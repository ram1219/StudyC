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

char GetGrade(int num) {
    if (num <= 100 && num >= 90) {
        return 'A';
    }
    else if (num >= 70) {
        return 'B';
    }
    else if (num >= 60) {
        return 'C';
    }
    else if (num >= 50) {
        return 'D';
    }
    else {
        return 'F';
    }
}
// 메인함수
int main(void) 
{
    int num;

    printf("점수를 입력하세요 : ");
    scanf("%d", &num);

    if (num >= 0 && num <= 100) {
        printf("학점 : %c\n", GetGrade(num));
    }
    else {
        printf("1부터 100사이의 정수만 입력해주세요.\n");
    }
    printf("\n");
	system("pause");
	return EXIT_SUCCESS;
}