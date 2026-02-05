#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#include "queue.h"

#define Dummy 0

int main() {

    Queue* QueueController = initQueue();

    removeNode(QueueController);

    for(int i=0;i<10;i++){
        insertNode(QueueController, i + 1);
    }

    printQueue(QueueController);
    printf("removed : %d\n", removeNode(QueueController));
    printQueue(QueueController);


    return 0;
    
}

Queue* initQueue() {
    Queue* QueueController = (Queue*)malloc(sizeof(Queue));

    Node* Head = createNode(Dummy);
    Node* Tail = createNode(Dummy);

    QueueController->Head = Head;
    QueueController->Tail = Tail;

    QueueController->Head->Next = QueueController->Tail;
    QueueController->Tail->Prev = QueueController->Head;

    return QueueController;
}

Node* createNode(int Data) {
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = Data;
    NewNode-> Next = NULL;
    NewNode-> Prev = NULL;

    return NewNode;
}

void insertNode(Queue* QueueController, int Data) {
    Node* NewNode = createNode(Data);
    

    NewNode->Next = QueueController->Head->Next;
    NewNode->Prev = QueueController->Head;

    QueueController->Head->Next->Prev = NewNode;
    QueueController->Head->Next = NewNode;

    
}

void printQueue(Queue* QueueController) {
    Node* Current = QueueController->Head->Next;

    while(Current != QueueController->Tail){
        printf("%d ", Current->Data);
        Current = Current->Next;
    }
    printf("\n");
}

int removeNode(Queue* QueueController) {
    if(isEmpty(QueueController)) {
        return printf("EmptyQueueException\n");
    }

    Node* removedNode = QueueController->Tail->Prev;
    removedNode->Prev->Next = QueueController->Tail;

    int removed = removedNode->Data;
    
    free(removedNode);

    return removed;
}

int isEmpty(Queue* QueueController) {
    if(QueueController->Head->Next == QueueController->Tail) {
        return 1;
    }
    else return 0;
}