/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
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

// 메인함수
int main(void) 
{
    write_json();

	system("pause");
	return EXIT_SUCCESS;
}

void read_json() {
    JSON_Value* rootValue;
    JSON_Object* rootObject;

    rootValue = json_parse_file("package.json");            // Json 파일 로드, 초기화
    rootObject = json_value_get_object(rootValue);          // Json_Value에서 Json_Object를 획득

    printf("name : %s\n", json_object_get_string(rootObject, "name"));
    printf("version : %s\n", json_object_get_string(rootObject, "version"));
    printf("repo : %s\n", json_object_get_string(rootObject, "repo"));
    printf("description : %s\n", json_object_get_string(rootObject, "description"));
    printf("license : %s\n", json_object_get_string(rootObject, "license"));

    // json파일에서 숫자 가져오기
    printf("temp : %.1lf\n", (double)json_object_get_number(rootObject, "temp"));

    // json파일에서 배열 가져오기
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

    // JSON_value에 할당된 동적 메모리 해제
    json_value_free(rootValue);
}

void write_json(void) {
    JSON_Value* rootValue;
    JSON_Object* rootObject;

    rootValue = json_value_init_object();
    rootObject = json_value_get_object(rootValue);

    // rootObject에 "Title"키를 추가하고 문자열 데이터 저장
    json_object_set_string(rootObject, "Title", "Interstellar");

    // 숫자 데이터 저장
    json_object_set_number(rootObject, "Year", 2014);
    json_object_set_number(rootObject, "Runtime", 169);

    json_object_set_string(rootObject, "Genre", "Sci-Fi");
    json_object_set_string(rootObject, "Director", "Christopher Nolan");

    // 키를 추가하고 배열 생성
    json_object_set_value(rootObject, "Actors", json_value_init_array());

    // 객체에서(rootObject) 배열 포인터를 가져온다
    JSON_Array* actors = json_object_get_array(rootObject, "Actors");

    // 배열에 문자열 요소 추가
    json_array_append_string(actors, "Matthew Mcconaughey");
    json_array_append_string(actors, "Anne Hathaway");
    json_array_append_string(actors, "Michael Caine");
    json_array_append_string(actors, "Jessica Chastain");
    json_array_append_string(actors, "Casey Affleck");

    // bool 추가
    json_object_set_boolean(rootObject, "Koreareleas", 1);

    // JSON_Value에 저장된 값들을 문자로 변환하여 saved.json에 저장
    json_serialize_to_file_pretty(rootValue, "saved.json");

    //JSON_Value에 할당된 동적 메모리 해제
    json_value_free(rootValue);
}
