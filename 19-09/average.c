extern int count;					// main.c 의 count 공유
extern int total;					// input.c 의 total을 공유
									// main.c의 total은 static으로 선언되었으므로 extern 할 수 없다.

double average(void) {

	return total / (double)count;
}