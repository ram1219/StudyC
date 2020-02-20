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

// 메인함수
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

// 스택공간 생성 및 초기화
Stack* Create_s()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));

    stack->top = -1;
    stack->cap = InitSize;
    stack->items = (Items*)malloc(sizeof(Items) * InitSize);

    return stack;
}

// 동적할당 해제
void Release_s(Stack* stack)
{
    free(stack->items);
    free(stack);
}

// stack내용 출력
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

// push할 공간이 없으면 expand한 후 push
void Push_s(Stack* stack, Items items)
{
    if (isFull_s(stack) == 1) { Expand_s(stack); }

    stack->top++;
    stack->items[stack->top] = items;
}

// push공간 확인
int isFull_s(const Stack* stack)
{
    return stack->top + 1 == stack->cap ? 1 : 0;
}

// stack이 가득찬 경우 공간 확장
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

// top 가져오기
Items Peek_s(const Stack* stack)
{
    if (isEmpty_s(stack) == 1) {
        printf("Empty Stack\n");
        return;
    }

    return stack->items[stack->top];
}

// top 빼기
Items Pop_s(Stack* stack)
{
    if (isEmpty_s(stack) == 1) {
        printf("Empty Stack\n");
        return;
    }

    return stack->items[stack->top--];
}

// stack이 비었는지 확인
int isEmpty_s(const Stack* stack)
{
    return stack->top == -1 ? 1 : 0;
}
