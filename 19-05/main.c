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

#define PRINT_EXPR(x) printf(#x "% = %d\n", x)          // �μ��� ���ڿ��� ġȯ
#define NAME_CAT(x,y) (x ## y)                          // 2���� ��ū�� �ϳ��� ����

// �����Լ�
int main(void) 
{
    int a1, a2;

    NAME_CAT(a, 1) = 10;
    NAME_CAT(a, 2) = 20;

    PRINT_EXPR(a1 + a2);
    PRINT_EXPR(a2 - a1);

	system("pause");
	return EXIT_SUCCESS;
}