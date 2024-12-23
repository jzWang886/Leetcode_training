#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"../uthash.h"

typedef struct node{
    int key;
    int index;
    UT_hash_handle hh;
} node;

bool containsNearbyDuplicate(int *nums, int numsSize, int k){
    node *table = NULL;
    
    node *s, *tmp; 
    for(int i=0; i<numsSize; ++i){
       HASH_FIND_INT(table, &nums[i], s);
       if(s == NULL){
           s = (node *)malloc(sizeof(node));
           s->key = nums[i];
           s->index = i;
           HASH_ADD_INT(table, key, s);
       }
       else{
           if((i-s->index) <= k){
               HASH_ITER(hh, table ,s , tmp){
                   HASH_DEL(table, s); free(s);
               }
               return true;
           }
           s->index = i;
       }
    }
    HASH_ITER(hh, table, s, tmp){
        HASH_DEL(table, s); free(s);
    }
    return false;
}

int main(){
    int nums1[] = {1, 2, 3, 1}, numsSize1 = 4;
    bool ans1 = containsNearbyDuplicate(nums1, numsSize1, 3);
    int nums2[] = {1, 0, 1, 1}, numsSize2 = 4;
    bool ans2 = containsNearbyDuplicate(nums2, numsSize2, 1);
    int nums3[] = {1, 2, 3, 1, 2, 3}, numsSize3 = 6;
    bool ans3 = containsNearbyDuplicate(nums3, numsSize3, 2);
    printf("Answer is %s\n", ans1 ? "true":"false");
    printf("Answer is %s\n", ans2 ? "true":"false");
    printf("Answer is %s\n", ans3 ? "true":"false");
    
    return 0;
}
