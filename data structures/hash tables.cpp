
Hash table:

- Hash function
- Key
- Colisão
- Encadeamento
- Load factor


Descrição - 
  
  Hash table ou tabela de espalahamento é uma estrutura de dados especial, que associa chaves com pesquisa de valores. Seu objeto é,
  apartir de chaves simples, fazer uma busca rápida e obter o valor desejado.

 
=================================================================================================================================    
Função hash: é uma função que gera um valor a partir de uma chave.
    
    // uma função hash simples retorna o resto da divisão por 10 com a chave, 10 seria o tamanho do vetor onde 
    // as chaves serão armazenadas
    int hash(int x)
    {
        return x % 10;
    }

    // função de inserção extremamente simples sem tratar as colisões
    void insere(int a[], int x)
    {
        a[hash(x)] = x;
    } 

    // função de busca também bem simples, sem tratar colisões
    int busca_hash(int a[], int x)
    {
        int k;
        k = hash(x);
        if (a[k] == x) return k;
        return – 1;
    }

    Há muitas maneiras de determinar uma função hash:

    Divisão: basicamente é usado o operator modular em conjunto com a chave, geralmente é usado apenas a chave com o 
             tamanho da tabela onde as keys serão armazenadas,  h(k) = k % s, sendo K a chave e S o tamanho da tabela.

    Enlaçamento: neste método a chave é dividida em diversas partes que são combinadas ou "enlaçadas" e transformadas para
                 criar o endereço.
          Existem 2 tipos de enlaçamento:
           - enlaçamento deslocado e enlaçamento limite.

          Enlaçamento deslocado: as partes da chave são colocadas uma embaixo da outra e processadas. Por exemplo, um código
                                 123-456-789 pode ser dividio em 3 partes: 123-456-789 que são adicionadas resultando em 1368.
                                 Esse valor pode usar o método da divisão 'valor % S', ou se a tabela contiver 1000 posições
                                 pode-se usar os 3 primeiros números para compor o endereço.

          Enlaçamento limite: as partes da chave são colocadas em ordem inversa. Considerando as mesmas divisões do código
                              123-456-789. Alinha-se as partes sempre invertendo as divisões da seguinte forma 321-654-987.
                              O resultando da soma é 1566. Esse valor pode usar o método da divisão 'valor % S', ou se a 
                              tabela contiver 1000 posições pode-se usar os 3 primeiros números para compor o endereço.

    Meio-quadrado: a chave é elevada ao quadrado e a parte do resultado é usada como endereço.

    Extração: neste método somente uma parte da chave é usada para criar o endereço. Para o código 123-456-789 pode-se 
              usar os primeiros ou os últimos 4 dígitos ou outro tipo de combinação como 1289. Somente uma porção da chave
              é usada.

    Transformação da raiz: A chave é transformada para outra base númerica. O valor obitido é aplicado no método da divisão
                           'valor % S' para obter o endereço.
  
=================================================================================================================================
Colisões: ocorrem quando uma função hash gera um valor que já foi gerado com uma key diferente, ou seja, o valo gerado já está
          sendo ocupado na tabela. Isso é conhecido como colisão.
 
    Existem 2 maneiras principais de se tratar colisões:

    - Separate chaining
    - Open addressing
    
      
      
  Separete Chaining: a ideia é fazer cada slot da tabela de espalhamento apontar para uma lista ligada
                     de registros.
  
                ...
             
             
  Open addressing: assim como separate chaining, open addressing é um método para manipular colisões. Em open addressing,
                   todos os elementos são armazenados em uma table hash. Então em qualquer ponto, o tamanho da tabela deve
                   ser maior ou igual ao número total de chaves/keys.
                     
     Insert(k): continue 'sondando' até que um slot vazio seja encontrado. uma vez que um slot vazio seja encontrado, insira k.
                     
     Search(k): continue 'sondando' até a chave do slot não se torne igual a chave de busca ou um slot vazio seja encontrado.
                     
     Delete(k): se nós simplesmente deletar-mos uma chave, a operação de busca pode falhar. Então slots de chaves deletadas são
                 marcados como 'deletado'.
                     
                a operação de inserção pode inserir um item em um slot deletado, mas a operação de busca não pararia em um slot
                deletado.
             
      
                     
     Open addressing é feito das seguintes maneiras:

      
     1 - Linear probing: em linear probing(sondagem linear), nós linearmente seguimos ao próximo slot. Por exemplo, o intervalo
         típico entre duas sondas é 1.
       
       hash(x) é o índice do slot executado usando a função hash e S é o tamanho da tabela
       
           se slot hash(x) % S está cheio, então nós tentamos (hash(x) + 1) % S
           se (hash(x) + 1) % S também não está cheio, então nós tentamos (hash(x) + 2) % S
           se (hash(x) + 2) % S também não está cheio, então nós tentamos (hash(x) + 3) % S 
           ...        
           ...
       
       
          Clustering: o principal problema com linear probing é o agrupamento/aglomeramento, muitos elementos consecutivos forma
                      grupos e isso começa a levar tempo para encontrar um slot vazio ou para encontrar/buscar um elemento, isso
                      é conhecido como agregação primária.
    
            
  
     2 - Quadratic probing: nós procuramos pelo i² slot.
       
      hash(x) é o índice.
      
        Se slot hash(x) % S está cheio, então nós tentamos (hash(x) + 1*1) % S
        Se (hash(x) + 1*1) % S também está cheio, então nós tentamos (hash(x) + 2*2) % S
        Se (hash(x) + 2*2) % S também está cheio, então nós tentamos (hash(x) + 3*3) % S





      Linear probing tem a melhor performance de chace, mas sofre de agrupamentos. A maior vantagem de linear probing é a facilidade
      de calcular.

      Quadratic probing fica entre os dois termos de performance de cache e o problema de agrupamentos.
       
       
  Open Addressing vs Separate Chaining
  
  Vantagens de chaining:
      1 - é mais simples de implementar
      2 - a tabela hash nunca é preenchida, nós podemos sempre adicionar mais elementos. em open addressing a tabela pode ficar cheia
      3 - é menos sensivel ao hash function ou load factors
      4 - é mais usado quando é desconhecida a quantidade de chaves e o quão frequente elas são inseridas ou deletadas
      5 - open addressing requer cuidado extra para evitar agrupamentos e load factor
       
  Vantagens de open addressing:
      1 - performance de cache do chaining não é bom pois as chaves são armazenadas usando listas ligadas. Open addressing provém
          melhor performance de cache pois tudo é armazenado na mesma tabela
      2 - Disperdicio de espaço(algumas partes da tabela hash de chaining nunca serão usadas). Em open addessing, um slot pode ser usado
          mesmo se uma entrada não for mapeada para ele
      3 - chaining usa espaço extra
        
