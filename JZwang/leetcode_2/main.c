#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

typedef struct List{
    struct ListNode *head;
    struct ListNode *tail;   
} List;

struct ListNode* CreatNode(int val){
    struct ListNode* NewNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    NewNode->next = NULL;
    NewNode->val = val;
    return NewNode;
}

List * CreatList(){
    List *NewList = (List *)malloc(sizeof(List));
    NewList->head = NULL;
    NewList->tail = NULL;
    return NewList;
}

void AddNode(List *ref_List, int val){
    if(ref_List->head == NULL){
        ref_List->head = CreatNode(val);
        ref_List->tail = ref_List->head;
    }
    else{
        ref_List->tail->next = CreatNode(val);
        ref_List->tail = ref_List->tail->next;
    }
}

void AddRemain(List *ref_List, struct ListNode *ref_head, int carry){
    while(ref_head != NULL){
        if(carry == 0){
            AddNode(ref_List, ref_head->val);
        }
        else{
            int tmp = (ref_head->val)+carry;
            if(tmp > 9){
                tmp %= 10;
            }
            else{
                carry = 0;
            }
            AddNode(ref_List, tmp);
        }
        ref_head = ref_head->next;
    }
    if(carry == 1){
        AddNode(ref_List, 1);
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode *l2){
    List *Ans = CreatList();
    int carry = 0, tmp;
    while(l1 != NULL && l2 != NULL){
        if(carry == 0){
            tmp = (l1->val)+(l2->val);
        }
        else{
            tmp = (l1->val)+(l2->val)+carry;
            carry = 0;
        }
        if(tmp > 9){
            carry = 1;
            tmp %= 10;
        }
        AddNode(Ans, tmp);
        l1 = l1->next;
        l2 = l2->next;
    }
    
    if(l1 !=  NULL){
        AddRemain(Ans, l1, carry);
    }
    else if(l2 != NULL){
        AddRemain(Ans, l2, carry);
    }
    else{
        if(carry == 1){
            AddNode(Ans, 1);
        }
        return Ans->head;
    }
    return Ans->head;
}

List *CreatInputList(int len){
    List *NewList = CreatList();
    int tmp;
    for(int i=0; i<len; ++i){
        scanf("%d", &tmp);
        AddNode(NewList, tmp);
    }
    return NewList;
}

void GetInputList(List *InputList){
    struct ListNode *cursor_Node = InputList->head;
    while(cursor_Node != NULL){
        printf("%d, ", cursor_Node->val);
        cursor_Node = cursor_Node->next;
    }
    printf("\n");
}
int main(){
    int n1, n2;
    scanf("%d%d", &n1, &n2);
    List *l1 = CreatInputList(n1);
    List *l2 = CreatInputList(n2);
    
    printf("l1: ");
    GetInputList(l1);

    printf("l2: ");
    GetInputList(l2);

    struct ListNode *Answer = addTwoNumbers(l1->head, l2->head);

    printf("Answer: ");
    while(Answer != NULL){
        printf("%d, ", Answer->val);
        Answer = Answer->next;
    }
    printf("\n");

    return 0;
}
