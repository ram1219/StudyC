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

typedef struct student {            // typedef 재정의 자료형 ---> Student라는 이름으로 struct를 재정의한다.
    int num;                        // 구조체를 불러올 때, struct student 가 아닌 Student로 불러오기가 가능하다.
    double grade;
}Student;

void print_data(Student* ps);
// 메인함수
int main(void) 
{
    Student s1 = { 315,4.2 };

    print_data(&s1);

	system("pause");
	return EXIT_SUCCESS;
}

void print_data(Student* ps) {
    printf("학번 : %d\n", ps->num);
    printf("학점 : %.1lf\n", ps->grade);
}