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

#pragma pack(push, 1)
typedef struct {
    char ch;
    int in;
}Sample1;

#pragma pack(pop)
typedef struct {
    char ch;
    int in;
}Sample2;

// �����Լ�
int main(void) 
{
    printf("Sample1 ����ü�� ũ�� : %d����Ʈ\n", sizeof(Sample1));
    printf("Sample2 ����ü�� ũ�� : %d����Ʈ\n", sizeof(Sample2));

	system("pause");
	return EXIT_SUCCESS;
}