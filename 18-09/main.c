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
    char name[20];
    int kor, eng, math;
    int total;
    double avg;
    int res;

    ifp = fopen("a.txt", "r");
    if (ifp == NULL) {
        printf("입력 파일을 열지 못했습니다.\n");
        return 1;
    }

    ofp = fopen("b.txt", "w");
    if (ofp == NULL) {
        printf("출력 파일을 열지 못했습니다.\n");
        return 1;
    }

    while (1) {
        res = fscanf(ifp, "%s%d%d%d%d", name, &kor, &eng, &math);         // a.txt(ifp) 에서 데이터 가져와서 각 변수에 저장
        if (res == EOF) { break; }                                        // 한 줄씩 데이터를 가져온다.

        total = kor + eng + math;
        avg = total / 3.0;
        fprintf(ofp, "%s%5d%7.1lf\n", name, total, avg);
    }

    fclose(ifp);
    fclose(ofp);

	system("pause");
	return EXIT_SUCCESS;
}