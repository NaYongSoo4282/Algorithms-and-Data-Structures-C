#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"

#define TrailerData 0
#define Exception -1
#define Insert 'A'
#define Delete 'D'
#define Get 'G'

void printList(LinkedList*List);
//for Check

int main(){
    
    LinkedList * List = initList();

    int N = 0, M = 0, e = 0, G = 0, Data = 0;
    char Op;

    scanf("%d", &N);

    for(int i = 0; i < N;i++){ //Spec : Insert = 'A', Delete = 'D', Get = 'G'
         scanf(" %c",&Op);

         if(Op == Insert){
            scanf("%d", &Data);
            insertNode(List, Data);
         }
         else if(Op == Delete){
            scanf("%d", Data);
            e = removeNode(List, Data);
            if(e != Exception){
                printf("Delete %d\n", Data);
            }
         }
         else if(Op == Get){
            scanf("%d", &Data);
            G = getNode(List, Data);
         }
    }


    return 0;
}

LinkedList* initList(){

    LinkedList* NewList = (LinkedList*)malloc(sizeof(LinkedList));

    NewList->Head = createNode(TrailerData); // init Trailer Node

    return NewList;
}

Node* createNode(int Data){

    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = Data;
    NewNode->Next = NULL;

    return NewNode;
}

void insertNode(LinkedList*List, int Data){

    Node*NewNode = createNode(Data);
    
    Node*Current = List;//get Trailer

    while(Current->Next != NULL){ //O(N)
        Current = Current->Next;        
    }

    Current->Next = NewNode; // insert
}

int removeNode(LinkedList*List, int Data){ 

    Node* Current = List->Head->Next; //get 1st Node
    Node*Prev=NULL;

    if(Current == NULL){
        
        printf("EmptyListException\n");
        
        return Exception;
    }//Throw Exception

    while(Current != NULL){
        if(Current->Data == Data){
            Prev->Next = Current->Next;
            freeNode(Current);
            return Data;
        }

        Prev = Current;
        Current = Current->Next;
    }

    printf("NoSuchDataException\n");
    return Exception;
}

int getNode(LinkedList*List, int Data){

    Node*Current = List->Head->Next;
    int Index = 0;

    if(Current == NULL){
        printf("EmptyListException\n");
        return Exception;
    }

    while(Current != NULL){
        if(Current->Data == Data){
            printf("List[%d] : %d\n", Index, Current->Data);
            return Index;
        }

        Current = Current->Next;
        Index++;
    }

    printf("NoSuchDataException\n");
    return Exception;
}

void freeNode(Node* node){
    free(node);
}

void freeList(LinkedList* List){
    free(List);
}

void printList(LinkedList*List){
    Node*Current = List->Head->Next;

    while(Current != NULL){
        printf(" %d", Current->Data);
    }
    printf("\n");
}