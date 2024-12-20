#include<stdio.h>
#include<stdlib.h>

int longestConsecutive(int *nums, int numsSize){
    int max_Num = 0, max_Len = 0;
    int *table = (int *)calloc(2000000001, sizeof(int));
    for(int i=0; i<numsSize; ++i){
        ++table[nums[i]+1000000000];
        if(nums[i]+1000000000 > max_Num) max_Num = nums[i]+1000000000;
    }
    
    int cursor = -1, current_Len = 0; 
    while(cursor++ < max_Num){
        if(table[cursor] == 1){
            ++current_Len;
            printf("cursor = %d, current_Len = %d\n", cursor, current_Len);
            continue;
        }
        else{
            if(current_Len > max_Len){
                max_Len = current_Len;
            }
            if(table[cursor] == 0) current_Len = 0;
            else current_Len = 1;
        }
    }
    if(current_Len > max_Len){
        max_Len = current_Len;
    }
    return max_Len; 
}

int main(){
    int input1[] = {100, 4, 200, 1, 3, 2};
    int ans1 = longestConsecutive(input1, 6);
    printf("Answer is %d\n", ans1);

    int input2[] = {0, 3, 7, 2 ,5, 8, 4, 6, 0, 1};
    int ans2 = longestConsecutive(input2, 10);
    printf("Answer is %d\n", ans2);
    
    return 0;
}
