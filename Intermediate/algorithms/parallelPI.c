#include <stdio.h>
#include <omp.h>

/*
 * DIOGO OLIVEIRA NEISS
 Oct 2019
  Parallel PI calculation using openMP
  
  To compíle you need to put -fopenmp
  
  Example: gcc file.c -o file -fopenmp
 
 */

long long strPrecision = 1000000000;
long double step;


int main(){
   int i;
   long double x, sum=0.0;
   long double pi;
	
	printf("Do you wish to do the calculation with a specified precision?\n");
	printf("[Y]/[N]\n");

	char answer = getchar();
	
	//answer form user
	if(answer == 'y' || answer == 'Y'){
		printf("Insert wished precision...\n");
		printf("It will be calculated in the form [1 / inserted precision]. \n");
		printf("Input: ");
		scanf("%lld", &strPrecision);
	}
	else
		printf("No precision specified. Going into default %10.lld\n", strPrecision);
	
	//step calculation
	step = 1.0 / strPrecision;	

	double inicio = omp_get_wtime();
	// to do sequencial you need to comment the below line
	#pragma omp parallel for private(x) reduction(+:sum)
 	for(i=0; i < strPrecision; i++){
  	 	x = (i + 0.5)*step;
   		sum = sum + 4.0/(1.0 + x*x);
 	}

   	pi = sum*step;

	double endExecution = omp_get_wtime();

   	printf("PI in the specified precision is: %.60Lf\n", pi);
	printf("Exec time: %f seconds\n", endExecution - inicio);
   
   return 0;
}
