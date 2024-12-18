#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

bool isAnagram(char *s, char *t){
    if(strlen(s) != strlen(t)){
        return false;
    }
    int s_Table[26] = {0};
    for(int i=0; s[i]; ++i){
        ++s_Table[s[i]-'a'];
    }
    for(int i=0; t[i]; ++i){
        if(s_Table[t[i]-'a'] <= 0) return false;
        else --s_Table[t[i]-'a'];
    }
    return true;
}

int main(){
   char *s = "anagram";
   char *t = "nagaram";
   bool ans = isAnagram(s, t);
   printf("Answer is %s\n", ans ? "true":"false");
   return 0;
}
