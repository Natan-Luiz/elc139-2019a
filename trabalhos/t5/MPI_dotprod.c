/*
	Natan Luiz Paetzhold Berwaldt
			201710492
		Programação Paralela
			TRABALHO 5
*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "mpi.h"

typedef struct {
   double *a;
   double *b;
   double c;
   int wsize;
   int repeat;
} dotdata_t;

// Estrutura global
dotdata_t dotdata;

double dotprod_worker(int part)
{
   int i, k;
   long offset = part;
   double *a = dotdata.a;
   double *b = dotdata.b;
   int wsize = dotdata.wsize;
   int start = offset*wsize;
   int end = start + wsize;
   double mysum;

   for (k = 0; k < dotdata.repeat; k++) {
      mysum = 0.0;
      for (i = start; i < end ; i++)  {
         mysum += (a[i] * b[i]);
      }
   }
   return mysum;
}

/*
 * Tempo (wallclock) em microssegundos
 */
long wtime()
{
   struct timeval t;
   gettimeofday(&t, NULL);
   return t.tv_sec*1000000 + t.tv_usec;
}

/*
 * Preenche vetor
 */
void fill(double *a, int size, double value)
{
   for (int i = 0; i < size; i++) {
      a[i] = value;
   }
}

int main(int argc, char * argv[])
{
	int myrank;         // "rank" do processo (0 a P-1)
	int num_p; 			// número de processos
	int source;         // "rank" do processo remetente
	int dest;           // "rank" do processo destinatário
	int tag = 0; // "etiqueta" da mensagem
	double msg = 0;
	MPI_Status status;
	
   	int wsize, repeat;
   	long start_time, end_time;

   	if ((argc != 3)) {
      	printf("ERRO NOS ARGUMENTOS\n");
      	exit(EXIT_FAILURE);
	}

   	wsize = atoi(argv[1]);  // worksize = tamanho do vetor de cada thread
   	repeat = atoi(argv[2]); // numero de repeticoes dos calculos (para aumentar carga)
		
		
	// MPI_Init deve ser invocado antes de qualquer outra chamada MPI
	MPI_Init(&argc, &argv);
    // Descobre o "rank" do processo
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    // Descobre o número de processos
	MPI_Comm_size(MPI_COMM_WORLD, &num_p);
	
	
	// Cria vetores
   	dotdata.a = (double*)malloc(wsize*num_p*sizeof(double));
   	fill(dotdata.a, wsize*num_p, 0.01);
   	dotdata.b = (double*)malloc(wsize*num_p*sizeof(double));
   	fill(dotdata.b, wsize*num_p, 1.0);
   	dotdata.c = 0.0;
   	dotdata.wsize = wsize;
   	dotdata.repeat = repeat;
	
	

	if(myrank == 0){
   		
   		start_time = wtime();
   		
		for(source = 1; source < num_p; source++){
			MPI_Recv(&msg, 1, MPI_DOUBLE, source, tag, MPI_COMM_WORLD, &status);
			dotdata.c += msg;
		}	
		dotdata.c += dotprod_worker(myrank);
		end_time = wtime();
		printf("%d process, %ld usec, result: %f\n", num_p, (long) (end_time - start_time), dotdata.c);
	} else {
		dest = 0;
		tag = dest;
		msg = dotprod_worker(myrank);
		MPI_Send(&msg, 1, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
	}
	MPI_Finalize();
}
