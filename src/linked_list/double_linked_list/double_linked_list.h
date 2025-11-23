
typedef struct tagNode{
    int Data;
    struct tagNode*Next;
    struct tagNode*Prev;
}Node;

typedef struct tagDoubleLinkedList{
    Node*Head;
    Node*Tail;
}DLL;

DLL*initList();
Node*createNode(int Data);
void insertNode(DLL* List, int Data);
int removeNode(DLL* List, int Data);
int isEmptyList(DLL* List);
int getNode(DLL* List, int Data);
void freeList(DLL*List);
//삽입, 삭제, 접근(조회) -basic method()