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

struct profile {
    int age;
    double height;
};

struct student {
    struct profile pf;
    int id;
    double grade;
};
// �����Լ�
int main(void) 
{
    struct student garam;

    garam.pf.age = 25;
    garam.pf.height = 166.8;
    garam.id = 20151490;
    garam.grade = 3.5;

    printf("���� : %d\n", garam.pf.age);
    printf("Ű : %.1lf\n", garam.pf.height);
    printf("�й� : %d\n", garam.id);
    printf("���� : %.1lf\n", garam.grade);
	
	system("pause");
	return EXIT_SUCCESS;
}