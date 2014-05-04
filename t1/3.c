const int N = 10;

void main() {
	int k = 0;
	int i, l, j, myid;
	#pragma omp parallel shared(l, k) 
	{
		int ID = //;
		if (ID == 0) {
			
			
		}
		
		
		#pragma omp for 
		for (i = 0; i < N; i++) {
			myid = omp_get_thread_num();
			printf("k=%d, i=%d, myid=%d\n", k, i, myid);
			
			#pragma omp atomic	
			k += i;
			printf("k=%d, i=%d\n", k, i);
		}
	}
	
	printf("result=%d, real=%d", k, N*(N-1)/2);
	
}
