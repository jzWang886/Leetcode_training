#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int evalRPN(char **tokens, int tokensSize){
    printf("In evalRPN\n");
    int *operandsStack = (int *)malloc(sizeof(int)*tokensSize); 
    int top = -1;
    
    for(int i=0; i<tokensSize; ++i){
        if(!strcmp(tokens[i], "+")){
            operandsStack[top-1] += operandsStack[top];
            --top;
        }
        else if(!strcmp(tokens[i], "-")){
            operandsStack[top-1] -= operandsStack[top];
            --top;
        }
        else if(!strcmp(tokens[i], "*")){
            operandsStack[top-1] *= operandsStack[top];
            --top;
        }
        else if(!strcmp(tokens[i], "/")){
            operandsStack[top-1] /= operandsStack[top];
            --top;
        }
        else{
            sscanf(tokens[i], "%d", operandsStack+top+1);
            ++top;
        }
    }
    return operandsStack[top];
}

int main(){
    int n;
    printf("The number of expression element:\n");
    scanf("%d", &n);

    char **input = (char **)malloc(sizeof(char *)*n);
    printf("Type the element(s) of expression:\n");
    for(int i=0; i<n; ++i){
        input[i] = (char *)malloc(sizeof(char)*200);
        scanf("%s", input[i]);
    }

    printf("Repeat the input:\n");
    printf("[");
    for(int i=0; i<n; ++i){
        printf("\"%s\"", input[i]);
        if(i != n-1) printf(",");
    }
    printf("]\n");

    int ans = evalRPN(input, n);
    printf("%d\n", ans);
    return 0;
}
