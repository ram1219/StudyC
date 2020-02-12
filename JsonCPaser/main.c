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
#include <stdbool.h>

#define TOKEN_COUNT   20   // ��ū�� �ִ� ����

// ��ū ���� ������
typedef enum _TOKEN_TYPE TOKEN_TYPE;
// ��� ����ü
typedef struct _TOKEN TOKEN;
// JSON ����ü
typedef struct _JSON JSON;

enum _TOKEN_TYPE {
    TOKEN_STRING,   // ���ڿ� ��ū
    TOKEN_NUMBER   // ���� ��ū
};

struct _TOKEN {
    TOKEN_TYPE type;   // ��ū ����
    // �� ������ �� ������ �����Ұ��̹Ƿ� ����ü ���
    union {
        char* string;   // ���ڿ� ������
        double number;   // �Ǽ��� ����
    };
    bool isArray;      // ���� ��ū�� �迭���� ǥ��
};

struct _JSON {
    TOKEN tokens[TOKEN_COUNT];   // ��ū �迭
};

// JSON������ �а� ����� ������ �ּҸ� �����Ѵ�.
char* readFile(char* filename, int* readSize);
// JSON �Ľ� �Լ�
void parseJSON(char* doc, int size, JSON* json);
// JSON ���� �Լ�
void freeJSON(JSON* json);

// �����Լ�
int main(void)
{
    int size;   // ���� ������ ����
    char* doc = readFile("Example.json", &size);   // ������ �а� ���۸� �����´�.

    // �Ѱܹ��� ���۰� ���ٸ� ���α׷��� �����Ѵ�.
    if (doc == NULL) { return EXIT_FAILURE; }

    JSON json = { 0 };   // JSON ����ü ���� ���� �� �ʱ�ȭ

    // ���� JSON�� �Ľ�
    parseJSON(doc, size, &json);

    int i = 0;
    while (true) {
        // ���� ���ڿ��� ���ٸ� �ݺ����� Ż���Ѵ�.
        if (json.tokens[i].string == NULL) { break; }

        // ���� JSON�� ����Ѵ�.
        printf("%s : %s\n", json.tokens[i].string, json.tokens[i + 1].string);

        i += 2;   // 2���� ��ū�� ����ϹǷ� 2ĭ �Ѿ��.
    }

    freeJSON(&json);   // json�� �Ҵ�� ���� �޸� ����
    free(doc);         // ���� ���� �޸� ����

    system("pause");
    return EXIT_SUCCESS;
}

char* readFile(char* filename, int* readSize)
{
    FILE* file = fopen(filename, "rb");
    if (file == NULL) { return NULL; }

    int size;      // ������ ũ��
    char* buffer;   // ���� ������ ������ ���� ����


    // ������ ũ�⸦ ���Ѵ�
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // ����ũ�� + \0 ������ŭ �Ҵ��ϰ� �ʱ�ȭ�Ѵ�.
    buffer = calloc(sizeof(char), size + 1);

    // ������ �������а� ���ۿ� ��´�
    if (fread(buffer, size, 1, file) < 1)
    {
        // ���� ������ ���ٸ� ���۸� ����, ���������͵� �ݴ´�.
        *readSize = 0;
        free(buffer);
        fclose(file);
        return NULL;
    }

    *readSize = size;
    fclose(file);

    return buffer;
}

void parseJSON(char* doc, int size, JSON* json)
{
    int tokenIndex = 0;   // ��ū �ε���
    int pos = 0;      // ������ ��ġ�� ����

    // JSON�� ���������� �´��� Ȯ���Ѵ�.
    if (doc[pos] != '{') { return; }

    pos++;   // ���� ���ڷ� �Ѿ��.

    // JSON ������ ũ�⸸ŭ �ݺ��Ѵ�.
    while (pos < size)
    {
        // ������ ������ ���� �б��Ѵ�.
        switch (doc[pos])
        {
        case '"':   // ���ڰ� "�̸� ���ڿ�
        {
            char* begin = doc + pos + 1;   // ���ڿ��� ������ġ, �� ���� "�� �����ϱ� ���� + 1
            char* end = strchr(begin, '"');   // ���ڿ��� �� ��ġ�� ���Ѵ� ��, ���� "��ġ

            // "�� ������ �������� �̹Ƿ� �ݺ�����
            if (end == NULL) { break; }

            int stringLength = end - begin;   // ���ڿ��� ���� = ����ġ - ���� ��ġ

            // ��ū �迭�� ���ڿ��� �����ϰ� Ÿ���� ����
            json->tokens[tokenIndex].type = TOKEN_STRING;
            json->tokens[tokenIndex].string = calloc(1, stringLength + 1);
            memcpy(json->tokens[tokenIndex].string, begin, stringLength);

            tokenIndex++;               // ��ū�� ���������Ƿ� �ε����� �ű��.
            pos = pos + stringLength + 1;   // ������ġ + ���ڿ� ���� + 1(")
        }
        break;
        default:
            break;
        }

        pos++;   // ���� ���ڷ� �Ѿ��.
    }


}

void freeJSON(JSON* json)
{
    // ��ū�� ���� ��ŭ �ݺ��Ѵ�
    for (int i = 0; i < TOKEN_COUNT; i++)
    {
        // ��ū�� ������ ���ڿ��� ���
        if (json->tokens[i].type == TOKEN_STRING)
        {
            // �Ҵ�� ���ڿ��� �����Ѵ�
            free(json->tokens[i].string);
        }
    }
}
