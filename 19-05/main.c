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

#define PRINT_EXPR(x) printf(#x "% = %d\n", x)          // 인수를 문자열로 치환
#define NAME_CAT(x,y) (x ## y)                          // 2개의 토큰을 하나로 붙임

// 메인함수
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