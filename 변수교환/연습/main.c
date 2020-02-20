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
#include <stdbool.h>
#include <string.h>

/* ///// 배열 이용 Queue ///// */

typedef char Items;
typedef struct _Queue Queue;

#define InitSize 20

struct _Queue {
    int len;
    int cap;
    Items* items;
};

Queue* Create_Q();
void Push_Q(Queue* queue, Items items);
bool is_full_Q(const Queue* queue);
void Expand_Q(Queue* queue);
Items Peek_Q(const Queue* queue);
Items Pop_Q(Queue* queue);
bool is_empty_Q(const Queue* queue);
void Release_Q(Queue* queue);
void Print_Q(const Queue* queue);

// 메인함수
int main() 
{
    Queue* queue = Create_Q();

    printf("\n ***** 순차 큐 연산 ***** \n");
    printf("\n 삽입 A>> ");  Push_Q(queue, 'A'); Print_Q(queue);
    printf("\n 삽입 B>> ");  Push_Q(queue, 'B'); Print_Q(queue);
    printf("\n 삽입 C>> ");  Push_Q(queue, 'C'); Print_Q(queue);

    printf("\nPEEK ITEM : %c\n", Peek_Q(queue));
    
    printf("\n 삭제 데이터 : %c", Peek_Q(queue));
    printf("\n 삭제 >> "); Pop_Q(queue); Print_Q(queue);
    printf("\n 삭제 데이터 : %c", Peek_Q(queue));
    printf("\n 삭제 >> "); Pop_Q(queue); Print_Q(queue);
    printf("\n 삭제 데이터 : %c", Peek_Q(queue));
    printf("\n 삭제 >> "); Pop_Q(queue); Print_Q(queue);

    printf("\n 삽입 D>> ");  Push_Q(queue, 'D'); Print_Q(queue);
    printf("\n 삽입 E>> ");  Push_Q(queue, 'E'); Print_Q(queue);
    Release_Q(queue);
}

// Queue생성 및 초기화
Queue* Create_Q()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));

    queue->len = -1;
    queue->cap = InitSize;
    queue->items = (Items*)malloc(sizeof(Items)* InitSize);

    return queue;
}

// full인지 확인하고, full 이면 확장한 후 데이터 push
void Push_Q(Queue* queue, Items items)
{
    if (is_full_Q(queue)) { Expand_Q(queue); }

    queue->len++;
    queue->items[queue->len] = items;
}

// full인지 확인
bool is_full_Q(const Queue* queue)
{
    return queue->len + 1 == queue->cap ? true : false;
}

// full이면 확장
void Expand_Q(Queue* queue)
{
    Items* items = (Items*)malloc(sizeof(Items) * queue->cap * 2);

    for (int i = 0; i < queue->cap; i++) {
        items[i] = queue->items[i];
    }
    free(queue->items);

    queue->cap *= 2;
    queue->items = items;
}

// POP시 빠져나올 데이터 확인
Items Peek_Q(const Queue* queue)
{
    if (is_empty_Q(queue)) {
        printf("Empty Queue\n");
    }
    
    return queue->items[0];
}

// POP을 한 후, 데이터를 한 칸씩 이동
Items Pop_Q(Queue* queue)
{
    if (is_empty_Q(queue)) {
        printf("Empty Queue\n");
        return;
    }
    Items item = queue->items[0];

    for (int i = 0; i < queue->len; i++) {
        queue->items[i] = queue->items[i + 1];
    }
    queue->len--;

    return item;
}

// Queue가 비었는지 확인
bool is_empty_Q(const Queue* queue)
{
    return queue->len == -1 ? true : false;
}

// 동적할당 해제
void Release_Q(Queue* queue)
{
    free(queue->items);
    free(queue);
}

// Queue가 저장하고 있는 데이터 출력
void Print_Q(const Queue* queue)
{
    printf("[");
    for (int i = 0; i <= queue->len; i++) {
        printf(" %c ", queue->items[i]);
    }
    printf("]\n\n");
}
