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

struct Student_t {
    int kor;
    int eng;
    int math;
};

int KorSum(struct Student_t s1, struct Student_t s2, struct Student_t s3);
int engSum(struct Student_t s1, struct Student_t s2, struct Student_t s3);
int mathSum(struct Student_t s1, struct Student_t s2, struct Student_t s3);

// �����Լ�
int main(void) 
{
    struct Student_t s1;
    struct Student_t s2;
    struct Student_t s3;

    printf("�л� 3���� ������� �Է��ϼ���. : ");
    scanf("%d%d%d", &s1.kor, &s2.kor, &s3.kor);

    printf("�л� 3���� ������� �Է��ϼ���. : ");
    scanf("%d%d%d", &s1.eng, &s2.eng, &s3.eng);

    printf("�л� 3���� ���м����� �Է��ϼ���. : ");
    scanf("%d%d%d", &s1.math, &s2.math, &s3.math);

    printf("���� ������ �� : %d, ��� : %.1lf\n", KorSum(s1, s2, s3), KorSum(s1, s2, s3) / 3.0);
    printf("���� ������ �� : %d, ��� : %.1lf\n", engSum(s1, s2, s3), engSum(s1, s2, s3) / 3.0);
    printf("���� ������ �� : %d, ��� : %.1lf\n", mathSum(s1, s2, s3), mathSum(s1, s2, s3) / 3.0);

    
	system("pause");
	return EXIT_SUCCESS;
}

int KorSum(struct Student_t s1, struct Student_t s2, struct Student_t s3) {

    return s1.kor + s2.kor + s3.kor;
}

int engSum(struct Student_t s1, struct Student_t s2, struct Student_t s3) {

    return s1.eng + s2.eng + s3.eng;
}

int mathSum(struct Student_t s1, struct Student_t s2, struct Student_t s3) {

    return s1.math + s2.math + s3.math;
}
