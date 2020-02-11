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

#define VER 7
#define BIT16

// 메인함수
int main(void) 
{
    int Max;

#if VER >= 6                        // if의 조건을 충족해야 컴파일이 가능하다  ---> 조건부 컴파일
    printf("버전 %d입니다.\n", VER);
#else
#error 컴파일러 버전은 6.0 이상이어야 합니다.
#endif

#ifdef BIT16                        // if defined (ifdef) ---> 매크로명이 정의되어 있는지 확인
        Max = 32767;                // if !defined (ifndef)  --> 위와 반대
#else
        Max = 2147483647;
#endif

        printf("int형 변수의 최댓값 : %d\n", Max);

	system("pause");
	return EXIT_SUCCESS;
}