#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

typedef struct node {
    int Value;
    int Min_Value;
    struct node *next;
} node;

typedef struct Stack {
    struct node *top;
} MinStack;

MinStack *minStackCreate(){
    MinStack *NewMinStack = (MinStack *)malloc(sizeof(MinStack));
    NewMinStack->top = NULL;
    return NewMinStack;
}

void minStackPush(MinStack *obj, int val){
    node *NewNode = (node *)malloc(sizeof(node));
    NewNode->Value = val;
    if(obj->top == NULL){
        NewNode->Min_Value = val;
        NewNode->next = NULL;
    }
    else{
        NewNode->Min_Value = min(val, obj->top->Min_Value);
        NewNode->next = obj->top;
    }
    obj->top = NewNode;
    return;
}

void minStackPop(MinStack *obj){
    node *PopNode = obj->top;
    if(PopNode != NULL){
        obj->top = obj->top->next;
        PopNode->next = NULL;
        free(PopNode);
    }
    return;
}

int minStackTop(MinStack *obj){
    return obj->top->Value;
}

int minStackGetMin(MinStack *obj){
    return obj->top->Min_Value;
}

void minStackFree(MinStack *obj){
    node *FreeNode = obj->top;
    while(FreeNode != NULL){
        obj->top = obj->top->next;
        FreeNode->next = NULL;
        free(FreeNode);
        FreeNode = obj->top;
    }
    free(obj);
    return;
}

int main(){
    MinStack *obj = minStackCreate();
    if(obj == NULL) printf("Creating successfully.\n");
    minStackPush(obj, 2);
    minStackPush(obj, 4);

    node *cursor = obj->top;
    while(cursor!=NULL){
        printf("%d\n", cursor->Value);
        cursor = cursor->next;
    }
    return 0;
}
