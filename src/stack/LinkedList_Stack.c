#include<stdio.h>
#include<stdlib.h>
#include "linkedlist_stack.h"

Stack* initStack();
void push(int Data, Stack*S);
int pop(Stack*S);


int main(){

    Stack *S = initStack();

    push(10, S);
    push(20, S);
    push(30, S);
    
    Node*current = NULL;
        current = S->Storage->Head->Next;

    for(int i=0;i<3;i++){
        printf("%d ", current->Data);
        current = current->Next;
    }

    printf("POP : %d\n", pop(S));
    
    current = S->Storage->Head->Next;

    for(int i=0;i<3;i++){
        if(current->Data == 0)break;
        printf("%d ", current->Data);
        current = current->Next;
    }
    return 0;
}

Stack* initStack(){
     
    Stack* S = (Stack*)malloc(sizeof(Stack));

    S->Storage = initList();

    return S;
}

void push(int Data, Stack*S){
    insertNode(S->Storage, Data);
}

int pop(Stack*S){
    if(S==NULL || isEmptyList(S->Storage) == 1){
        printf("EmptyListException\n");
        return -9999;
    }

    Node*Last = S->Storage->Tail->Prev;
    int removeData = Last->Data;
    Node*Prev = Last->Prev;
    Prev->Next = Last->Next;
    Last->Next->Prev = Prev;

    free(Last);

    return removeData;
}

