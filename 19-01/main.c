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
#include "student.h"

// �����Լ�
int main(void) 
{
    Student a = { 315,"ȫ�浿" };

    printf("�й� : %d, �̸� : %s\n", a.num, a.name);

	system("pause");
	return EXIT_SUCCESS;
}