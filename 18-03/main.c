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
    char str[] = "banana";
    int i = 0;

    fp = fopen("b.txt", "w");
    if (fp == NULL) {
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }

    while (str[i] != '\0') {
        fputc(str[i], fp);
        i++;
    }
    fputc('\n', fp);
    fclose(fp);

	system("pause");
	return EXIT_SUCCESS;
}