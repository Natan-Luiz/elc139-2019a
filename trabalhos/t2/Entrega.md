#### Nome: Natan Luiz Paetzhold Berwaldt
#### Disciplina: Programação Paralela



[MINHAS SPECS](specs.txt)


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
|               |         |        |        |        |                |                | 
|---------------|---------|--------|--------|--------|----------------|----------------| 
| Repeticoes 20 | Size    | 1      | 2      | 4      | SpeedUP 2      | SpeedUP 4      | 
| -             | 100     | 282    | 348    | 432    | "0,8103448276" | "0,6527777778" | 
| -             | 10000   | 1701   | 1401   | 993    | "1,214132762"  | "1,712990937"  | 
| -             | 1000000 | 81561  | 60684  | 38646  | "1,34402808"   | "2,110464214"  | 
| -             | 5000000 | 507442 | 287124 | 193332 | "1,767327009"  | "2,624718102"  | 



|    Repeticoes 2000    |   Size      |   1 Thread       |    2 Thread       |     4 Thread      |     SpeedUP 2         |      SpeedUP 4         | 
|-----------------|---------|----------|----------|----------|---------------|---------------| 
| -               | 100     | 1920     | 897      | 765      | "2,140468227" | "2,509803922" | 
| -               | 10000   | 75030    | 60933    | 32949    | "1,231352469" | "2,277155604" | 
| -               | 1000000 | 7417275  | 4493325  | 3584373  | "1,650731919" | "2,069336813" | 
| -               | 5000000 | 36423084 | 20165343 | 17774208 | "1,806221893" | "2,049209956" | 



|                  |         |           |           |           |               |               | 
|------------------|---------|-----------|-----------|-----------|---------------|---------------| 
| Repeticoes 20000 | Size    | 1         | 2         | 4         | SpeedUP 2     | SpeedUP 4     | 
| -                | 100     | 13566     | 8139      | 3798      | "1,666789532" | "3,571879937" | 
| -                | 10000   | 721068    | 512256    | 347565    | "1,407632121" | "2,074627767" | 
| -                | 1000000 | 73294350  | 41530230  | 35603367  | "1,764843344" | "2,058635353" | 
| -                | 5000000 | 365212305 | 211201503 | 176362056 | "1,729212623" | "2,070809976" | 




### 5) 
A diferença entre os codigos está na falta das linhas  
  <code>pthread_mutex_lock (&mutexsum);</code>
e
  <code>pthread_mutex_unlock (&mutexsum);</code>
responsáveis por impedir que duas ou mais threads executem a instrução <code> dotdata.c += mysum;</code> ao mesmo tempo e por consequencia alterem o mesmo endereço de memoria no mesmo instante.
O programa gerou o mesmo resultado quando testado, porém isso não é totalmente garantido, visto que a memória compartilhada estando desprotegida pode acarretar em duas threads alterando a variavel ao mesmo tempo, fazendo assim com que uma anule o resultado da outra e impedindo que o resultado final seja previsível.


## PARTE 2

### 1)
O arquivo encontra-se em: [opm_dotprod.c](openmp/omp_dotprod.c)


### 2)
