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

struct score {
    int kor;
    int eng;
    int math;
};

// �����Լ�
int main(void) 
{
    struct score yuni = { 90,80,70 };
    struct score* ps = &yuni;

    printf("���� : %d\n", (*ps).kor);
    printf("���� : %d\n", ps->eng);
    printf("���� : %d\n", ps->math);

	system("pause");
	return EXIT_SUCCESS;
}