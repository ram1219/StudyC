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
    int* pi;
    int i, sum = 0;

    pi = (int*)malloc(5 * sizeof(int));
    if (pi == NULL) {
        printf("�޸𸮰� �����մϴ�!\n");
        exit(1);
    }

    printf("�ټ����� ���̸� �Է��ϼ��� : ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &pi[i]);
        sum += pi[i];
    }

    printf("�ټ� ���� ��� ���� : %.1lf\n", (sum / 5.0));
    free(pi);

	system("pause");
	return EXIT_SUCCESS;
}