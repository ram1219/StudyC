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
    int ch;

    while (1) {
        ch = fgetc(stdin);

        if (ch == EOF) {                    // ctrl + Z (-1)�� �Է��� �����Ѵ�.
            break;
        }

        fputc(ch, stdout);
    }
	system("pause");
	return EXIT_SUCCESS;
}