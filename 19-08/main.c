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

#include "sub.h"                            // sub.c�� �ִ� �Լ��� ����

// �����Լ�
int main(void) 
{
    int a, b;
    double avg;

    input_data(&a, &b);                     // sub.c�� �Լ�
    avg = average(a, b);                    // sub.c�� �Լ�
    printf("%d�� %d�� ��� : %.1lf\n", a, b, avg);

	system("pause");
	return EXIT_SUCCESS;
}