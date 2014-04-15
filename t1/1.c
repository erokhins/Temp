int main() {
	int i, k;
	
	#pragma omp parallel
	{
		#pragma omp for private(i) lastprivate(k)
		for(i=0; i<10; i++)
		k = i*i;
	}
	printf("k = %d\n", k);
}


void for1(float a[], float b[], int n)
{

  int i, j;

  #pragma omp parallel shared(a,b,n)

  {

   #pragma omp for schedule(dynamic,1) private (i,j) nowait

    for (i = 1; i < n; i++)

       for (j = 0; j < i; j++)

         b[j + n*i] = (a[j + n*i] + a[j + n*(i-1)]) / 2.0;

  }

}
