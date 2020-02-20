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
int main() 
{
    int numarr[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };

    int size = sizeof(numarr) / sizeof(int);
    int start = 0, end = size - 1;
    int L = start, R = end;
    int pivot = (int)((end - start) / 2.0);

    while (1) {
        // L == R 때까지 반복
        while (L < R) {
            // L이 pivot보다 크거나 같으면 탈출
            while (L < pivot) { L++; }
            // R이 pivot보다 작으면 탈출
            while (R >= pivot) { R--; }
        }
    }
}