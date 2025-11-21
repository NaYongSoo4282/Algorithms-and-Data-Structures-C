typedef struct tagNode{
    int Data;
    struct tagNode*Next;
}Node;

typedef struct tagLinkedList{
    Node*Head;
}LinkedList;

LinkedList* initList();//연결리스트 초기화
Node* createNode(int Data); //노드 생성
void insertNode(LinkedList*Head, int Data); //노드 삽입 (Data는 createNode로 처리)
int removeNode(LinkedList*Head, int Data); //노드 삭제 (Data와 일치하는 노드 삭제)
int getNode(LinkedList*Head, int Data); //노드 조회
void freeNode(Node* node);
void freeList(LinkedList *List); // 할당 해제

void NewFunction(LinkedList *List);
