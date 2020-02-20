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
#include <stdbool.h>
#include <string.h>

/* ///// �迭 �̿� Queue ///// */

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

// �����Լ�
int main() 
{
    Queue* queue = Create_Q();

    printf("\n ***** ���� ť ���� ***** \n");
    printf("\n ���� A>> ");  Push_Q(queue, 'A'); Print_Q(queue);
    printf("\n ���� B>> ");  Push_Q(queue, 'B'); Print_Q(queue);
    printf("\n ���� C>> ");  Push_Q(queue, 'C'); Print_Q(queue);

    printf("\nPEEK ITEM : %c\n", Peek_Q(queue));
    
    printf("\n ���� ������ : %c", Peek_Q(queue));
    printf("\n ���� >> "); Pop_Q(queue); Print_Q(queue);
    printf("\n ���� ������ : %c", Peek_Q(queue));
    printf("\n ���� >> "); Pop_Q(queue); Print_Q(queue);
    printf("\n ���� ������ : %c", Peek_Q(queue));
    printf("\n ���� >> "); Pop_Q(queue); Print_Q(queue);

    printf("\n ���� D>> ");  Push_Q(queue, 'D'); Print_Q(queue);
    printf("\n ���� E>> ");  Push_Q(queue, 'E'); Print_Q(queue);
    Release_Q(queue);
}

// Queue���� �� �ʱ�ȭ
Queue* Create_Q()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));

    queue->len = -1;
    queue->cap = InitSize;
    queue->items = (Items*)malloc(sizeof(Items)* InitSize);

    return queue;
}

// full���� Ȯ���ϰ�, full �̸� Ȯ���� �� ������ push
void Push_Q(Queue* queue, Items items)
{
    if (is_full_Q(queue)) { Expand_Q(queue); }

    queue->len++;
    queue->items[queue->len] = items;
}

// full���� Ȯ��
bool is_full_Q(const Queue* queue)
{
    return queue->len + 1 == queue->cap ? true : false;
}

// full�̸� Ȯ��
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

// POP�� �������� ������ Ȯ��
Items Peek_Q(const Queue* queue)
{
    if (is_empty_Q(queue)) {
        printf("Empty Queue\n");
    }
    
    return queue->items[0];
}

// POP�� �� ��, �����͸� �� ĭ�� �̵�
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

// Queue�� ������� Ȯ��
bool is_empty_Q(const Queue* queue)
{
    return queue->len == -1 ? true : false;
}

// �����Ҵ� ����
void Release_Q(Queue* queue)
{
    free(queue->items);
    free(queue);
}

// Queue�� �����ϰ� �ִ� ������ ���
void Print_Q(const Queue* queue)
{
    printf("[");
    for (int i = 0; i <= queue->len; i++) {
        printf(" %c ", queue->items[i]);
    }
    printf("]\n\n");
}
