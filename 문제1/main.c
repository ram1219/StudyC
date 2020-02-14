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

// 메인함수
int main(void) 
{
    int sum = 0;

    for (int i = 1; i <= 300; i++) {
        if (i % 3 == 0) {
            sum += i;
        }
    }

    printf("\n1 부터 300 까지의 숫자 중 3의 배수의 합 = %d\n\n", sum);
    
	system("pause");
	return EXIT_SUCCESS;
}