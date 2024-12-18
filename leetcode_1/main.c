#include<stdio.h>
#include<stdlib.h>

//Using UT_hash libery.

#define TABLE_SIZE 10000

typedef struct element{
    struct bucket *head; 
    struct bucket *tail;
} element;

typedef struct bucket{
    int key;
    struct bucket *next;   
} bucket;

int *twoSum(int *nums, int numSize, int target, int *returnSize){
    element *hash_Table = (element *)malloc(sizeof(element)*TABLE_SIZE);
    for(int i=0; i<TABLE_SIZE; ++i){
        hash_Table[i].head = NULL;
        hash_Table[i].tail = NULL;
    }
    
     
}

int main(){
    
    return 0;
}
