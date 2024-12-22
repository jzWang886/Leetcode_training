#include<stdio.h>
#include<stdlib.h>

int cmp(const void *ptr1, const void *ptr2){
    int *iptr1 = *(int **)ptr1;
    int *iptr2 = *(int **)ptr2;

    size_t i = 0;
    while(i != 2 && iptr1[i] == iptr2[i]) ++i;

    return i == 2 ? 0 : (iptr2[i] < iptr1[i]) - (iptr1[i] < iptr2[i]);
}

int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes){
    qsort(intervals, intervalsSize, sizeof(* intervals), cmp);
    size_t cur = 0;
    for(int i=1; i<intervalsSize; ++i){
        if(intervals[cur][0] != intervals[i][0]){
            if(intervals[cur][1] >= intervals[i][0]){
                if(intervals[cur][1] < intervals[i][1]){
                    intervals[cur][1] = intervals[i][1];
                }
                continue;
            }
            ++cur;
            intervals[cur][0] = intervals[i][0];
            intervals[cur][1] = intervals[i][1];
        }
        else{
            intervals[cur][1] = intervals[i][1];
        }
    }
    *returnSize = ++cur;
    (*returnColumnSizes) = (int *)malloc(sizeof(int)*(*returnSize));
    for(int i=0; i<*returnSize; ++i){
        (*returnColumnSizes)[i] = 2;
    }
    return intervals;
}

int main(){
    int n;
    scanf("%d", &n);
    int **input = (int **)malloc(sizeof(int *)*n);
    for(int i=0; i<n; ++i){
        input[i] = (int *)malloc(sizeof(int)*2);
        scanf("%d%d", input[i], input[i]+1);
    }
    for(int i=0; i<n; ++i){
        printf("[%d, %d]\n", input[i][0], input[i][1]);
    }
    int intervalsColSize = 2, returnSize;
    int *returnColumnSizes;
    input = merge(input, n, &intervalsColSize, &returnSize, &returnColumnSizes);

    for(int i=0; i<returnSize; ++i){
        printf("[%d, %d]\n", input[i][0], input[i][1]);
    }
    return 0;
}
