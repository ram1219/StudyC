/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�, ����� ���� �ڷ��� Structure �н�
  --------------------------------------------------------------------------------
  first created - 2020.02.01
  writer - Hugo MG Sung.
*/

#include <stdio.h>
#include <stdlib.h>

struct student {
    int num;
    double grade;
};

// �����Լ�
int main(void) 
{
    struct student s1;

    s1.num = 2;
    s1.grade = 2.7;
    printf("�й� : %d\n", s1.num);
    printf("���� : %.1lf\n", s1.grade);

	system("pause");
	return EXIT_SUCCESS;
}