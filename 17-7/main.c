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

struct address {
    char name[20];
    int age;
    char tel[20];
    char addr[80];
};

// 메인함수
int main(void) 
{
    struct address list[5] = {
        {"홍길동",23,"111-1111","울릉도 독도"},
        {"이순신",35,"222-2222","서울 건천동"},
        {"장보고",19,"333-3333","완도 청해진"},
        {"유관순",15,"444-4444","충남 천안"},
        {"안중근",45,"555-5555","황해도 해주"}
    };
    
    for (int i = 0; i < 5; i++) {
        printf("%10s%5d%15s%20s\n", list[i].name, list[i].age, list[i].tel, list[i].addr);
    }

	system("pause");
	return EXIT_SUCCESS;
}