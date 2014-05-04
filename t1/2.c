const float matrix[5][5] = {
			{1, 2, 3, 4, 5},
			{16, 21, 5, 7, 2},
			{-5, 11, -15, -17, 22},
			{33, 11, 55, 17, 32},
			{44, -51, -71, 23, 25},
		};

const float m3[3][3] = {
			{3, 5, 7},
			{2, 6, 4},
			{0, 2, 8}
		};
	
float mAbs(float f) {
	if (f < 0)
		return -f;
	else
		return f;
}	
float norm1(int size, float m[size][size]);
float normB(int size, float m[size][size]);
	
int main() {
	run(3, m3);
	run(5, matrix);
}

void run(int size, float m[size][size]) {
	#pragma omp parallel shared(m, size) 
	{
		#pragma omp sections 
		{
			#pragma omp section 
			{
				float n1 = norm1(size, m);
				printf("n1 = %f\n", n1);
			}
			#pragma omp section 
			{
				float nB = normB(size, m);
				printf("nB = %f\n", nB);
			}
		}
	}	
}

void run2(int size, float m[size][size]) {
	float n1 = norm1(size, m);
	printf("n1 = %f\n", n1);
	float nB = normB(size, m);
	printf("nB = %f\n", nB);
}

float normB(int size, float m[size][size]) {
	float max = 0;
	int i;
	for (i = 0; i < size; i++) {
		float sum = 0;
		int j;
		for (j = 0; j < size; j++) {
			sum += mAbs(m[i][j]);
		}
		if (sum > max)
			max = sum;
	}
	return max;
}

float norm1(int size, float m[size][size]) {
	float max = 0;
	int i;
	for (i = 0; i < size; i++) {
		float sum = 0;
		int j;
		for (j = 0; j < size; j++) {
			sum += mAbs(m[j][i]);
		}
		if (sum > max)
			max = sum;
	}
	return max;
}
