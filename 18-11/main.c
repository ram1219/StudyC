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
    FILE* afp, * bfp;
    int num = 10;
    int res;

    afp = fopen("a.txt", "wt");
    fprintf(afp, "%d", num);

    bfp = fopen("b.txt", "wb");
    fwrite(&num, sizeof(num), 1, bfp);

    fclose(afp);
    fclose(bfp);

    bfp = fopen("b.txt", "rb");
    fread(&res, sizeof(res), 1, bfp);
    printf("%d\n\n", res);

    fclose(bfp);

	system("pause");
	return EXIT_SUCCESS;
}