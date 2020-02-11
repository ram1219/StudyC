/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
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

// 메인함수
int main(void) 
{
    printf("Sample1 구조체의 크기 : %d바이트\n", sizeof(Sample1));
    printf("Sample2 구조체의 크기 : %d바이트\n", sizeof(Sample2));

	system("pause");
	return EXIT_SUCCESS;
}