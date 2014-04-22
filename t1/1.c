#include <omp.h>

int main() {
	int i;
	for (i = 0; i < 100; i++)
		run1();
}

void run1() {
	int i, k;
	
	#pragma omp parallel
	{
		k=0;
		#pragma omp for private(i) firstprivate(k) lastprivate(k) 
			for(i=0; i<1; i++)
				k = k + i;
		
	}
	printf("k = %d\n", k);
}

void run2() {
	int i, k;
	
	#pragma omp parallel
	{
		#pragma omp for private(k)
		for(i=0; i<100; i++)
		k = i*i;
	}
	printf("k = %d\n", k);
}

void run3() {
	int myid, a;
	a = 10;
	#pragma omp parallel default(shared) firstprivate(a)
	{
		myid = omp_get_thread_num();
		printf("Thread%d: a = %d\n", myid, a);
		a = myid;
		printf("Thread%d: a = %d\n", myid, a);
	}
}
