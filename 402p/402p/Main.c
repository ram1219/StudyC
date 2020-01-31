#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

int main() {

	char mark[5][5] = { 0 };
	int i, j;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (i == j) {
				mark[i][j] = 'X';
				printf("%c", mark[i][j]);
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}


	//system("pause");
	return 0;
}