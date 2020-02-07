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
    int size = 5;
    int count = 0;
    int num;
    
    pi = (int*)calloc(size, sizeof(int));       // size * sizeof(int) 할당

    while (1) {
        printf("양수만 입력하세요 : ");
        scanf("%d", &num);

        if (num <= 0) {
            break;
        }
        if (count == size) {
            size += 5;
            pi = (int*)realloc(pi, size * sizeof(int));     // pi의 할당값을 size *sizeof(int)로 재할당
        }
        pi[count++] = num;

    }

    for (int i = 0; i < count; i++) {
         printf("%5d", pi[i]);
    }

    free(pi);

	system("pause");
	return EXIT_SUCCESS;
}