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

// 메인함수
int main(void)
{
	while (1) {
		int process = 0;

		printf("0 : 입력, 1 : 삭제, 2 : 출력 -> ");
		scanf("%d", &process);

		switch (process)
		{
		case INSERT:
		{
			double data = 0;
			printf("노드 입력 : ");
			scanf("%lf", &data);
			InsertNode(data);
		}
		break;
		case DELETE:
		{
			int index = 0;
			printf("삭제할 인덱스를 입력하세요 : ");
			scanf("%d", &index);
			DeleteNode(index);
		}
		break;
		case PRINT:
			PrintNode();
			break;
		default:
		{
			printf("종료합니다.\n");
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
	else { printf("입력된 노드값이 없습니다.\n"); }
}

// 노드 추가
void InsertNode(double data) {

	// 노드 입력받을 공간을 동적할당 후 초기화
	list* AddNode = (list*)malloc(sizeof(list));
	AddNode->num = data;
	AddNode->next = NULL;

	// 어떤 값도 없는 경우
	if (head == NULL) {
		head = AddNode;
	}
	// 제일 끝 노드의 뒤에 새로운 노드 추가
	else {
		list* current = head;

		while (current->next != NULL) {
			current = current->next;
		}

		current->next = AddNode;

		length++;
	}


}

// 노드 제거
void DeleteNode(int index) {

	if (index < 0 || index > length) {
		printf("삭제가 불가능한 인덱스입니다.\n");
		return;
	}

	list* current = head;
	list* pre = NULL;                   // current의 이전 주소

	int count = 0;

	//count가 index까지 이동
	while (count < index) {
		pre = current;
		current = current->next;
		count++;
	}

	pre->next = current->next;

	// 할당한 공간 해제 및 전체 길이 감소
	length--;
	free(current);
}

void Release()
{
	// 동적할당 해제할 값이 없는 경우
	if (head == NULL) { return; }

	list* current = head;
	list* target = NULL;

	// 동적할당 공간 해제
	while (current != NULL) {
		target = current;
		current = current->next;
		free(target);
	}
}
