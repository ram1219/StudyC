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

int i = 0;                          // 퀵 정렬의 반복 횟수

typedef int element;                // int를 저장하는 구조체
int size;                           // 배열 크기 


// 주어진 부분집합 안에서 피봇 위치를 확정하여 분할 위치를 정하는 연산
int partition(element a[], int begin, int end){
    int pivot, L, R;
    element temp;                                // 값 임시 저장
    L = begin;
    R = end;
    pivot = (int)((begin + end) / 2.0);         // 배열의 가운데 값을 pivot으로 지정

    printf("\n[ %d단계 : pivot = %d ]\n", ++i, a[pivot]);

    // L과 R이 만나지 않을 때까지 반복해서 수행
    while (L < R) {
        // L의 값이 pivot의 값보다 작을 때 까지만 수행
        while ((a[L] < a[pivot]) && (L < R)) { L++; }

        // R의 값이 pivot의 값보다 클 때 까지만 수행
        while ((a[R] >= a[pivot]) && (L < R)) { R--; }

        // L == R 이 될 경우 수행하지 않음
        if (L < R) {
            temp = a[L];
            a[L] = a[R];
            a[R] = temp;

            if (L == pivot) { pivot = R; }
        }
    }

    // L == R이 됐을 경우
    temp = a[pivot];
    a[pivot] = a[R];
    a[R] = temp;

    for (int t = 0; t < size; t++) { printf(" %d", a[t]); }
    printf("\n");

    return R;
}

void quickSort(element a[], int begin, int end) {
    int p;

    if (begin < end) {
        // partition함수에서 리턴한 R값을 p에 저장
        p = partition(a, begin, end);

        quickSort(a, begin, p - 1);
        quickSort(a, p + 1, end);
    }
}

// 메인함수
int main() {
    element list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
    size = 8;

    printf("\n [ 초기 상태 ] \n");
    for (int i = 0; i <= size - 1; i++) { printf(" %d", list[i]); }
    printf("\n");

    quickSort(list, 0, size - 1);
}
