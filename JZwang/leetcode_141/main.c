#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

typedef struct node{
    struct node* next;
} node;

bool hasCycle(node *head){
    if(head == NULL) return false;
    node *One_Step = head, *Two_Step = head;
    do{
        if(One_Step->next != NULL){
            One_Step = One_Step->next;
        }
        else{
            return false;
        }

        if(Two_Step->next != NULL && Two_Step->next->next != NULL){
            Two_Step = Two_Step->next->next;
        }
        else{
            return false;
        }
    }while(One_Step != Two_Step);

    return true;
}

void Add_Node(node **head, node **tail){
    node *NewNode = (node *)malloc(sizeof(node));
    NewNode->next = NULL;

    if((*head) == NULL) {
        (*head) = NewNode;
        (*tail) = NewNode;
    }
    else{
        (*tail)->next = NewNode;
        (*tail) = (*tail)->next;
    }

    return;
}

int main(){
    srand(time(NULL));
    int r = rand()%100;

    if(r%2){
        printf("The linked-list has cycle.\n");
    }
    else{
        printf("The linked-list has no cycle.\n");
    }

    node *head = NULL, *tail = NULL, *pos = NULL;
    for(int i=0; i<100; ++i){
        Add_Node(&head, &tail);
        if(i == r && r%2){
            pos = tail; 
        }
    }
    if(r%2 && pos != NULL){
        tail->next = pos;
    }

    bool ans = hasCycle(head);
    printf("The result of \'hasCycle\' function is %s\n", ans ? "True":"False");

    return 0;
}
