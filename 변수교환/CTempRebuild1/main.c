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
    char I_string[20];
    printf("문자열을 입력하세요 : ");
    scanf("%s", I_string);

    int Upper = 0;                          //대문자
    int Lower = 0;                          //소문자
    int num = 0;                            //숫자
    int S_charater = 0;                     //특수문자

    for (int i = 0; i < strlen(I_string); i++) {
        if ('0' <= I_string[i] && I_string[i] <= '9') { num++; }
        else if ('a' <= I_string[i]&& I_string[i] <= 'z') { Lower++; }
        else if ('A' <= I_string[i] && I_string[i] <= 'Z') { Upper++; }
        else { S_charater++; }
    }

    printf("%s에서 대문자 : %d, 소문자 : %d, 숫자 : %d, 특수문자 : %d\n", I_string, Upper, Lower, num, S_charater);
}