#include <stdio.h>
#include <time.h>

unsigned int fibonacci_recursive(unsigned int n);

int main(int argc, char *argv[]){
	unsigned int i;
	unsigned int k;
	for (i = 0; i <= 40; i++){
		clock_t start = clock();
		k = fibonacci_recursive(i);
		clock_t end = clock();
		printf("%d\n", k);
		FILE *ofile = fopen("fib-recursive.txt", "a");
		double time = (double)(end-start)/CLOCKS_PER_SEC*1000;
		fprintf(ofile, "%d\t%f\n", i, time);
		fclose(ofile);
	}
	return 0;
}

unsigned int fibonacci_recursive(unsigned int n){
	if(n == 0) return 0;
     if(n == 1) return 1;
	return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}
