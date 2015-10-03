#include <stdio.h>
#include <time.h>

extern int fibonacci(int x);

int main(int argc, char *argv[])
{
  int number=0;
  int result=0;

  scanf("%d",&number);

  clock_t start = clock();
  result = fibonacci(number); 
  clock_t end = clock();
  
  FILE *ofile = fopen("fib-non_recursive.txt", "a");
  double time = (double)(end-start)/CLOCKS_PER_SEC;
  fprintf(ofile, "%d\t%f\n", number, time*1000);
  fclose(ofile);

  printf("The fibonacci sequence at %d is: %d\n", number, result);

  return 0;
}


