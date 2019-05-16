### Nome: Natan Luiz Paetzhold Berwaldt
### Disciplina: Programacao Paralela
### Matricula: 201710492

# TRABALHO 6

### Parte 1:

Implementacao do trabalho: [AQUI](t6.c)

Alterado if/else que era responsavel pelo gerenciamento dos SEND/RECEIVE e colocadas as funcoes MPI_BCAST e MPI_SCATTER para fazer a divisao do trabalho no lugar;

Outra alternativa seria, ao inves de dividir o trabalho em linhas, dividir um pedaco de cada linha para os diferentes processor e utilizar a funcao REDUCE para fazer o somatorio das multiplicacoes e colocar na posicao correta da matriz C.

### Parte 2:
