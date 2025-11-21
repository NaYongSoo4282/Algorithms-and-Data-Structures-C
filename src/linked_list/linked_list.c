#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include "linked_list.h"

#define DummyData 0
#define Exception -1
#define Insert 'A'
#define Delete 'D'
#define Get 'G'

void printList(LinkedList*List);
//for Check

void runUnitTests() {
    printf("\n=== [Unit Test] Start Checks... ===\n");
    
    // 1. 초기화 테스트
    LinkedList* list = initList();
    assert(list != NULL);
    assert(list->Head != NULL);
    assert(list->Head->Next == NULL); // 초기엔 비어있어야 함
    printf("1. Init Test Passed\n");

    // 2. 빈 리스트 예외 처리 테스트 (Edge Case)
    // 아무것도 없는데 지우려고 할 때 프로그램이 뻗지 않고 -1을 뱉는지 확인
    int result = removeNode(list, 999);
    assert(result == Exception); 
    
    result = getNode(list, 999);
    assert(result == Exception);
    printf("2. Empty List Handling Passed\n");

    // 3. 정상 삽입 테스트 (Happy Path)
    insertNode(list, 10); // List: 10
    insertNode(list, 20); // List: 10 -> 20
    insertNode(list, 30); // List: 10 -> 20 -> 30
    
    // 제대로 들어갔는지 인덱스로 확인 (형님 코드 로직상 인덱스 반환)
    assert(getNode(list, 10) == 0); 
    assert(getNode(list, 20) == 1);
    assert(getNode(list, 30) == 2);
    printf("3. Insert & Search Passed\n");

    // 4. 중간 노드 삭제 테스트 (Normal Delete)
    // 20을 지우면, 10 -> 30 이 되어야 함.
    removeNode(list, 20);
    assert(getNode(list, 20) == Exception); // 20은 없어야 함
    assert(getNode(list, 30) == 1);         // 30이 인덱스 1번으로 당겨져야 함 ★중요
    printf("4. Middle Delete Passed\n");

    // 5. 첫 번째 노드(Head 다음) 삭제 테스트 (Edge Case)
    // 현재: 10 -> 30. 여기서 10을 지움. 결과: 30만 남아야 함.
    // 이 테스트가 중요한 이유: Dummy Node 로직이 꼬이면 여기서 자주 터짐.
    removeNode(list, 10);
    assert(getNode(list, 10) == Exception);
    assert(getNode(list, 30) == 0); // 30이 0번(첫 번째)이 되어야 함
    printf("5. First Node Delete Passed\n");

    // 6. 없는 데이터 삭제 시도 (Edge Case)
    // 현재: 30. 없는 50을 지우려 함.
    assert(removeNode(list, 50) == Exception);
    // 기존 데이터는 멀쩡해야 함
    assert(getNode(list, 30) == 0);
    printf("6. Non-existing Delete Passed\n");

    // 7. 메모리 해제 테스트
    freeList(list);
    assert(list->Head == NULL); // Head가 안전하게 NULL 처리 되었는지
    free(list);
    
    printf("=== [Unit Test] All Systems Go! (Perfect) ===\n\n");
}

int main(){

    runUnitTests();
    /*
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
            scanf("%d", &Data);
            e = removeNode(List, Data);

            if(e != Exception){
                printf("Delete %d\n", Data);
            }
         }

         else if(Op == Get){
            scanf("%d", &Data);
            G = getNode(List, Data);

            if(G != Exception){
                printf("List[%d] : %d\n", G, Data);
            }
         }
    }


    freeList(List);
    free(List); 
    List = NULL;

    printList(List); //check
*/
    return 0;

}

LinkedList* initList(){

    LinkedList* NewList = (LinkedList*)malloc(sizeof(LinkedList));

    NewList->Head = createNode(DummyData); 
    //더미 노드를 사용 : 삽입/삭제 시 항상 동일한 로직 적용

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
    
    Node*Current = List->Head;

    while(Current->Next != NULL){ 
        Current = Current->Next;        
    }

    Current->Next = NewNode;
}

int removeNode(LinkedList*List, int Data){ 

    Node* Current = List->Head->Next; 
    Node*Prev = List->Head;

    if(Current == NULL){
        
        printf("EmptyListException\n");
        
        return Exception;
    }

    while(Current != NULL){
        if(Current->Data == Data){

            Prev->Next = Current->Next;
            Current->Next = NULL; // 가독성, 방어적
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

   if(List == NULL){
    printf("Cleaned\n");
   }

    Node*Cleaner = List->Head;
    Node*NextNode = NULL;

    while(Cleaner != NULL){
        NextNode = Cleaner->Next;
        freeNode(Cleaner);        
        Cleaner = NextNode;
    }

    List->Head = NULL;
}

void printList(LinkedList*List){

    if(List == NULL){
        printf("NoListException\n");

        return;
    }
    
    Node*Current = List->Head->Next;

    while(Current != NULL){
        printf(" %d", Current->Data);
        Current = Current->Next;
    }
    printf("\n\n");
}