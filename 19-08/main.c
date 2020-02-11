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

#include "sub.h"                            // sub.c에 있는 함수의 선언

// 메인함수
int main(void) 
{
    int a, b;
    double avg;

    input_data(&a, &b);                     // sub.c의 함수
    avg = average(a, b);                    // sub.c의 함수
    printf("%d와 %d의 평균 : %.1lf\n", a, b, avg);

	system("pause");
	return EXIT_SUCCESS;
}