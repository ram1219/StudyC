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
    int* pi;
    int i, sum = 0;

    pi = (int*)malloc(5 * sizeof(int));
    if (pi == NULL) {
        printf("메모리가 부족합니다!\n");
        exit(1);
    }

    printf("다섯명의 나이를 입력하세요 : ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &pi[i]);
        sum += pi[i];
    }

    printf("다섯 명의 평균 나이 : %.1lf\n", (sum / 5.0));
    free(pi);

	system("pause");
	return EXIT_SUCCESS;
}