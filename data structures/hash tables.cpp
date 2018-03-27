
Hash table:

- Hash function
- Key
- Colisão
- Encadeamento


Descrição - 
  
  Hash table ou tabela de espalahamento é uma estrutura de dados especial, que associa chaves com pesquisa de valores. Seu objeto é,
  apartir de chaves simples, fazer uma busca rápida e obter o valor desejado.

 
=================================================================================================================================    
Função hash: é uma estrutura da dados especial, que associa chaves de pesquisa a valores. Seu objetivo é, a partir de uma chave 
             simples, fazer uma busca rápida e obter o valor desejado.
    
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
 
    Para tratar as colisões, pode-se colocar o elemento na primeira posição livre seguinte e considerar a tabela como circular
    (o elemente após o último a[n - 1] é o primeiro elemento a[0].
      - Isso se aplica tanto na inserção de novos elementos quanto na busca. 
      - Esta técnica é cconhecida como lista linear, linear probing ou sondagem.
  
