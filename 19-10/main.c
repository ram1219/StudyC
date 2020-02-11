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

//#include "point.h"            // line.h 에도 point.h가 선언되어 있으므로 헤더의 중복이 발생한다.
#include "line.h"               

// 메인함수
int main(void) 
{
    Line a = { {1,2},{5,6} };
    Point b;

    b.x = (a.first.x + a.second.x) / 2;
    b.y = (a.first.y + a.second.y) / 2;
    printf("선의 가운데 정의 좌표 : (%d, %d)\n", b.x, b.y);

	system("pause");
	return EXIT_SUCCESS;
}