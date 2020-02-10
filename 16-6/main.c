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

// 메인함수
int main(int argc, char** argv) 
{
    // 프로젝트 - 속성 - 디버깅 - 명령 인수에 입력한 값이 없을 경우 if실행
    if (argc <= 1) {
        printf("명령 구문이 올바르지 않습니다.\n");
        exit(1);
    }

    char* intarg[2];
    int j = 0;

    for (int i = 0; i < argc; i++) {
        if (i == 0) { continue; }       // 0번째는 프로그램의 이름
        intarg[j] = (char*)malloc(strlen(argv[i]) + 1);
        strcpy(intarg[j], argv[i]);
    }

    printf("첫번째 명령 인수 :%s\n", intarg[0]);
    printf("두번째 명령 인수 :%s\n", intarg[1]);

    for (int i = 0; i < argc; i++) {
        free(intarg[i]);
    }
	system("pause");
	return EXIT_SUCCESS;
}