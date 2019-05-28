//Natan Luiz P. Berwaldt

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char** argv) {

  int myrank;    // "rank" do processo
  int p;         // numero de processos
  int root;      // rank do processo root

  // MPI_Init deve ser invocado antes de qualquer outra chamada MPI
  MPI_Init(&argc, &argv);
  // Descobre o "rank" do processo
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  // Descobre o numero de processos
  MPI_Comm_size(MPI_COMM_WORLD, &p);

  int data = 0;     // dado a ser enviado
  root = 0;     // define o rank do root

	// Seta o valor da mensagem
	if(myrank == root)
		data = 100;
	
	// Efetua o Bcast
    MPI_Bcast(&data, 1, MPI_INT, root, MPI_COMM_WORLD);

  // Efetua os diferentes prints
  if (myrank == root) {
    printf("Processo %d (root) realizando broadcast do dado %d\n", root, data);
  } else {
    printf("Processo %d recebendo dado %d do processo root\n", myrank, data);
  }

  MPI_Finalize();
  return 0;
}
