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

#define VER 7
#define BIT16

// �����Լ�
int main(void) 
{
    int Max;

#if VER >= 6                        // if�� ������ �����ؾ� �������� �����ϴ�  ---> ���Ǻ� ������
    printf("���� %d�Դϴ�.\n", VER);
#else
#error �����Ϸ� ������ 6.0 �̻��̾�� �մϴ�.
#endif

#ifdef BIT16                        // if defined (ifdef) ---> ��ũ�θ��� ���ǵǾ� �ִ��� Ȯ��
        Max = 32767;                // if !defined (ifndef)  --> ���� �ݴ�
#else
        Max = 2147483647;
#endif

        printf("int�� ������ �ִ� : %d\n", Max);

	system("pause");
	return EXIT_SUCCESS;
}