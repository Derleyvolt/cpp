
Organiza elementos em um range.

Organiza elementos em um range (first, last) em ordem ascendente.

Os elementos são comparados usando operator< na primeira versão, e comp na segunda versão.

Elementos equivalentes não são garantidos manter sua original ordem relativa.



paramêtros:

  Random-access itrators na posição inicial e final da sequência a ser organizada. O range usado é (first, list),
  no qual contém todos os elementos entre first e last, incluindo o elemento apontado por first mas não o 
  elemento apontando por last, pois last aponta pro endereço logo após o último elemento.
  
  RandomAcessIterator deve apontar para um tipo no qual swap é apropriadamente definido e no qual deve ser
  'move-constructible' e 'move-assignable'.
  
  
comp:

  Função binária que aceita dois elementos no range como argumento, e retorna um bool. O valor retornado
  indica se o primeiro elemento passado vem antes do segundo elemento passado em uma especifica 'strict weak
  ordering' que isso define.
  
  A função não deve modificar qualquer de seus elementos.
  A função pode ser um ponteiro para função ou uma função objeto.
  
  
  
  Complexidade: O(n * log(n))
