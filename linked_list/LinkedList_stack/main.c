/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.01
  writer - Hugo MG Sung.
*/

#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct Node Node;
typedef struct Stack Stack;

struct Node {
    Item item;
    Node* next;
};

struct Stack {
    Node* top;
    Node* head;
};

Node* CreateNode(Item item);
Stack* CreateStack();
void push_s(Stack* stack, Item item);
Item peek_s(const Stack* stack);
Item pop_s(Stack* stack);
void Release_s(Stack* stack);
void print_s(const Stack* stack);

// 메인함수
int main() 
{
    Stack* stack = CreateStack();

    push_s(stack, 10); print_s(stack);
    push_s(stack, 20); print_s(stack);
    push_s(stack, 30); print_s(stack);

    pop_s(stack); print_s(stack);
    pop_s(stack); print_s(stack);
    pop_s(stack); print_s(stack);

    Release_s(stack);
}

Node* CreateNode(Item item) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->item = item;
    node->next = NULL;

    return node;
}

Stack* CreateStack()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));

    stack->top = NULL;
    stack->head = NULL;

    return stack;
}

void push_s(Stack* stack, Item item)
{
    Node* node = CreateNode(item);

    if (stack->head == NULL) {
        stack->head = node;
        stack->top = stack->head;
    }
    else {
        Node* current = stack->head;
        
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
        stack->top = current->next;
    }

    printf("\nPUSH : %d\n", item);
}

Item peek_s(const Stack* stack)
{
    if (stack->top == NULL) {
        printf("NOT PEEK\n");
        return;
    }

    return stack->top->item;
}

Item pop_s(Stack* stack)
{
    if (stack->top == NULL) {
        printf("NOT POP\n");
        return;
    }

    Item item = stack->top->item;

    if (stack->head == stack->top) {
        stack->head = NULL;
        stack->top == NULL;
    }
    else {
        Node* current = stack->head;
        Node* pre = NULL;

        while (current->next != NULL) {
            pre = current;
            current = current->next;
        }

        stack->top = pre;
        pre->next = current->next;
        free(current);
    }

    printf("\nPOP : %d\n", item);

    return item;
}

void Release_s(Stack* stack)
{
    Node* current = stack->head;

    while (current != NULL) {
        stack->head = stack->head->next;
        free(current);
        current = stack->head;
    }

    free(stack);
}

void print_s(const Stack* stack)
{
    Node* current = stack->head;

    if (stack->head == NULL) {
        printf("NOT PRINT\n");
        return;
    }

    printf("[ ");
    while (current != NULL) {
        printf("%d, ", current->item);
        current = current->next;
    }
    printf("\b\b ]\n");
}
