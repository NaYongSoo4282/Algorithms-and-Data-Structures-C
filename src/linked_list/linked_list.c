#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"



int main(){
    
    LinkedList * List = initList();
    
    return 0;
}

LinkedList* initList(){

    LinkedList* NewList = (LinkedList*)malloc(sizeof(LinkedList));

    NewList->Head = NULL;

    return NewList;
}

Node* createNode(int Data){{

    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = Data;
    NewNode->Next = NULL;

    return NewNode;
}