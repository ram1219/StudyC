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
int main(void) 
{
    FILE* ifp, * ofp;
    char str[80];
    char* res;

    ifp = fopen("a.txt", "r");                                      // 미리 생성해 둔 a.txt 파일 오픈
    if (ifp == NULL) {
        printf("입력 파일을 열지 못했습니다.\n");
        return 1;
    }

    ofp = fopen("b.txt", "w");                                      // 새로 작성하기 위해 b.txt 파일 생성 후 오픈
    if (ofp == NULL) {
        printf("출력 파일을 열지 못했습니다.\n");
        return 1;
    }
                                                                
    while (1) {                                                 // Monkey likes ---- 1번, banana ---- 2번
        res = fgets(str, sizeof(str), ifp);

        if (res == NULL) { break; }
        str[strlen(str) - 1] = '\0';                            // '\n' 부분을 지우고 '\0' 을 넣어서 문장끝내기
        fputs(str, ofp);
        fputs(" ", ofp);                                        // " " 한 후, 아래에 있던 내용을 이어서 붙이기
    }

    fclose(ifp);
    fclose(ofp);

	system("pause");
	return EXIT_SUCCESS;
}