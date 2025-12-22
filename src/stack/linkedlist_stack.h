#include "../linked_list/double_linked_list/double_linked_list.h"

typedef struct tagStack{
    DLL * Storage;
}Stack;

Stack* initStack(Stack*S);
void push(Node*NewNode, Stack*S);
Node* pop(Stack*S);