#include<stdio.h>
#include<stdlib.h>
#include "double_linked_list.h"
#include<assert.h>

#define Exception -1
#define Dummy 0

void unitTest();
void printList(DLL*List);

DLL*initList();
Node*createNode(int Data);
void insertNode(DLL*List, int Data);
int removeNode(DLL*List, int Data);
int getNode(DLL*List, int Data);
void freeList(DLL*List);

int main(){

    unitTest();
    
    return 0;
}

DLL* initList(){
    DLL*NewList = (DLL*)malloc(sizeof(DLL));

    NewList->Head = createNode(Dummy);
    NewList->Tail = createNode(Dummy);

    NewList->Head->Next = NewList->Tail;
    NewList->Tail->Prev = NewList->Head;

    return NewList;
}

Node*createNode(int Data){
    Node*NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = Data;
    NewNode->Next = NULL;
    NewNode->Prev = NULL;

    return NewNode;
}

void insertNode(DLL*List, int Data){

    Node*NewNode = createNode(Data);
    
    Node*Last = List->Tail->Prev;

    Last->Next = NewNode;
    NewNode->Prev = Last;

    List->Tail->Prev = NewNode;
    NewNode->Next = List->Tail;
}

int removeNode(DLL*List, int Data){
    Node*Current = List->Head->Next;
    int Index=0;

    
    if(isEmptyList(List)){
        printf("EmptyListException\n");
        return Exception;
    }

   
    while(Current != NULL){
        if(Current->Data == Data){
            Current->Prev->Next = Current->Next; //Prev's Next is Current->Next
            Current->Next->Prev = Current->Prev; //Next's Prev is Current->Prev

            Current->Next = NULL;
            Current->Prev = NULL;
            free(Current);

            return Index;
        }

        Current = Current->Next;       
        Index++;
    }

    printf("NoSuchData\n");
    return Exception;
}

int getNode(DLL* List, int Data){
    Node*Current = List->Head->Next;
    int Index = 0;

    if(isEmptyList(List)){
        printf("EmptyListExcption\n");
        return Exception;
    }

    while(Current != NULL){

        if(Current->Data == Data){
            return Index;
        }

        Index++;
        Current = Current->Next;
    }

    printf("NoSuchException\n");
    return Exception;
}

int isEmptyList(DLL*List)
{
    if(List->Head->Next == List->Tail) return 1;
    else return 0;
}

void freeList(DLL*List){
    Node*Trash = NULL;

    Node*Current = List->Head;

    while(Current != NULL){
        Trash = Current;
        Current = Current->Next;

        free(Trash);
        Trash = NULL;
    }

    List->Head = NULL;
    List->Tail = NULL;
}

void unitTest(){

    DLL*List = initList();
    if(List == NULL){
        printf("mallocException\n");
        return;
    }

//initList test

    for(int i=1;i<=5; i++){
        insertNode(List, i);
    }
    
    printList(List);

//createNode(), insertNode() test
    int remove;

    remove = removeNode(List, 1);
    if(remove != Exception)
        printf("List[%d] : %d deleted\n", remove, 1);

    remove = removeNode(List, 5);
    if(remove != Exception)
        printf("List[%d] : %d deleted\n", remove, 5);

    printList(List);

//removeNode() [firstNode, LastNode] test

    int get;
    get = getNode(List, 4);
    if(Exception != get)
        printf("List[%d] : %d \n", get, 4);
    
    get = getNode(List, 5);

    if(Exception != get)
        printf("List[%d] : %d \n", get, 5);

    freeList(List);
    printList(List);

    free(List);
    List = NULL;
}

void printList(DLL*List){

    if(List->Head == NULL){
        printf("EmptyListException\n");
        return;
    }

    Node*Current = List->Head->Next;

    printf("printList\n\n");

    while(Current->Data != Dummy && Current != NULL){
        printf(" %d", Current->Data);
        Current = Current->Next;
    }
    printf("\n\n");
}