#include<stdio.h>
#include<stdlib.h>

char **summaryRanges(int *nums, int numsSize, int *returnSize){
    char **res = (char **)malloc(sizeof(char *)*20);
    *returnSize = 0;
    if(numsSize == 0) return res;
    int l = 0;
    int i;
    for(i=1; i<=numsSize; ++i){
        if(i == numsSize || nums[i] != nums[i-1]+1){
            char *tmp = (char *)malloc(sizeof(char)*30);
            if(l == i-1){
                sprintf(tmp, "%d", nums[l]);
            }
            else{
                sprintf(tmp, "%d->%d", nums[l], nums[i-1]);
            }
            res[(*returnSize)++] = tmp;
            l = i;
        }
    }
    return res;
}

int main(){
    int input1[] = {-1, 0, 1, 2, 3, 4, 5};
    int returnSize;
    char **ans1 = summaryRanges(input1, 7, &returnSize);
    for(int i=0; i<returnSize; ++i){
        printf("%s\n", ans1[i]);
    }
    printf("\n");

    int input2[] = {0, 1, 2, 4, 5, 7};
    char **ans2 = summaryRanges(input2, 6, &returnSize);
    for(int i=0; i<returnSize; ++i){
        printf("%s\n", ans2[i]);
    }
    printf("\n");
    
    int input3[] = {0, 2, 3, 4, 6, 8, 9};
    char **ans3 = summaryRanges(input3, 7, &returnSize);
    for(int i=0; i<returnSize; ++i){
        printf("%s\n", ans3[i]);
    }
    printf("\n");
    
    return 0;
}
