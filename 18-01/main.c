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
    FILE* fp;
    int ch;                        // char을 사용해도 괜찮다.

    fp = fopen("a.txt", "r");
    if (fp == NULL) {
        printf("파일이 열리지 않았습니다.\n");
        return 1;
    }

    //printf("파일이 열렸습니다.\n");

    // 18-02 

    while (1) {
        ch = fgetc(fp);     

        if (ch == EOF) {        // ch가 가져오는 문자가 EOF(End Of File) 이라면 반복문 종료
            break;
        }
        
        putchar(ch);            // ch가 가져온 문자 출력
    }
    printf("\n\n");

    fclose(fp);

	system("pause");
	return EXIT_SUCCESS;
}