#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *simplifyPath(char *path){
    int p_len = strlen(path);
    char *res = (char *)malloc(sizeof(char)*(p_len+1));

    int cursor = 1, top = 0;
    res[top] = '/';
    
    char *tmp = (char *)malloc(sizeof(char)*(p_len));
    int tmp_cursor;
    while(cursor < p_len){
        tmp_cursor = 0;
        while(cursor < p_len && path[cursor] != '/'){
            tmp[tmp_cursor++] = path[cursor++];
        }
        tmp[tmp_cursor] = '\0';
        if(tmp_cursor == 0 || strcmp(tmp, ".") == 0){
            ++cursor;
            continue;
        }
        else{
            if(strcmp(tmp, "..") == 0){
                while(top > 0 && res[top] != '/'){
                    --top;
                }
                if(top > 0) --top; //remove '/'.
            }
            else{
                if(top > 0) res[++top] = '/';
                for(int i=0; i<tmp_cursor; ++i){
                    res[++top] = tmp[i];
                }
            }
            ++cursor;
        }
    }
    res[++top] = '\0';

    return res;
}

int main(){
    char input[3001] = {'\0'};
    char buffer[3001] = {'\0'};
    int n;
    printf("The depth of absolute path:\n");
    scanf("%d", &n);
    
    printf("Type %d dir/file name(s):\n", n);
    for(int i=0; i<n; ++i){
        strcat(input, "/");
        scanf("%s", buffer);
        strcat(input, buffer);
    }
    printf("Input string: %s\n", input);

    char *ans = simplifyPath(input);
    printf("Output string: %s\n", ans);

    return 0;
}
