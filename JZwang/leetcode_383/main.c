#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define len1 10
#define len2 12
bool canConstruct(char *ransomNote, char *magazine){
    int m_table['z'+1] = {0};

    for(int i=0; magazine[i]; ++i){
        ++m_table[magazine[i]];
    } 
    for(int i=0; ransomNote[i]; ++i){
        if(m_table[ransomNote[i]]) --m_table[ransomNote[i]];
        else return false; 
    }
    return true;
}
int main(){
    char ransomNote[len1] = "a"; 
    char magazine[len2] = "b"; 
    bool ans = canConstruct(ransomNote, magazine);
    printf("Answer is %s\n", ans ? "true" : "false");
    return 0;
}










































































































