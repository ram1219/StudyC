#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

void my_gets(char* str, int size);

int main() {
	char str[7];

	my_gets(str, sizeof(str));
	printf("입력한 문자열 : %s\n", str);

	//system("pause");
	return 0;
}

void my_gets(char* str, int size) {
	int ch;
	int i = 0;

	ch = getchar();
	while ((ch != '\n') && (i < size - 1)) {
		str[i] = ch;
		i++;
		ch = getchar();
	}
	str[i] = '\0';
}