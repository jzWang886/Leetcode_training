#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

bool isValid(char *s){
    int cursor = 0, top = -1, s_len = strlen(s);
    if(s_len%2 == 1) return false;
    char *stack = (char *)malloc(sizeof(char)*s_len);
    
    while(s[cursor]){
        if(s[cursor] == '(' || s[cursor] == '[' || s[cursor] == '{'){
            stack[++top] = s[cursor++];
        }
        else{
            if(top < 0 || (s[cursor]==')' && stack[top]!='(') || (s[cursor]==']' && stack[top]!='[') || (s[cursor]=='}' && stack[top]!='{')){
                return false;
            }
            --top;
            ++cursor;
        }
    }

    if(top == -1){
        return true;
    }
    return false;
}

int main(){
    int n;
    printf("The number of input char:\n");
    scanf("%d", &n);

    char *input = (char *)malloc(sizeof(char)*(n+1));
    printf("Type input:\n");
    scanf("%s", input);
    
    printf("Repeat input:\n");
    printf("[ %s ]\n", input);

    bool ans = isValid(input);
    printf("Answer is :%s\n", ans ? "true":"false");

    return 0;
}
