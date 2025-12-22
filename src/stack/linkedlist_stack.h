#include "../linked_list/double_linked_list/double_linked_list.h"

typedef struct tagStack{
    DLL * Storage;
}Stack;

Stack* initStack();
void push(int Data, Stack*S);
int pop(Stack*S);