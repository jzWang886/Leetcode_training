#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool wordPattern(char *pattern, char *s){
    char *usedWords_Table[26] = {NULL};
    char *letter_Table[26] = {NULL};
    char *token = strtok(s, " ");
    int usedWords_count = 0, pattern_len = strlen(pattern), k = 0;

    while(token != NULL && k < pattern_len){
        printf("Token is %s\n", token);
        if(letter_Table[pattern[k]-'a'] == NULL){            
            printf("The content of usedWords_Table is: ");
            for(int i=0; i<usedWords_count; ++i){
               printf("usedWords_Table[%d] = %s", i, usedWords_Table[i]);
               if(strcmp(usedWords_Table[i], token) == 0){
                   return false;
               }
            }
            printf("\n");
            letter_Table[pattern[k++]-'a'] = token;
            usedWords_Table[usedWords_count++] = token;
        }
        else{
            if(strcmp(letter_Table[pattern[k]-'a'], token) != 0){
                return false;
            }
            else{
                ++k;
            }
        }        
        token = strtok(NULL, " ");
    }
    
    if(k != pattern_len || token != NULL){
        return false;
    }
    return true;
}

int main(){
    char *pattern = "aaaa";
    char s[] = "dog cat cat dog";
    
    bool ans = wordPattern(pattern, s);
    printf("Answer is %s\n", ans ? "true":"false");
    return 0;
}

