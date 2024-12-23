#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int **insert(int **intervals, int intervalsSize, int *intervalsColSize, int *newInterval, int newIntervalSize, int *returnSize, int **returnColumnSizes){
    int start = newInterval[0], end = newInterval[1], r = 0, k = 0;
    int **res = (int **)malloc(sizeof(int *)*(intervalsSize + 1));
    while(r < intervalsSize && intervals[r][1] < start){
        res[k++] = intervals[r++];
    }
    if((r < intervalsSize && intervals[r][0] > end) || r == intervalsSize){
        res[k++] = newInterval;
    }
    else{
        int l = r++;
        while(r < intervalsSize && intervals[r][0] <= end){
            ++r;
        }
        start = min(intervals[l][0], start);
        end = max(intervals[r-1][1], end);
        res[k] = (int *)malloc(sizeof(int *)*2);
        res[k][0] = start;
        res[k][1] = end;
        ++k;
    }

    while(r < intervalsSize){
        res[k++] = intervals[r++];
    }

    *returnSize = k;
    (*returnColumnSizes) = (int *)malloc(sizeof(int)*k);
    for(int i=0; i<k; ++i){
        (*returnColumnSizes)[i] = 2;
    }

    return res;
}

int main(){
    int n;
    printf("Number of interval(s):\n");
    scanf("%d", &n);
    int **input = (int **)malloc(sizeof(int *)*n);
    printf("Input:\n");
    for(int i=0; i<n; ++i){
        input[i] = (int *)malloc(sizeof(int)*2);
        scanf("%d%d", input[i], input[i]+1);
    }

    for(int i=0; i<n; ++i){
        printf("[%d %d]\n", input[i][0], input[i][1]);
    }

    int intervalsColSize = 2, returnSize, *returnColumnSizes;
    int *newInterval = (int *)malloc(sizeof(int)*2);
    printf("New interval:\n");
    scanf("%d%d", newInterval, newInterval+1);
    printf("[%d %d]\n", newInterval[0], newInterval[1]);
    int **output = insert(input, n, &intervalsColSize, newInterval, 2, &returnSize, &returnColumnSizes);

    printf("Output:\n");
    for(int i=0; i<returnSize; ++i){
        printf("[%d %d]\n", output[i][0], output[i][1]);
    }
    return 0;
}










































