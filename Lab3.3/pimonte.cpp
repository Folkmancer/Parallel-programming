#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define BLOCK_SIZE 500


int main(){
  unsigned int iter=200000000; 
  int i,j;
  double x, y;
  double dUnderCurve=0.0;
  double pi=0.0;

  double r[BLOCK_SIZE*2];          

  for (i=0; i<BLOCK_SIZE*2; i++)
  {
	  r[i]= (float)(rand()%100)/100.0;
  }

  double start_time = omp_get_wtime();

#pragma omp parallel shared(r, iter, pi)
  { 
	#pragma omp for private(j, i, x, y) reduction(+:dUnderCurve) 
	  for (j = 0; j < iter / BLOCK_SIZE; j++) {
		  for (i = 0; i < BLOCK_SIZE; i++) {
			  x = r[i];
			  y = r[i + BLOCK_SIZE];
			  if (x * x + y * y <= 1.0) {
				  dUnderCurve++;
			  }
		  }
	  }
	#pragma omp critical 
	  pi = dUnderCurve / (double)iter * 4;
  }
 
  double time = omp_get_wtime() - start_time;

  printf ("pi = %10.9f\n", pi);
  printf("Seconds = %10.9f\n", time);
  system("pause");
  return 0;
}
