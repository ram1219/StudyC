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
typedef struct List List;

struct Node {
    Item item;
    Node* next;
};

struct List {
    int len;
    Node* head;
};

Node* CreateNode(Item item);
List* CreateList();
void InsertNode(Item item, List* list);
void DeleteNode(int index, List* list);
void PrintList(List* list);
void Release(List* list);

enum makelist { INSERT, DELETE, PRINT };

// 메인함수
int main()
{
    // 실행할 동작 입력
    int input = 0;
    // 노드가 들어갈 리스트 생성
    List* list = CreateList();

    while (1) {

        printf("0 : 입력, 1 : 삭제, 2 : 출력 -> ");
        scanf("%d", &input);

        switch (input)
        {
        case INSERT:
        {
            Item item = 0;
            printf("노드 입력 : ");
            scanf("%d", &item);
            InsertNode(item, list);
        }
        break;
        case DELETE:
        {
            int index = 0;
            printf("삭제할 인덱스를 입력하세요 : ");
            scanf("%d", &index);
            DeleteNode(index, list);
        }
        break;
        case PRINT:
            PrintList(list);
            break;
        default:
        {
            printf("종료합니다.\n");
            Release(list);
            return;
        }
        }
        printf("\n");
    }

    Release(list);
}

// 노드 생성 후 초기화
Node* CreateNode(Item item)
{
    Node* node = (Node*)malloc(sizeof(Node));

    node->item = item;
    node->next = NULL;

    return node;
}

// node를 담을 list 생성 후 초기화
List* CreateList()
{
    List* list = (List*)malloc(sizeof(List));

    list->len = 0;
    list->head = NULL;

    return list;
}

// list에 node 삽입
void InsertNode(Item item, List* list)
{
    // 변수로 받은 item을 가진 노드를 생성.
    Node* node = CreateNode(item);

    // head(초기data)가 없는 경우 생성한 노드를 head로 지정.
    if (list->head == NULL) { list->head = node; }
    // list안의 노드들이 오름차순으로 정렬이 되도록 삽입
    else {
        Node* current = list->head;
        Node* pre = NULL;

        // 생성한 노드가 head보다 작은 경우                                // --------- head에 삽입
        if (node->item < list->head->item) {
            // 생성한 노드의 next가 current(현재 head)를 가리킴
            node->next = current;
            // head를 생성한 노드의 값으로 변경
            list->head = node;
        }
        else {
            // list의 끝까지 반복하면서 들어갈 공간 탐색
            while (current != NULL) {                                                                                                 

                // 생성한 노드가 현재 위치의 노드보다 작으면               // --------- middle에 삽입
                if (node->item < current->item) {
                    // 생성한 노드는 현재 위치의 노드를 가리킴
                    node->next = current;
                    // 이전 노드는 새로 생성한 노드를 가리킴
                    pre->next = node;

                    // 반복문 탈출
                    break;
                }

                pre = current;
                current = current->next;
            }

            // 생성한 노드가 마지막 값보다 큰 경우
            if (current == NULL) {                                        // ---------- tail에 삽입
               pre->next = node;
            }
        }
    }
    printf("\n[ %d ] INSERT\n", node->item);
    list->len++;
}

// list에서 노드 제거
void DeleteNode(int index, List* list)
{
    Node* current = list->head;
    Node* pre = NULL;

    if (list->len == 0) {
        printf("EMPTY LIST\n");
        return;
    }

    if (index<0 || index>list->len) {
        printf("NOT DELETE\n");
        return;
    }

    // 삭제할 인덱스가 head인 경우
    if (index == 0) {
        // 노드가 head만 있는 경우
        if (current->next == NULL) {
            // head를 비우고
            list->head = NULL;
        }
        else {
            // head를 head의 다음 노드로 이동
            list->head = current->next;
            free(current);
        }
    }
    else {
        // index의 위치까지 current를 이동
        for (int i = 0; i < index; i++) {
            pre = current;
            current = current->next;
        }

        // current == index 일 때, pre가 current->next를 가리킴
        pre->next = current->next;
        free(current);

    }
    printf("\n[ INDEX : %d ] DELET\n", index);
    list->len--;
}

void PrintList(const List* list)
{
    Node* current = list->head;

    if (list->len == 0) {
        printf("NOT PRINT\n");
        return;
    }

    printf("[ ");
    while(current != NULL) {
        printf("%d, ", current->item);
        current = current->next;
    }
    printf("\b\b ]\n");
}

// 동적 할당 해제
void Release(List* list)
{
    // ReleaseNode
    Node* current = list->head;
    while (current != NULL) {
        // head를 다음 위치로 이동
        list->head = list->head->next;
        // current가 가진 head값을 해제
        free(current);
        // current도 다음 위치로 이동
        current = list->head;
    }

    // ReleaseList
    free(list);
}