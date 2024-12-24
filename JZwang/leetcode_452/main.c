#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b){
    int *ptr1 = *(int **)a;
    int *ptr2 = *(int **)b;

    size_t i = 0;
    while(i < 2 && ptr1[i] == ptr2[i]) ++i;

    return i == 2 ? 0 :((ptr1[i]>ptr2[i])-(ptr1[i]<ptr2[i]));
}

int findMinArrowShots(int **points, int pointsSize, int *pointsColSize){
    printf("Enter function successfully.\n");
    qsort(points, pointsSize, sizeof(* points), cmp);
    
    int ArrowNum = 0, i = 0, curArrowPos;
    while(i < pointsSize){
        curArrowPos = points[i++][1];
        ++ArrowNum;
        while(i < pointsSize && points[i][0] <= curArrowPos){
            if(points[i][1] < curArrowPos) curArrowPos = points[i][1];
            ++i;
        }
    }

    return ArrowNum;
}

int main(){
    int n;
    printf("How many input(s):\n");
    scanf("%d", &n);
    int **points = (int **)malloc(sizeof(int *)*n);
    printf("Type %d input:\n", n);
    for(int i=0; i<n; ++i){
        points[i] = (int *)malloc(sizeof(int)*2);
        scanf("%d%d", points[i], points[i]+1);
    }
    printf("Your inputs:\n");
    for(int i=0; i<n; ++i){
        printf("[%d %d]\n", points[i][0], points[i][1]);
    }
    int pointsColSize = 2;
    int ans = findMinArrowShots(points, n, &pointsColSize);
    printf("The min number of used arrow(s): %d\n", ans);
    return 0;
}
