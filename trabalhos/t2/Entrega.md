#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

typedef struct 
 {
   double *a;
   double *b;
   double c; 
   int wsize;
   int repeat; 
 } dotdata_t;

// Variavel Global
dotdata_t dotdata;


void dotprod_worker(void *arg)
{
   int i, k;
   long offset = (long) arg;
   double *a = dotdata.a;
   double *b = dotdata.b;     
   int wsize = dotdata.wsize;
   int start = offset*wsize;
   int end = start + wsize;
   double mysum;
   #pragma omp parallel for
   for (k = 0; k < dotdata.repeat; k++) {
      mysum = 0.0;
      for (i = start; i < end ; i++)  {
         mysum += (a[i] * b[i]);
      }
   }

   #pragma opm critical(Somas){
   dotdata.c += mysum;
   }
}

/*
 * Preenche vetor
 */ 
void fill(double *a, int size, double value)
{  
   int i;
   for (i = 0; i < size; i++) {
      a[i] = value;
   }
}

int main(int argc, char **argv)
{
   int nthreads, wsize, repeat;
   long start_time, end_time;

   if ((argc != 4)) {
      printf("Uso: %s <nthreads> <worksize> <repetitions>\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   nthreads = atoi(argv[1]); 
   wsize = atoi(argv[2]);  // worksize = tamanho do vetor de cada thread
   repeat = atoi(argv[3]); // numero de repeticoes dos calculos (para aumentar carga)

   // Cria vetores
   dotdata.a = (double *) malloc(wsize*nthreads*sizeof(double));
   fill(dotdata.a, wsize*nthreads, 0.01);
   dotdata.b = (double *) malloc(wsize*nthreads*sizeof(double));
   fill(dotdata.b, wsize*nthreads, 1.0);
   dotdata.c = 0.0;
   dotdata.wsize = wsize;
   dotdata.repeat = repeat;

   double start_time = omp_get_wtime();
   dotprod_worker(arg);
   double end_time = omp_get_wtime();

   // Mostra resultado e estatisticas da execucao
   printf("%f\n", dotdata.c);
   printf("%d thread(s), %ld usec\n", nthreads, (long) (end_time - start_time));
   fflush(stdout);

   free(dotdata.a);
   free(dotdata.b);

   return EXIT_SUCCESS;
}
