### Nome: Natan Luiz Paetzhold Berwaldt
### Disciplina: Programacao Paralela
### Matricula: 201710492

# TRABALHO 6

### Parte 1:

Implementacao do trabalho: [AQUI](t6.c)

Alterado if/else que era responsavel pelo gerenciamento dos SEND/RECEIVE e colocadas as funcoes MPI_BCAST e MPI_SCATTER para fazer a divisao do trabalho no lugar;

Outra alternativa seria, ao inves de dividir o trabalho em linhas, dividir um pedaco de cada linha para os diferentes processor e utilizar a funcao REDUCE para fazer o somatorio das multiplicacoes e colocar na posicao correta da matriz C.

### Parte 2:

&nbsp;&nbsp;&nbsp;&nbsp; O texto em questão tem por objetivo levar ao leitor à concordar com os argumentos de quem o escreveu, e para afirmar estes argumentos apresenta verdades tendo como referencial artigos que eram atuais na epoca em que foi escrito.  
 &nbsp;&nbsp;&nbsp;&nbsp; Muitos dos pontos levantados no artigo provam-se parte importante da discussão sobre o uso ou não da tecnica de Send-Receive, porem em alguns casos, algumas tentativas passam por não ser tão convincentes.  
 &nbsp;&nbsp;&nbsp;&nbsp; Na ordem que é citado no artigo, primeiramente, Simplicidade e facilidade na programação. Vendo diretamente a syntaxe das chamadas, ainda não parece que há uma grande simplificação no codigo, mas cada vez mais o programador padrão está trabalhando em niveis mais altos de abstração da computação, buscando cada vez mais que os codigos sejam de facil compreensão ao invés de eficientes, visto o aumento considerável na qualidade do hardware que tem-se nos dias atuais. Assim, chamadas que abstraem grandes partes de codigo são sempre bem vistas aos olhos da comunidade e um ponto forte à favor da ideia discutida no artigo.  
 &nbsp;&nbsp;&nbsp;&nbsp; Quanto a flexibilidade das operações, o artigo utiliza apenas exemplos de uso real do programa, talvez com uma busca maior por uma falha, seja possivel encontrar applicações nas quais as operações coletivas deixem a desejar. Quanto a performance são bastante controversos os argumentos citados no artigo, em primeiro lugar, o trecho que cite: "As implementações são escritas por programadores muito mais familiarizados com maquinas pralelas..."; Obviamento que estes vao ser mais eficientes do que programadores sem a mesma experiencia no assunto, mas neste caso o problema deixa de ser das primitivas e pode ser resolvido com um maior estudo por parte do programador. E quanto ao segundo ponto, operações implementadas diretamente no hardware criam uma comparação um tanto infundada com as primitivas, visto que gera uma situação diferente da proposta.  
 &nbsp;&nbsp;&nbsp;&nbsp; Quanto ao ultimo ponto, previsibilidade, é citado no artigo que send-receive permite maior precisão na previsão, mas que para isso é necessário um estudo detalhado e dificil do modelo, "dificil para um programador de aplicação usar", programador esse, que em parte dos casos, possivelmente não estará sequer se importando com performance ou características de baixo-nível.  
 &nbsp;&nbsp;&nbsp;&nbsp; Assim sendo, muitos dos pontos citados realmente mostram valor no uso de coletivos, e demonstram que o uso dos mesmos deve ser prioridade a sua contra-parte, porem não totalmente é necessário ignorar o Send-Receive, que passa a sensação de que o programador tem "maior controle" do que está fazendo, basta apenas que o mesmo "Saiba o que está fazendo".  
