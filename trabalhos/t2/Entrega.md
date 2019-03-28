#### Nome: Natan Luiz Paetzhold Berwaldt
#### Disciplina: Programação Paralela



## PARTE 1

Questões:  

### 1)
Particionamento: Para cada Thread é dividido uma parte igual de multiplicações de elementos dos vetores e as somas parciais dos resultados obtidos, e uma vez por thread é incorporada essa soma parcial ao resultado final que fica guardado em memoria compartilhada.
  
Comunicação: A comunicação é dada em dois momentos, em um primeiro momento onde a thread precisa obter os elementos de cada vetor a[i] e b[i] e após, no calculo das somas é necessário o resultado das somas anteriores. <code>dotdata.c += mysum;</code>  
  
Aglomeração: Para evitar o excesso de comunicações, gerando assim muitos acessos à memoria compartilhada, é feita uma aglomeração de resultados parciais dentro da thread, estes resultados são guardados na variável <code>mysum</code> até o fim da execução da thread, onde aí sim o resultado é passado/comunicado para a memória compartilhada.  
  
Mapeamento: O mapeamento do problema ocorre dentro da função dotprod_threads, onde é dado uma quantidade semelhante de operações de multiplicação e soma para cada thread. Cada thread fica com uma carga de trabalho equivalente à TOTAL_DE_ELEMENTOS_DO_VETOR/NUMERO_DE_THREADS, neste intervalo a thread é responsável por multiplicar 1 a 1 os elementos com indice equivalente dos dois vetores.  

### 2)
O speedUP foi de 1,8 (unidades de medida de speedups :) ).

### 3)
Os resultados detalhados estão em [RESULTS.CSV](results.csv)

### 4)



### 5) 
A diferença entre os codigos está na falta das linhas  
  <code>pthread_mutex_lock (&mutexsum);</code>
e
  <code>pthread_mutex_unlock (&mutexsum);</code>
responsáveis por impedir que duas ou mais threads executem a instrução <code> dotdata.c += mysum;</code> ao mesmo tempo e por consequencia alterem o mesmo endereço de memoria no mesmo instante.
O programa gerou o mesmo resultado quando testado, porém isso não é totalmente garantido, visto que a memória compartilhada estando desprotegida pode acarretar em duas threads alterando a variavel ao mesmo tempo, fazendo assim com que uma anule o resultado da outra e impedindo que o resultado final seja previsível.


## PARTE 2

### 1)
O arquivo encontra-se em:


### 2)
