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

// �����Լ�
int main()
{
    // ������ ���� �Է�
    int input = 0;
    // ��尡 �� ����Ʈ ����
    List* list = CreateList();

    while (1) {

        printf("0 : �Է�, 1 : ����, 2 : ��� -> ");
        scanf("%d", &input);

        switch (input)
        {
        case INSERT:
        {
            Item item = 0;
            printf("��� �Է� : ");
            scanf("%d", &item);
            InsertNode(item, list);
        }
        break;
        case DELETE:
        {
            int index = 0;
            printf("������ �ε����� �Է��ϼ��� : ");
            scanf("%d", &index);
            DeleteNode(index, list);
        }
        break;
        case PRINT:
            PrintList(list);
            break;
        default:
        {
            printf("�����մϴ�.\n");
            Release(list);
            return;
        }
        }
        printf("\n");
    }

    Release(list);
}

// ��� ���� �� �ʱ�ȭ
Node* CreateNode(Item item)
{
    Node* node = (Node*)malloc(sizeof(Node));

    node->item = item;
    node->next = NULL;

    return node;
}

// node�� ���� list ���� �� �ʱ�ȭ
List* CreateList()
{
    List* list = (List*)malloc(sizeof(List));

    list->len = 0;
    list->head = NULL;

    return list;
}

// list�� node ����
void InsertNode(Item item, List* list)
{
    // ������ ���� item�� ���� ��带 ����.
    Node* node = CreateNode(item);

    // head(�ʱ�data)�� ���� ��� ������ ��带 head�� ����.
    if (list->head == NULL) { list->head = node; }
    // list���� ������ ������������ ������ �ǵ��� ����
    else {
        Node* current = list->head;
        Node* pre = NULL;

        // ������ ��尡 head���� ���� ���                                // --------- head�� ����
        if (node->item < list->head->item) {
            // ������ ����� next�� current(���� head)�� ����Ŵ
            node->next = current;
            // head�� ������ ����� ������ ����
            list->head = node;
        }
        else {
            // list�� ������ �ݺ��ϸ鼭 �� ���� Ž��
            while (current != NULL) {                                                                                                 

                // ������ ��尡 ���� ��ġ�� ��庸�� ������               // --------- middle�� ����
                if (node->item < current->item) {
                    // ������ ���� ���� ��ġ�� ��带 ����Ŵ
                    node->next = current;
                    // ���� ���� ���� ������ ��带 ����Ŵ
                    pre->next = node;

                    // �ݺ��� Ż��
                    break;
                }

                pre = current;
                current = current->next;
            }

            // ������ ��尡 ������ ������ ū ���
            if (current == NULL) {                                        // ---------- tail�� ����
               pre->next = node;
            }
        }
    }
    printf("\n[ %d ] INSERT\n", node->item);
    list->len++;
}

// list���� ��� ����
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

    // ������ �ε����� head�� ���
    if (index == 0) {
        // ��尡 head�� �ִ� ���
        if (current->next == NULL) {
            // head�� ����
            list->head = NULL;
        }
        else {
            // head�� head�� ���� ���� �̵�
            list->head = current->next;
            free(current);
        }
    }
    else {
        // index�� ��ġ���� current�� �̵�
        for (int i = 0; i < index; i++) {
            pre = current;
            current = current->next;
        }

        // current == index �� ��, pre�� current->next�� ����Ŵ
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

// ���� �Ҵ� ����
void Release(List* list)
{
    // ReleaseNode
    Node* current = list->head;
    while (current != NULL) {
        // head�� ���� ��ġ�� �̵�
        list->head = list->head->next;
        // current�� ���� head���� ����
        free(current);
        // current�� ���� ��ġ�� �̵�
        current = list->head;
    }

    // ReleaseList
    free(list);
}