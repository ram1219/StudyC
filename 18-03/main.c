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

// �����Լ�
int main(void) 
{
    FILE* fp;
    char str[] = "banana";
    int i = 0;

    fp = fopen("b.txt", "w");
    if (fp == NULL) {
        printf("������ ������ ���߽��ϴ�.\n");
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