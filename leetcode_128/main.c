#include<stdio.h>
#include<stdlib.h>
#include"../uthash.h"

typedef struct node{
    int key;
    UT_hash_handle hh;
} node; 

int longestConsecutive(int *nums, int numsSize){
    node *hash = NULL, *s;
    for(int i=0; i<numsSize; ++i){
        HASH_FIND_INT(hash, &nums[i], s);
        if(s == NULL){
            s = (node *)malloc(sizeof(node));
            s->key = nums[i];
            HASH_ADD_INT(hash, key, s);
        }
    }
    int longest = 0;
    for(int i=0; i<numsSize; ++i){
        int tmp = nums[i]-1;
        HASH_FIND_INT(hash, &tmp, s);
        if(s == NULL){
            int current_long = 0;
            tmp = nums[i];
            do{
                ++current_long;
                ++tmp;
                HASH_FIND_INT(hash, &tmp, s);
            }while(s != NULL);
            if(current_long > longest){
                longest = current_long;
            }
        }
    }
    return longest;
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
