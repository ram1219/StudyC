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

struct address {
    char name[20];
    int age;
    char tel[20];
    char addr[80];
};

// �����Լ�
int main(void) 
{
    struct address list[5] = {
        {"ȫ�浿",23,"111-1111","�︪�� ����"},
        {"�̼���",35,"222-2222","���� ��õ��"},
        {"�庸��",19,"333-3333","�ϵ� û����"},
        {"������",15,"444-4444","�泲 õ��"},
        {"���߱�",45,"555-5555","Ȳ�ص� ����"}
    };
    
    for (int i = 0; i < 5; i++) {
        printf("%10s%5d%15s%20s\n", list[i].name, list[i].age, list[i].tel, list[i].addr);
    }

	system("pause");
	return EXIT_SUCCESS;
}