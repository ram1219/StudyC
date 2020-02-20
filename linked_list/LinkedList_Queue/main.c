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

typedef int Item;
typedef struct QueueNode Node;
typedef struct Queue Queue;

struct QueueNode {
    Item item;
    Node* next;
};

struct Queue {
    int len;
    Node* front;
    Node* rear;
};

Node* CreateQueueNode(Item item);
Queue* CreateQueue();
void Push_q(Queue* queue, Item item);
Item Peek_q(const Queue* queue);
Item Pop_q(Queue* queue);
void Release_q(Queue* queue);
void print_q(const Queue* queue);

// �����Լ�
int main() 
{
    Queue* queue = CreateQueue();

    Push_q(queue, 10); print_q(queue);
    Push_q(queue, 20); print_q(queue);
    Push_q(queue, 30); print_q(queue);

    printf("PEEK : %d\n", Peek_q(queue)); Pop_q(queue); print_q(queue);
    printf("PEEK : %d\n", Peek_q(queue)); Pop_q(queue); print_q(queue);
    printf("PEEK : %d\n", Peek_q(queue)); Pop_q(queue); print_q(queue);

    Release_q(queue);
}

Node* CreateQueueNode(Item item)
{
    Node* node = (Node*)malloc(sizeof(Node));

    node->item = item;
    node->next = NULL;

    return node;
}

Queue* CreateQueue()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));

    queue->len = 0;
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

void Push_q(Queue* queue, Item item)
{
    Node* node = CreateQueueNode(item);

    // Queue�� ����� ���
    if (queue->front == NULL) {
        // ���� ������ ��尡 front, rear�� �ȴ�.
        queue->front = node;
        queue->rear = node;
    }
    else {
        Node* current = queue->rear;

        // ���� �ִ� �ε����� ������ ��尡 �ȴ�.
        current->next = node;
        // rear�� ���� �̵�
        queue->rear = current->next;
        // rear�� front�� �����Ͽ� ���� ť�� �����.
        queue->rear->next = queue->front;
    }
    queue->len++;
}

Item Peek_q(const Queue* queue)
{
    if (queue->front == NULL) {
        printf("EMPTY QUEUE\n");
        return;
    }

    return queue->front->item;
}

Item Pop_q(Queue* queue)
{
    Item item = queue->front->item;

    // Queue�� �� ���
    if (queue->front == NULL) {
        printf("EMPTY QUEUE\n");
        return;
    }
    // Queue�� ��尡 �� ���� ���
    else if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    }
    else {
        Node* current = queue->front;

        queue->front = current->next;
        queue->rear->next = queue->front;
        free(current);
    }
    queue->len--;

    return item;
}

void Release_q(Queue* queue)
{
    Node* current = queue->front;

    while (current->next != queue->rear) {
        queue->front = current->next;
        free(current);
    }

    free(queue);
}

void print_q(const Queue* queue)
{
    if (queue->front == NULL) {
        printf("EMPTY QUEUE\n");
    }
    else if (queue->front == queue->rear) { printf("%d\n", queue->front->item); }
    else {
        Node* current = queue->front;

        for(int i=0; i < queue->len; i++) {
            printf("%d ", current->item);
            current = current->next;
        }
        printf("\n");
    }
}
