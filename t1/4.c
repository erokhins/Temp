#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

const int size = 1000;


int nowM() {
	struct timeval  tv;
	gettimeofday(&tv, NULL);

	double a = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;
}

void main() {
	const float A[size][size];
	
	
	srand ( time(NULL) );
	rand();
	printf("%d\n", rand());
	printf("%f\n", nowM());
}
