int main() {
	run3();
}

void run1() {
	int i, k;
	
	#pragma omp parallel
	{
		#pragma omp for private(i) lastprivate(k)
		for(i=0; i<10; i++)
		k = i*i;
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
	#pragma omp parallel firstprivate(a)
	{
		myid = omp_get_thread_num();
		printf("Thread%d: a = %d\n", myid, a);
		a = myid;
		printf("Thread%d: a = %d\n", myid, a);
	}
}
