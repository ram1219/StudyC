#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <Windows.h>
#include <conio.h> 

typedef struct _finddata_t FILE_SEARCH;

void GetfileList(char* path);


int main(void)
{
	int i = 0;
	char* path = "D:\\document";
	
	GetfileList(path);


	return EXIT_SUCCESS;
}
void GetfileList(char* path) {

	long h_file;

	int icount = 0;
	char *SaveName[100];
	char* tmpName;

	int iBool = 0;

	char search_Path[100];
	char c = 0;
	char* fa;

	FILE_SEARCH file_search;

	while (1)
	{
		if (_kbhit())						// ���ѷ��� ����
		{
			if (getch() == 'z')
				break;
		}

		sprintf_s(search_Path, 100, "%s\\*.*", path);						// fopen���� ����� ��� ����

		if ((h_file = _findfirst(search_Path, &file_search)) == -1L) {		// ������ ���� ���
			printf("No files in current directory!\n");
		}

		else {
			do {

				if (strcmp(strrchr(&file_search.name, '.'), ".txt") == 0) {	// txt���ϸ� ��󳻱�
					fa = file_search.name;							// ���� �̸� ����

					if (icount == 0) { 
						SaveName[icount] = fa;
					}

					for (int i = 0; i < icount; i++) {
														
						if (&SaveName[i] == fa) {
							iBool = 0;
							break;
						}
						else {
							iBool = 1;
						}
							
					}
					if (iBool == 1) {
						SaveName[icount] = fa;
						iBool = 0;
					}

					for (int i = 0; i <= icount; i++) {
						if (i == icount) {
							sprintf_s(search_Path, 100, "%s\\%s", path, SaveName[i]);
							FILE* fp = fopen(search_Path, "rt");

							if (fp == NULL) {										// �� ������ ���
								return;
							}

							while (c != EOF)
							{
								c = fgetc(fp);
								putchar(c);
							}
							fclose(fp);

							c = 0;
							printf("\n\n");
							Sleep(1000);
	
						}
					}
					icount++;
				}

			} while (_findnext(h_file, &file_search) == 0);

			_findclose(h_file);
		}
	}
}



