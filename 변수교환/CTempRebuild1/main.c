/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------
  first created - 2020.02.01
  writer - Hugo MG Sung.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �����Լ�
int main(void) 
{
    char I_string[20];
    printf("���ڿ��� �Է��ϼ��� : ");
    scanf("%s", I_string);

    int Upper = 0;                          //�빮��
    int Lower = 0;                          //�ҹ���
    int num = 0;                            //����
    int S_charater = 0;                     //Ư������

    for (int i = 0; i < strlen(I_string); i++) {
        if ('0' <= I_string[i] && I_string[i] <= '9') { num++; }
        else if ('a' <= I_string[i]&& I_string[i] <= 'z') { Lower++; }
        else if ('A' <= I_string[i] && I_string[i] <= 'Z') { Upper++; }
        else { S_charater++; }
    }

    printf("%s���� �빮�� : %d, �ҹ��� : %d, ���� : %d, Ư������ : %d\n", I_string, Upper, Lower, num, S_charater);
}