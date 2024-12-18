#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isIsomorphic(char *s, char *t){
    int s_table[129] = {0}, t_table[129] = {0};
    for(int i=0; s[i]; ++i){ 
        if(s_table[s[i]+1] == 0) s_table[s[i]+1] = t[i]+1;
        else{
            if(s_table[s[i]+1] == t[i]+1) continue;
            else return false;
        }
    }
    for(int i=0; t[i]; ++i){
        if(t_table[t[i]+1] == 0) t_table[t[i]+1] = s[i]+1;
        else{
            if(t_table[t[i]+1] == s[i]+1) continue;
            else return false;
        }
    }
    return true;
}

int main(){
    char *s = "foo";
    char *t = "bar";
    
    bool ans = isIsomorphic(s, t);
    printf("Answer is %s\n", ans ? "true" : "false");
    return 0;
}
