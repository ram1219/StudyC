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

typedef struct _list list;
typedef struct _list {
	double num;
	list* next;
};

void PrintNode();
void InsertNode(double data);
void DeleteNode(int index);
void Release();

enum makelist { INSERT, DELETE, PRINT };

list* head = NULL;
int length = 0;

// �����Լ�
int main(void)
{
	while (1) {
		int process = 0;

		printf("0 : �Է�, 1 : ����, 2 : ��� -> ");
		scanf("%d", &process);

		switch (process)
		{
		case INSERT:
		{
			double data = 0;
			printf("��� �Է� : ");
			scanf("%lf", &data);
			InsertNode(data);
		}
		break;
		case DELETE:
		{
			int index = 0;
			printf("������ �ε����� �Է��ϼ��� : ");
			scanf("%d", &index);
			DeleteNode(index);
		}
		break;
		case PRINT:
			PrintNode();
			break;
		default:
		{
			printf("�����մϴ�.\n");
			Release();
			return;
		}
		}
		printf("\n");
	}

	system("pause");
	return EXIT_SUCCESS;
}

void PrintNode() {

	list* current;

	if (head != NULL) {
		current = head;

		printf("list all : ");

		while (current != NULL) {
			printf("%.1lf\t", current->num);
			current = current->next;
		}
		printf("\n");
	}
	else { printf("�Էµ� ��尪�� �����ϴ�.\n"); }
}

// ��� �߰�
void InsertNode(double data) {

	// ��� �Է¹��� ������ �����Ҵ� �� �ʱ�ȭ
	list* AddNode = (list*)malloc(sizeof(list));
	AddNode->num = data;
	AddNode->next = NULL;

	// � ���� ���� ���
	if (head == NULL) {
		head = AddNode;
	}
	// ���� �� ����� �ڿ� ���ο� ��� �߰�
	else {
		list* current = head;

		while (current->next != NULL) {
			current = current->next;
		}

		current->next = AddNode;

		length++;
	}


}

// ��� ����
void DeleteNode(int index) {

	if (index < 0 || index > length) {
		printf("������ �Ұ����� �ε����Դϴ�.\n");
		return;
	}

	list* current = head;
	list* pre = NULL;                   // current�� ���� �ּ�

	int count = 0;

	//count�� index���� �̵�
	while (count < index) {
		pre = current;
		current = current->next;
		count++;
	}

	pre->next = current->next;

	// �Ҵ��� ���� ���� �� ��ü ���� ����
	length--;
	free(current);
}

void Release()
{
	// �����Ҵ� ������ ���� ���� ���
	if (head == NULL) { return; }

	list* current = head;
	list* target = NULL;

	// �����Ҵ� ���� ����
	while (current != NULL) {
		target = current;
		current = current->next;
		free(target);
	}
}
