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
#include <string.h>

struct profile {
    char name[20];
    int age;
    double height;
    char* intro;
};

// �����Լ�
int main(void) 
{
    struct profile yuni;

    strcpy(yuni.name, "�谡��");
    yuni.age = 25;
    yuni.height = 166.8;

    yuni.intro = (char*)malloc(80);
    printf("�ڱ�Ұ� : ");
    gets(yuni.intro);

    printf("�̸� : %s\n", yuni.name);
    printf("���� : %d\n", yuni.age);
    printf("Ű : %.1lf\n", yuni.height);
    printf("�ڱ�Ұ� : %s\n", yuni.intro);

    free(yuni.intro);

	system("pause");
	return EXIT_SUCCESS;
}