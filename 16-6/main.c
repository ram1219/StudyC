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
int main(int argc, char** argv) 
{
    // ������Ʈ - �Ӽ� - ����� - ��� �μ��� �Է��� ���� ���� ��� if����
    if (argc <= 1) {
        printf("��� ������ �ùٸ��� �ʽ��ϴ�.\n");
        exit(1);
    }

    char* intarg[2];
    int j = 0;

    for (int i = 0; i < argc; i++) {
        if (i == 0) { continue; }       // 0��°�� ���α׷��� �̸�
        intarg[j] = (char*)malloc(strlen(argv[i]) + 1);
        strcpy(intarg[j], argv[i]);
    }

    printf("ù��° ��� �μ� :%s\n", intarg[0]);
    printf("�ι�° ��� �μ� :%s\n", intarg[1]);

    for (int i = 0; i < argc; i++) {
        free(intarg[i]);
    }
	system("pause");
	return EXIT_SUCCESS;
}