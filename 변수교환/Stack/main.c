/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------
  first created - 2020.02.01
  writer - Hugo MG Sung.
*/

#include <stdio.h>
#include <stdlib.h>

typedef int Items;
typedef struct _Stack Stack;

#define InitSize 10

struct _Stack {
    int top;
    int cap;
    Items* items;
};

Stack* Create_s();
void Release_s(Stack* stack);
void Print_s(const Stack* stack);

void Push_s(Stack* stack, Items items);
int isFull_s(const Stack* stack);
void Expand_s(Stack* stack);

Items Peek_s(const Stack* stack);
Items Pop_s(Stack* stack);
int isEmpty_s(const Stack* stack);

// �����Լ�
int main() 
{
    Stack* stack = Create_s();

    Push_s(stack, 0);
    Print_s(stack);
    Push_s(stack, 10);
    Print_s(stack);
    Push_s(stack, 20);
    Print_s(stack);

    Items item = Peek_s(stack);
    printf("peek => %d\n\n", item);

    Pop_s(stack);
    Print_s(stack);
    Pop_s(stack);
    Print_s(stack);

    Release_s(stack);
}

// ���ð��� ���� �� �ʱ�ȭ
Stack* Create_s()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));

    stack->top = -1;
    stack->cap = InitSize;
    stack->items = (Items*)malloc(sizeof(Items) * InitSize);

    return stack;
}

// �����Ҵ� ����
void Release_s(Stack* stack)
{
    free(stack->items);
    free(stack);
}

// stack���� ���
void Print_s(const Stack* stack)
{
    if (stack->top == -1) {
        printf("Empty Stack\n");
    }
    else {
        for (int i = 0; i <= stack->top; i++) {
            printf("[%d] = %d\n", i, stack->items[i]);
        }
        printf("\n");
    }
}

// push�� ������ ������ expand�� �� push
void Push_s(Stack* stack, Items items)
{
    if (isFull_s(stack) == 1) { Expand_s(stack); }

    stack->top++;
    stack->items[stack->top] = items;
}

// push���� Ȯ��
int isFull_s(const Stack* stack)
{
    return stack->top + 1 == stack->cap ? 1 : 0;
}

// stack�� ������ ��� ���� Ȯ��
void Expand_s(Stack* stack)
{
    Items* items = (Items*)malloc(sizeof(items) * stack->cap * 2);

    for (int i = 0; i < stack->cap; i++) {
        items[i] = stack->items[i];
    }
    free(stack->items);

    stack->cap *= 2;
    stack->items = items;
}

// top ��������
Items Peek_s(const Stack* stack)
{
    if (isEmpty_s(stack) == 1) {
        printf("Empty Stack\n");
        return;
    }

    return stack->items[stack->top];
}

// top ����
Items Pop_s(Stack* stack)
{
    if (isEmpty_s(stack) == 1) {
        printf("Empty Stack\n");
        return;
    }

    return stack->items[stack->top--];
}

// stack�� ������� Ȯ��
int isEmpty_s(const Stack* stack)
{
    return stack->top == -1 ? 1 : 0;
}
