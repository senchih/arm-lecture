#include <stdio.h>
#include <time.h>

unsigned int fibonacci(unsigned int n);

int main(int argc, char *argv[]){
	unsigned int i;
	unsigned int k;
	for (i = 0; i <= 40; i++){
		clock_t start = clock();
		k = fibonacci(i);
		clock_t end = clock();
		printf("%d\n", k);
		FILE *ofile = fopen("fib-non_recursive.txt", "a");
		double time = (double)(end-start)/CLOCKS_PER_SEC*1000000;
		fprintf(ofile, "%d\t%f\n", i, time);
		fclose(ofile);
	}
	return 0;
}

unsigned int fibonacci(unsigned int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	int i;
	int a, b;
	unsigned int k;
	a = 1; b = 0;
	for(i=1; i <= n; i++){
		k = a + b;
		b = a;
		a = k;
	}
	return k;
}
