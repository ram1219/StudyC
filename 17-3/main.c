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

struct profile {
    int age;
    double height;
};

struct student {
    struct profile pf;
    int id;
    double grade;
};
// 메인함수
int main(void) 
{
    struct student garam;

    garam.pf.age = 25;
    garam.pf.height = 166.8;
    garam.id = 20151490;
    garam.grade = 3.5;

    printf("나이 : %d\n", garam.pf.age);
    printf("키 : %.1lf\n", garam.pf.height);
    printf("학번 : %d\n", garam.id);
    printf("학점 : %.1lf\n", garam.grade);
	
	system("pause");
	return EXIT_SUCCESS;
}