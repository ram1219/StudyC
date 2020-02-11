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
#define PI 3.14159
#define LIMIT 100.0
#define MSG "passed!"
#define ERR_PRN printf("허용 범위를 벗어났습니다!\n")

// 메인함수
int main(void) 
{
    double radius, area;

    printf("반지름을 입력하세요(10 이하) : ");
    scanf("%lf", &radius);

    area = PI * radius * radius;

    if (area > LIMIT) { ERR_PRN; }
    else { printf("원의 면적 : %.2lf (%s) \n", area, MSG); }

	system("pause");
	return EXIT_SUCCESS;
}