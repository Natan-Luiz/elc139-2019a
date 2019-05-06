### Nome: Natan Luiz Paetzhold Berwaldt
### Disciplina: Programacao Paralela
### Matricula: 201710492

# TRABALHO 5

### Parte 1:

A parte 1 foi implementada em? [MPI DOTPROD](MPI_dotprod.c)

Compilar: mpicc -o MPI_dotprod MPI_dotprod.c
Executar: mpiexec -np [PROCESSOS] MPI_dotprod [ELEMENTOS/PROCESSO] [REPETICOES]

### Parte 2:

A parte 2 foi implementada em: [MPI MENSAGEM](MPImensagem.c)

### Parte 3:

Primeiro programa: [MPI CERTO 1](mpi_errado1.c)

O erro encontrava-se na linha linha 36, onde era atribuido o valor 1 para a tag, mas no momento de receber a mensagem houve falha, visto que a mensagem foi enviada pelo outro processo com a Tag 0.

Segundo Programa: [MPI CERTO 2](mpi_errado2.c)

O erro encontrado foi a falta da chama da funcao MPI_Finalize() ao final do codigo.
