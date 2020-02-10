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
    int age;
    char name[20];

    fp = fopen("a.txt", "r");
    if (fp == NULL) { return 1; }

    fscanf(fp, "%d", &age);

    fgetc(fp);
    fgets(name, sizeof(name), fp);            // 처음부터 개행문자가 입력되어 있으므로 바로 종료된다.
    
   //fscanf(fp, "%s", name);                   // 공백 문자의 이전까지만 출력되는 문제가 발생

    

    printf("이름 : %s, 나이 : %d\n\n", name, age);
    fclose(fp);

	system("pause");
	return EXIT_SUCCESS;
}