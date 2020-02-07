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
#include <string.h>

void printf_str(char** ps);
// 메인함수
int main(void) 
{
    char temp[80];
    char* str[21] = { 0 };
    int i = 0;

    while (i < 20) {
        printf("문자열을 입력하세요 : ");
        gets(temp);

        if (strcmp(temp, "end") == 0) { break; }

        str[i] = (char*)malloc(strlen(temp) + 1);
        strcpy(str[i], temp);
        i++;
    }
    
    printf_str(str);

    for (i = 0; str[i] != NULL; i++) {
        free(str[i]);
    }

	system("pause");
	return EXIT_SUCCESS;
}

void printf_str(char** ps) {
    while (*ps != NULL) {
        printf("%s\n", *ps);
        ps++;
    }
}