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
#define PI 3.14159
#define LIMIT 100.0
#define MSG "passed!"
#define ERR_PRN printf("��� ������ ������ϴ�!\n")

// �����Լ�
int main(void) 
{
    double radius, area;

    printf("�������� �Է��ϼ���(10 ����) : ");
    scanf("%lf", &radius);

    area = PI * radius * radius;

    if (area > LIMIT) { ERR_PRN; }
    else { printf("���� ���� : %.2lf (%s) \n", area, MSG); }

	system("pause");
	return EXIT_SUCCESS;
}