extern int count;					// main.c �� count ����
extern int total;					// input.c �� total�� ����
									// main.c�� total�� static���� ����Ǿ����Ƿ� extern �� �� ����.

double average(void) {

	return total / (double)count;
}