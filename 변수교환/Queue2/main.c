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

typedef struct _Queue Queue;
typedef int Items;

struct _Queue {
    int len;
    Items front;
    Items rear;
    Items items;
};

Queue* Create_cq();
void Release_cq(Queue * queue);
void Print_cq(const Queue* queue);
void Push_cq(Queue* queue, Items item);
Items Pop_cq(Queue* queue);
Items Peek_cq(const Queue* queue);
bool isEmpty_cq(const Queue* queue);

// �����Լ�
int main() 
{
	
}