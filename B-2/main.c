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
    int temp;
    int min;

    for (int i = 0; i < 4; i++) {
        min = i;
        for (int j = i + 1; j < 5; j++) {
            if (a[min] > a[j]) {
                min = j;
            }
        }
        if (min != i) {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("%5d", a[i]);
    }
    printf("\n\n");
	system("pause");
	return EXIT_SUCCESS;
}