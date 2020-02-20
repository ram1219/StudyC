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

int i = 0;                          // �� ������ �ݺ� Ƚ��

typedef int element;                // int�� �����ϴ� ����ü
int size;                           // �迭 ũ�� 


// �־��� �κ����� �ȿ��� �Ǻ� ��ġ�� Ȯ���Ͽ� ���� ��ġ�� ���ϴ� ����
int partition(element a[], int begin, int end){
    int pivot, L, R;
    element temp;                                // �� �ӽ� ����
    L = begin;
    R = end;
    pivot = (int)((begin + end) / 2.0);         // �迭�� ��� ���� pivot���� ����

    printf("\n[ %d�ܰ� : pivot = %d ]\n", ++i, a[pivot]);

    // L�� R�� ������ ���� ������ �ݺ��ؼ� ����
    while (L < R) {
        // L�� ���� pivot�� ������ ���� �� ������ ����
        while ((a[L] < a[pivot]) && (L < R)) { L++; }

        // R�� ���� pivot�� ������ Ŭ �� ������ ����
        while ((a[R] >= a[pivot]) && (L < R)) { R--; }

        // L == R �� �� ��� �������� ����
        if (L < R) {
            temp = a[L];
            a[L] = a[R];
            a[R] = temp;

            if (L == pivot) { pivot = R; }
        }
    }

    // L == R�� ���� ���
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
        // partition�Լ����� ������ R���� p�� ����
        p = partition(a, begin, end);

        quickSort(a, begin, p - 1);
        quickSort(a, p + 1, end);
    }
}

// �����Լ�
int main() {
    element list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
    size = 8;

    printf("\n [ �ʱ� ���� ] \n");
    for (int i = 0; i <= size - 1; i++) { printf(" %d", list[i]); }
    printf("\n");

    quickSort(list, 0, size - 1);
}
