#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "CalHeader.h"

int get_total(int* data, int size) {
	int res = 0;

	for (int i = 0; i < size; i++) {
		res += data[i];
	}

	return res;
}