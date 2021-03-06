## Nome: Natan Luiz Paetzhold Berwaldt
## Disciplina: Programação Paralela
## Trabalho 3

[OpenMPDemoABC.cpp](OpenMPDemoABC.cpp)

Resultados obtidos com a execução do código:


```
Threads adicionam Chars ao array (nThreads= 3 | tamanho array = 60)
Casos com exclusão mútua.

Case 1: Schedule Static without chunk
ABBCCCCCCCCCCCCCCCCCCCCBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAAA
A=20 B=20 C=20 

Case 2: Schedule Static with chunk 
ACCCCCCCCCCCCCCCAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBB
A=30 B=15 C=15 

Case 3: Schedule Dynamic without chunk
ACCCCCCBCBBCCAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACB
A=46 B=4 C=10 

Case 4: Schedule Dynamic with chunk
BCCCAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACCCCCCCCCCCCBBBBBBBBBBBBBB
A=30 B=15 C=15 

Case 5: Schedule Guided without chunk
ACCCAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACCCCCCCCCCCBBBBBBBBB
A=37 B=9 C=14 

Case 6: Schedule Guided with chunk
ACCCAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBCCCCCCCCCCCC
A=30 B=15 C=15 

Case 7: Schedule Runtime
ACCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCBA
A=2 B=1 C=57 

Case 8: Schedule Auto
CAAAAAAAAAAAAAAAAAAAACCCCCCCCCCCCCCCCCCCBBBBBBBBBBBBBBBBBBBB
A=20 B=20 C=20 


Casos sem exclusão mútua.


Case 1: Schedule Static without chunk
CBCABCABCAACBACBACBABCABABABCABCABCABCABCABCABCABCABCABC--CC
A=19 B=19 C=20 

Case 2: Schedule Static with chunk 
BCBABCABCABACBACBACBACBACBACBACBACBACBACBAC-A-AAAAAAAAAAAAAA
A=29 B=15 C=14 

Case 3: Schedule Dynamic without chunk
BBCABCABCABACBACBACBACBACBACBACBACBACBACBACBACBCABCABCABCA--
A=19 B=20 C=19 

Case 4: Schedule Dynamic with chunk
CBACABCACBABCBACBACBACBACBACBACBACBACBACBACB--BBBBBBBBBBBBBB
A=14 B=29 C=15 

Case 5: Schedule Guided without chunk
BBCABCABCABACBACBACBACBACBACBACBACBACBACBCABCABCABCABCABCA--
A=19 B=20 C=19 

Case 6: Schedule Guided with chunk
BBACABCABCABCBACBACBACBACBACBACBACBACBACBACBC-BCBCBCBCB-BBBB
A=14 B=25 C=19 

Case 7: Schedule Runtime
ABCABCABCABACBACBACBACBACBACBACBACBACBACBACBACBCABCABCABCB--
A=19 B=20 C=19 

Case 8: Schedule Auto
ABCCBACABABCABCAABCACBACABCABACBAACBACBACABCABACABC-BCBCBCB-
A=20 B=19 C=19 


```

### REFERENCIAS

FINLAYSON, Ian. OpenMP Scheduling - University of Marry Washington. [Disponível aqui](http://ianfinlayson.net/class/cpsc425/notes/11-scheduling)
