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
    int a[5] = { 3,2,1,6,5 };
    int b[5] = { 3,2,1,6,5 };
    int temp;

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (b[i] < b[j]) {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("%5d", a[i]);
    }

    printf("\n\n");

    for (int i = 0; i < 5; i++) {
        printf("%5d", b[i]);
    }

    printf("\n\n");

	system("pause");
	return EXIT_SUCCESS;
}