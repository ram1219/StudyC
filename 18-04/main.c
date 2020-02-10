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
    int ch;

    while (1) {
        ch = getchar();
        if (ch == EOF) {                    // ctrl + Z (-1)로 입력을 종료한다.
            break;
        }
        putchar(ch);
    }

	system("pause");
	return EXIT_SUCCESS;
}