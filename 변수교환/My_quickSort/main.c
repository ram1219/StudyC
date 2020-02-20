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
int main() 
{
    int numarr[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };

    int size = sizeof(numarr) / sizeof(int);
    int start = 0, end = size - 1;
    int L = start, R = end;
    int pivot = (int)((end - start) / 2.0);

    while (1) {
        // L == R ������ �ݺ�
        while (L < R) {
            // L�� pivot���� ũ�ų� ������ Ż��
            while (L < pivot) { L++; }
            // R�� pivot���� ������ Ż��
            while (R >= pivot) { R--; }
        }
    }
}