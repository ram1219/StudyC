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
#include <string.h>

struct profile {
    char name[20];
    int age;
    double height;
    char* intro;
};

// 메인함수
int main(void) 
{
    struct profile yuni;

    strcpy(yuni.name, "김가람");
    yuni.age = 25;
    yuni.height = 166.8;

    yuni.intro = (char*)malloc(80);
    printf("자기소개 : ");
    gets(yuni.intro);

    printf("이름 : %s\n", yuni.name);
    printf("나이 : %d\n", yuni.age);
    printf("키 : %.1lf\n", yuni.height);
    printf("자기소개 : %s\n", yuni.intro);

    free(yuni.intro);

	system("pause");
	return EXIT_SUCCESS;
}