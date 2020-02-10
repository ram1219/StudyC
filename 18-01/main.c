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
    int ch;                        // char�� ����ص� ������.

    fp = fopen("a.txt", "r");
    if (fp == NULL) {
        printf("������ ������ �ʾҽ��ϴ�.\n");
        return 1;
    }

    //printf("������ ���Ƚ��ϴ�.\n");

    // 18-02 

    while (1) {
        ch = fgetc(fp);     

        if (ch == EOF) {        // ch�� �������� ���ڰ� EOF(End Of File) �̶�� �ݺ��� ����
            break;
        }
        
        putchar(ch);            // ch�� ������ ���� ���
    }
    printf("\n\n");

    fclose(fp);

	system("pause");
	return EXIT_SUCCESS;
}