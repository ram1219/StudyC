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

#include "parson.h"

void read_json(void);
void write_json(void);

// �����Լ�
int main(void) 
{
    write_json();

	system("pause");
	return EXIT_SUCCESS;
}

void read_json() {
    JSON_Value* rootValue;
    JSON_Object* rootObject;

    rootValue = json_parse_file("package.json");            // Json ���� �ε�, �ʱ�ȭ
    rootObject = json_value_get_object(rootValue);          // Json_Value���� Json_Object�� ȹ��

    printf("name : %s\n", json_object_get_string(rootObject, "name"));
    printf("version : %s\n", json_object_get_string(rootObject, "version"));
    printf("repo : %s\n", json_object_get_string(rootObject, "repo"));
    printf("description : %s\n", json_object_get_string(rootObject, "description"));
    printf("license : %s\n", json_object_get_string(rootObject, "license"));

    // json���Ͽ��� ���� ��������
    printf("temp : %.1lf\n", (double)json_object_get_number(rootObject, "temp"));

    // json���Ͽ��� �迭 ��������
    JSON_Array* array = json_object_get_array(rootObject, "keywords");

    printf("keywords :\n");
    for (int i = 0; i < json_array_get_count(array); i++) {
        printf(" %s\n", json_array_get_string(array, i));
    }

    JSON_Array* Array = json_object_get_array(rootObject, "src");

    printf("src :\n");
    for (int i = 0; i < json_array_get_count(Array); i++) {
        printf(" %s\n", json_array_get_string(Array, i));
    }

    // JSON_value�� �Ҵ�� ���� �޸� ����
    json_value_free(rootValue);
}

void write_json(void) {
    JSON_Value* rootValue;
    JSON_Object* rootObject;

    rootValue = json_value_init_object();
    rootObject = json_value_get_object(rootValue);

    // rootObject�� "Title"Ű�� �߰��ϰ� ���ڿ� ������ ����
    json_object_set_string(rootObject, "Title", "Interstellar");

    // ���� ������ ����
    json_object_set_number(rootObject, "Year", 2014);
    json_object_set_number(rootObject, "Runtime", 169);

    json_object_set_string(rootObject, "Genre", "Sci-Fi");
    json_object_set_string(rootObject, "Director", "Christopher Nolan");

    // Ű�� �߰��ϰ� �迭 ����
    json_object_set_value(rootObject, "Actors", json_value_init_array());

    // ��ü����(rootObject) �迭 �����͸� �����´�
    JSON_Array* actors = json_object_get_array(rootObject, "Actors");

    // �迭�� ���ڿ� ��� �߰�
    json_array_append_string(actors, "Matthew Mcconaughey");
    json_array_append_string(actors, "Anne Hathaway");
    json_array_append_string(actors, "Michael Caine");
    json_array_append_string(actors, "Jessica Chastain");
    json_array_append_string(actors, "Casey Affleck");

    // bool �߰�
    json_object_set_boolean(rootObject, "Koreareleas", 1);

    // JSON_Value�� ����� ������ ���ڷ� ��ȯ�Ͽ� saved.json�� ����
    json_serialize_to_file_pretty(rootValue, "saved.json");

    //JSON_Value�� �Ҵ�� ���� �޸� ����
    json_value_free(rootValue);
}
