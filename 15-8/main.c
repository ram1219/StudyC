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

void func(int (*fp)(int, int));
int sum(int a, int b);
int mul(int a, int b);
int Max(int a, int b);

// 메인함수
int main(void) 
{
    int sel;

    printf("01 두 정수의 합\n");
    printf("02 두 정수의 곱\n");
    printf("03 두 정수 중에서 큰 값 계산\n");
    printf("원하는 연산을 선택하세요 : ");

    scanf("%d", &sel);

    switch (sel) {
    case 1:
        func(sum);
        break;
    case 2:
        func(mul);
        break;
    case 3:
        func(Max);
        break;
    }
  
	system("pause");
	return EXIT_SUCCESS;
}

void func(int (*fp)(int, int)) {
    int a, b;
    int res;

    printf("두 정수의 값을 입력하세요 : ");
    scanf("%d%d", &a, &b);
    res = fp(a, b);
    printf("걸괏값은 : %d\n", res);
}

int sum(int a, int b) {
    return (a + b);
}

int mul(int a, int b) {
    return (a * b);
}

int Max(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}