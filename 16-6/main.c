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
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
	system("pause");
	return EXIT_SUCCESS;
}