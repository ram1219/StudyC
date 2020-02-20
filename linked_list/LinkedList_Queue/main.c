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

// 메인함수
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

    // Queue가 비었을 경우
    if (queue->front == NULL) {
        // 새로 생성된 노드가 front, rear가 된다.
        queue->front = node;
        queue->rear = node;
    }
    else {
        Node* current = queue->rear;

        // 현재 있는 인덱스의 다음이 노드가 된다.
        current->next = node;
        // rear의 값을 이동
        queue->rear = current->next;
        // rear를 front랑 연결하여 원형 큐로 만든다.
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

    // Queue가 빈 경우
    if (queue->front == NULL) {
        printf("EMPTY QUEUE\n");
        return;
    }
    // Queue의 노드가 한 개인 경우
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
