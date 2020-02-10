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
    FILE* fp;
    char str[20];

    fp = fopen("a.txt", "a+");                          // �ؽ�Ʈ ������ �аų� ������ ���� �߰��ϱ� ���� ����

    if (fp == NULL) {
        printf("������ ������ ���߽��ϴ�.\n");
        return 1;
    }

    while (1) {
        printf("���� �̸� : ");
        scanf("%s", str);

        if (strcmp(str, "end") == 0) {
            break;
        }
        else if (strcmp(str, "list") == 0) {
            rewind(fp);                               // fseek �� ����� ���. 
                                                      //��ġ������ �̵��� ������� ������ rewind�� ����ϴ� ���� �� ����.

            //fseek(fp, 0, SEEK_SET);                 // ������ ó��(SEEK_SET)���� 0��ŭ ��ġ�����ڸ� �̵�
                                                      // ����� ���� --> y���� �̵�
            while (1) {
                fgets(str, sizeof(str), fp);

                if (feof(fp)) { break; }            // feof(file end of file) ������ ������ ��� ������ ����
                printf("%s", str);
            }
        }
        else {
            fprintf(fp, "%s\n", str);               // �Է¹��� ���� ���Ͽ� ���
        }
    }
    fclose(fp);

	system("pause");
	return EXIT_SUCCESS;
}