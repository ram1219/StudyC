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

struct vision {
    double left;
    double right;
};

struct vision exchange(struct vision robot);

// �����Լ�
int main(void) 
{
    struct vision robot;

    printf("�÷� �Է� : ");
    scanf("%lf%lf", &(robot.left), &(robot.right));

    robot = exchange(robot);
    printf("�ٱ� �÷� : %.1lf  %.1lf\n", robot.left, robot.right);

	system("pause");
	return EXIT_SUCCESS;
}

struct vision exchange(struct vision robot) {
    double temp;

    temp = robot.left;
    robot.left = robot.right;
    robot.right = temp;

    return robot;
}