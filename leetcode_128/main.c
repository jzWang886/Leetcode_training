// Hashmap method using double hashing of opening address.
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int longestConsecutive(int *nums, int numsSize){
    if(numsSize == 0) return 0;

    int tableSize = 4*numsSize;
    int *hash_Table = (int *)malloc(sizeof(int)*tableSize);
    for(int i=0; i<tableSize; ++i){
        hash_Table[i] = INT_MAX;
    }
    
    int *uniqNums = (int *)malloc(sizeof(int)*numsSize);
    int uniqN = 0;

    int hash1, hash2;
    for(int i=0; i<numsSize; ++i){
        if(nums[i] < 0){
            hash1 = (nums[i]*-1) % tableSize; //First Hash.
            hash2 = 1 + ((nums[i]*-1) % (tableSize-1));
        }
        else{
            hash1 = nums[i] % tableSize;
            hash2 = 1 + (nums[i] % (tableSize-1));
        }
        int step = 0, hash;
        do{
            hash = (hash1 + hash2*step++) % tableSize; 
        }while(hash_Table[hash] != INT_MAX && hash_Table[hash] != nums[i]);
        if(hash_Table[hash] == INT_MAX) uniqNums[uniqN++] = nums[i];
        hash_Table[hash] = nums[i];
    }

    int longest = 0;
    for(int i=0; i<uniqN; ++i){
        if(uniqNums[i]-1 < 0){
            hash1 = ((uniqNums[i]-1)*-1) % tableSize;
            hash2 = 1 + (((uniqNums[i]-1)*-1) % (tableSize-1));
        }
        else{
            hash1 = (uniqNums[i]-1) % tableSize;
            hash2 = 1 + ((uniqNums[i]-1) % (tableSize-1));
        }
        int step = 0, hash;
        do{
            hash = (hash1 + hash2*step++) % tableSize;
        }while(hash_Table[hash] != INT_MAX && hash_Table[hash] != uniqNums[i]-1);
        if(hash_Table[hash] == INT_MAX){
            int len = 1;
            for(int j = uniqNums[i]+1; 1; ++j, ++len){
                if(j < 0){
                    hash1 = (j*-1) % tableSize;
                    hash2 = 1 + ((j*-1) % (tableSize-1));
                }
                else{
                    hash1 = j % tableSize;
                    hash2 = 1 + (j % (tableSize-1));
                }
                step = 0;
                do{
                    hash = (hash1 + hash2*step++) % tableSize;
                }while(hash_Table[hash] != INT_MAX && hash_Table[hash] != j);
                if(hash_Table[hash] == INT_MAX) break;
            }
            if(len > longest) longest = len;
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

    int input3[1] = {0};
    int ans3 = longestConsecutive(input3, 1);
    printf("Answer is %d\n", ans3);
    return 0;
}
