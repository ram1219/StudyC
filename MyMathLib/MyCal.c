#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include "Mycalc.h"

#ifdef __cplusplus
extern "C" {
#endif

_declspec(dllexport) int int_add(int a, int b) { return a + b; }

_declspec(dllexport) int int_multi(int a, int b) { return a * b; }

#ifdef __cplusplus
}
#endif

