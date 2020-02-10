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
    int ary[10] = { 13, 10, 13, 13, 10, 16, 13, 10, 13, 10 };           // 26�� ctrl + Z�� ����. --> ���ᰡ ��.
    int res;

    fp = fopen("c.txt", "wb");                  // ������ �������� ����

    for (int i = 0; i < 10; i++) {
        fputc(ary[i], fp);
    }
    fclose(fp);

    fp = fopen("c.txt", "r");                  // ������ �б����� ����

    while (1) {
        res = fgetc(fp);

        if (res == EOF) {
            break;
        }

        printf("%5d", res);
    }
    printf("\n\n");

    fclose(fp);

	system("pause");
	return EXIT_SUCCESS;
}