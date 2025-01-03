#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int stoi_(char *s, int *len){
    int num = 0;
    *len = 0;
    while(isdigit(*s)){
        num = 10*num + (*s-'0');
        ++s;
        ++(*len);
    }
    return num;
}

int calculate(char *s){
    int s_len = strlen(s), i = -1, sign = 1, bracket_sign = 1;
    int signsStack[1000] = {0}, Stack_Top = -1;
    int num = 0, stoi_len;
    signsStack[++Stack_Top] = 1;
    while(++i<s_len){
        switch (s[i]) {
            case ' ':
                continue;
            case '+':
                sign = 1;
                break;
            case '-':
                sign = -1;
                break;
            case '(':
                bracket_sign *= sign;
                signsStack[++Stck_Top] = bracket_sign;
                sign = 1;
                break;
            case ')':
                bracket_sign = signsStack[--Stack_Top];
                break;
            default:
                num += (bracket_sign*sign*(stoi_(s+i, &stoi_len)));
                i += stoi_len-1;
        }
    }
    return num;
}

int main(){
    //Test of "stoi_" function.
    /*
    char *s = (char *)malloc(sizeof(char)*300);
    printf("Test of stoi_ function. Type a number here:\n");
    scanf("%s", s);
    int len;
    printf("The result: %d\n", stoi_(s, &len));
    */

    char *input = (char *)malloc(sizeof(char)*3000);
    printf("Enter input:\n");
    scanf("%s", input);
    printf("Repeat input:\n");
    printf("%s\n", input);

    int ans = calculate(input);
    printf("Answer is %d\n", ans);
    
    return 0;
}
