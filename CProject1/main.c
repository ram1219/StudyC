#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <Windows.h>

typedef struct _finddata_t FILE_SEARCH;

void GetfileList(char* path);

typedef struct File_ {
	char* fa;
};


int main(void)
{
	int i = 0;
	char* path = "D:\\document";
	
	

	GetfileList(path);



	return EXIT_SUCCESS;
}

void GetfileList(char* path) {

	long h_file;
	int i = 0;
	char search_Path[100];
	char c = 0;

	FILE_SEARCH file_search;

	struct File_ fi;

	while (1) {

		sprintf_s(search_Path, 100, "%s\\*.*", path);

		if ((h_file = _findfirst(search_Path, &file_search)) == -1L) {
			printf("No files in current directory!\n");
		}
		else {
			do {					
				if (strcmp(strrchr(&file_search.name, '.'), ".txt") == 0) {
					fi.fa = file_search.name;
					i++;

					sprintf_s(search_Path, 100, "%s\\%s", path, fi.fa);
					FILE* fp = fopen(search_Path, "rt");

					if (fp == NULL) {
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

			} while (_findnext(h_file, &file_search) == 0);

			_findclose(h_file);
		
		}	
	}
}



