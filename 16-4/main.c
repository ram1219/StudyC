/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------
  first created - 2020.02.01
  writer - Hugo MG Sung.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �����Լ�
int main(void) 
{
    char temp[80];
    char* str[3];
    
    for (int i = 0; i < 3; i++) {
        printf("���ڿ��� �Է��ϼ��� : ");
        gets(temp);
        str[i] = (char*)malloc(strlen(temp) + 1);
        strcpy(str[i], temp);
    }

    for (int i = 0; i < 3; i++) {
        printf("%s\n", str[i]);
    }

    for (int i = 0; i < 3; i++) {
        free(str[i]);
    }

	system("pause");
	return EXIT_SUCCESS;
}