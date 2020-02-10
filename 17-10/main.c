/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.10
  writer - Hugo MG Sung.
*/

#include <stdio.h>
#include <stdlib.h>

union student {
    int num;
    double grade;
};

// 메인함수
int main(void) 
{
    union student s1 = { 315 };             // union(공용체)는 첫 번째 멤버만 초기화한다.

    printf("학번 : %d\n", s1.num);
    s1.grade = 4.4;
    printf("학점 : %.1lf\n", s1.grade);
    printf("학번 : %d\n", s1.num);          // 위 grade의 double형의 사이즈로 변경된다.

	system("pause");
	return EXIT_SUCCESS;
}