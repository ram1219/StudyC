/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수, 사용자 정의 자료형 Structure 학습
  --------------------------------------------------------------------------------
  first created - 2020.02.01
  writer - Hugo MG Sung.
*/

#include <stdio.h>
#include <stdlib.h>

struct student {
    int num;
    double grade;
};

// 메인함수
int main(void) 
{
    struct student s1;

    s1.num = 2;
    s1.grade = 2.7;
    printf("학번 : %d\n", s1.num);
    printf("학점 : %.1lf\n", s1.grade);

	system("pause");
	return EXIT_SUCCESS;
}