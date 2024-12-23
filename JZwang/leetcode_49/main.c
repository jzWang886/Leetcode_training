#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isAnagrams(char *s, char *t){
    int s_Table[26] = {0};
    for(int i=0; s[i]; ++i){
        ++s_Table[s[i]-'a'];
    }
    //printf("s_Table is builded.\n");

    for(int i=0; t[i]; ++i){
        if(s_Table[t[i]-'a'] <= 0) return false;
        else --s_Table[t[i]-'a'];
        //printf("t[i] is %c\n", t[i]);
    }
    //printf("string has been checked.\n");

    return true;
}

char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumSizes){
        
}

int main(){
    /*
    //test isAnagrams function:
    char *s = "cat", *t = "tat";
    bool ans = isAnagrams(s, t);
    printf("inAnagrams function test ans is :%s\n", ans ? "True":"False");
    */

    
    return 0;
}
