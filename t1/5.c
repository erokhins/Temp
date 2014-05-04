#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>

long long current_timestamp() {
    struct timeval te; 
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // caculate milliseconds
    // printf("milliseconds: %lld\n", milliseconds);
    return milliseconds;
}

const int SIZE = 1000000;
const int module = 1000;
const int kk = 20;


int main() {
	long long ms;
	srand ( time(NULL) );

	int m[SIZE];
	int i;
	for (i = 0; i < SIZE; i++) {
		m[i] = rand() % module;
	}

	ms = current_timestamp();
	for (i = 0; i < kk; i++)
		mySum(m);
	printf("sum = %d\n", mySum2(m));
	printf("spend time: %lld\n", current_timestamp() - ms);

	
	ms = current_timestamp();
	for (i = 0; i < kk; i++)
		mySum2(m);
	printf("sum2 = %d\n", mySum2(m));
	printf("spend time: %lld\n", current_timestamp() - ms);

	ms = current_timestamp();
	for (i = 0; i < kk; i++)
		mySum3(m);
	printf("sum3 = %d\n", mySum3(m));
	printf("spend time: %lld\n", current_timestamp() - ms);
	
	ms = current_timestamp();
	for (i = 0; i < kk; i++)
		mySum4(m);
	printf("sum4 = %d\n", mySum4(m));
	printf("spend time: %lld\n", current_timestamp() - ms);
}


int mySum(int a[SIZE]) {
	int sum = 0; 
	int i;
	for (i = 0; i < SIZE; i++) {
		sum += a[i];
	}
	return sum;
}

int mySum2(int a[SIZE]) {
	int sum = 0;
	int i, j;
	#pragma omp parallel shared(sum, a) private(i) 
	{
		#pragma omp for 
		for (i = 0; i < SIZE; i++) {
			
			#pragma omp atomic
			sum += a[i];
		}
	}
	return sum;
}

int mySum3(int a[SIZE]) {
	int sum = 0;
	int i, j;
	#pragma omp parallel shared(sum, a) private(i) 
	{
		#pragma omp for 
		for (i = 0; i < SIZE; i++) {
			
			#pragma omp critical 
			{
				sum += a[i];
			}
		}
	}
	return sum;
}

int mySum4(int a[SIZE]) {
	int i,j;
	int sum1, sum2;
	
	#pragma omp parallel sections private(i, j) lastprivate(sum1, sum2)
	{
		#pragma omp section 
		{	
			sum1 = 0;
			for (i = 0; i < SIZE/2; i++) {
				sum1 += a[i];
			}
		}
		#pragma omp section 
		{	
			sum2 = 0;
			for (j = SIZE/2; j < SIZE; j++) {
				sum2 += a[j];
			}
		}
	}
	printf("s1 = %d\n", sum1);
	printf("s2 = %d\n", sum2);
	return sum1 + sum2;
}
