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

char GetGrade(int num) {
    if (num <= 100 && num >= 90) {
        return 'A';
    }
    else if (num >= 70) {
        return 'B';
    }
    else if (num >= 60) {
        return 'C';
    }
    else if (num >= 50) {
        return 'D';
    }
    else {
        return 'F';
    }
}
// �����Լ�
int main(void) 
{
    int num;

    printf("������ �Է��ϼ��� : ");
    scanf("%d", &num);

    if (num >= 0 && num <= 100) {
        printf("���� : %c\n", GetGrade(num));
    }
    else {
        printf("1���� 100������ ������ �Է����ּ���.\n");
    }
    printf("\n");
	system("pause");
	return EXIT_SUCCESS;
}