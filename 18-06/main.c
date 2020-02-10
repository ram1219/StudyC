/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.01
  writer - Hugo MG Sung.
*/

#include <stdio.h>
#include <stdlib.h>

// 메인함수
int main(void) 
{
    FILE* fp;
    int ary[10] = { 13, 10, 13, 13, 10, 16, 13, 10, 13, 10 };           // 26은 ctrl + Z와 같다. --> 종료가 됨.
    int res;

    fp = fopen("c.txt", "wb");                  // 파일을 쓰기위해 개방

    for (int i = 0; i < 10; i++) {
        fputc(ary[i], fp);
    }
    fclose(fp);

    fp = fopen("c.txt", "r");                  // 파일을 읽기위해 개방

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