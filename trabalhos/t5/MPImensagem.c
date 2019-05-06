/*
	Natan Luiz Paetzhold Berwaldt
			201710492	
		PROGRAMACAO PARALELA
			TRABALHO 5
*/

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
   int numtasks, rank, dest, tagIn, tagOut, source, rc;
   int msg = 0;
   MPI_Status stat;

   MPI_Init(&argc,&argv);
   MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);

   printf("Processo %d iniciando...\n",rank);

   if (rank == 0) {
      dest = 1;
      tagOut = rank;
      msg += 1;
      rc = MPI_Send(&msg, 1, MPI_INT, dest, tagOut, MPI_COMM_WORLD);
      //printf("Enviei mensagem para processo %d...\n", dest);
   }
   else if (rank == numtasks-1) {
      source = rank-1;
      tagIn = rank-1;
      rc = MPI_Recv(&msg, 1, MPI_INT, source, tagIn, MPI_COMM_WORLD, &stat);
      //printf("Recebi mensagem do processo %d...\n", source);
      printf("Resultado: %d\n",msg); 
   }
   else{
      dest = rank+1;
      source = rank-1;
      tagIn = source;
      tagOut = rank;
      rc = MPI_Recv(&msg, 1, MPI_INT, source, tagIn, MPI_COMM_WORLD, &stat);
      //printf("Recebi mensagem do processo %d...\n", source);
      msg+=1;
      rc = MPI_Send(&msg, 1, MPI_INT, dest, tagOut, MPI_COMM_WORLD);
      //printf("Enviei mensagem para processo %d...\n", dest);
   }

   MPI_Finalize();
}
