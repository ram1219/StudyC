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
    FILE* fp;
    char str[20];

    fp = fopen("a.txt", "a+");                          // 텍스트 파일을 읽거나 파일의 끝에 추가하기 위해 개방

    if (fp == NULL) {
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }

    while (1) {
        printf("과일 이름 : ");
        scanf("%s", str);

        if (strcmp(str, "end") == 0) {
            break;
        }
        else if (strcmp(str, "list") == 0) {
            rewind(fp);                               // fseek 와 비슷한 기능. 
                                                      //위치지시자 이동을 사용하지 않으면 rewind를 사용하는 것이 더 낫다.

            //fseek(fp, 0, SEEK_SET);                 // 파일의 처음(SEEK_SET)부터 0만큼 위치지시자를 이동
                                                      // 양수만 가능 --> y방향 이동
            while (1) {
                fgets(str, sizeof(str), fp);

                if (feof(fp)) { break; }            // feof(file end of file) 파일의 내용을 모두 읽으면 종료
                printf("%s", str);
            }
        }
        else {
            fprintf(fp, "%s\n", str);               // 입력받은 값을 파일에 출력
        }
    }
    fclose(fp);

	system("pause");
	return EXIT_SUCCESS;
}