typedef struct tagNode{
    int Data;
    struct tagNode* Next;
    struct tagNode* Prev;
}Node;

typedef struct tagQueue{
    Node* Head;
    Node* Tail;
}Queue;

Node* createNode(int Data);
Queue* initQueue();
void insertNode(Queue* QueueController, int Data);
int removeNode(Queue* QueueController);
int isEmpty(Queue* QueueController);
void printQueue(Queue* QueueController);