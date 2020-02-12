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
#include <my_global.h>
#include <WinSock2.h>
#include <mysql.h>

#pragma comment (lib, "libmysql.lib")

#define MYSQLUSER "root"
#define MYSQLPASSWORD "mysql_p@ssw0rd"
#define MYSQLIP "localhost"

void loadmysql(char mysqlip[], MYSQL* cons);

// �����Լ�
int main(void) 
{
    //printf("MySQL info is %s\n", mysql_get_client_info());

    MYSQL* cons = mysql_init(NULL);                 // MYSQL ���� �ʱ�ȭ
    MYSQL_RES* res;
    MYSQL_ROW row;
    int fields;

    loadmysql(MYSQLIP, cons);
    printf("\n");

    mysql_query(cons, "use shopdb;");                     
    mysql_query(cons, "SELECT * FROM membertbl;");
    res = mysql_store_result(cons);
    fields = mysql_num_fields(res);

    // ���� �����ͼ� �Ѹ��� ���� ����
    while (row = mysql_fetch_row(res)) {
        for (int i = 0; i < fields; i++) {
            printf("%s", row[i]);
            if (i < fields) { printf("\t"); }
        }
        printf("\n");
    }
    printf("\n");

    mysql_free_result(res);                 // ������ ����
    mysql_close(cons);

	system("pause");
	return EXIT_SUCCESS;
}

void loadmysql(char mysqlip[], MYSQL* cons) {
    if (cons == NULL) {
        fprintf(stderr, "%s\n", mysql_error(cons));
        Sleep(1000);
        exit(1);
    }

    if (!(mysql_real_connect(cons, MYSQLIP, MYSQLUSER, MYSQLPASSWORD, NULL, 0, NULL, 0) == NULL)) {
        printf("\n����\n");       
        mysql_set_character_set(cons, "euckr");
    }
    else {
        fprintf(stderr, "���� ���� : %s\n", mysql_error(cons));
        getchar();
    }
}