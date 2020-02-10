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
    FILE* ifp, * ofp;
    char str[80];
    char* res;

    ifp = fopen("a.txt", "r");                                      // �̸� ������ �� a.txt ���� ����
    if (ifp == NULL) {
        printf("�Է� ������ ���� ���߽��ϴ�.\n");
        return 1;
    }

    ofp = fopen("b.txt", "w");                                      // ���� �ۼ��ϱ� ���� b.txt ���� ���� �� ����
    if (ofp == NULL) {
        printf("��� ������ ���� ���߽��ϴ�.\n");
        return 1;
    }
                                                                
    while (1) {                                                 // Monkey likes ---- 1��, banana ---- 2��
        res = fgets(str, sizeof(str), ifp);

        if (res == NULL) { break; }
        str[strlen(str) - 1] = '\0';                            // '\n' �κ��� ����� '\0' �� �־ ���峡����
        fputs(str, ofp);
        fputs(" ", ofp);                                        // " " �� ��, �Ʒ��� �ִ� ������ �̾ ���̱�
    }

    fclose(ifp);
    fclose(ofp);

	system("pause");
	return EXIT_SUCCESS;
}