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

int input_data(void);
double average(void);
void printf_data(double);

int count = 0;
static int total = 0;

// �����Լ�
int main(void) 
{
    double avg;

    total = input_data();
    avg = average();
    printf_data(avg);

	system("pause");
	return EXIT_SUCCESS;
}

void printf_data(double avg) {
    printf("�Է��� ����� ���� : %d\n", count);
    printf("��ü �հ� ��� : %d, %.1lf\n", total, avg);
}