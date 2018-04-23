# Função sort

Organiza elementos em um range.

Organiza elementos em um range (first, last) em ordem ascendente.

Os elementos são comparados usando operator< na primeira versão, e comp na segunda versão.

Elementos equivalentes não são garantidos manter sua original ordem relativa.

a ordem por padrão é ascendente para valores númericos e lexicografica ascendente para valores strings.

Paramêtros:

  Random-access itrators na posição inicial e final da sequência a ser organizada. O range usado é (first, list),
  no qual contém todos os elementos entre first e last, incluindo o elemento apontado por first mas não o 
  elemento apontando por last, pois last aponta pro endereço logo após o último elemento.
  
  RandomAcessIterator deve apontar para um tipo no qual swap é apropriadamente definido e no qual deve ser
  `move-constructible` e `move-assignable`.
  
  
Comp:

  Função binária que aceita dois elementos no range como argumento, e retorna um bool. O valor retornado
  indica se o primeiro elemento passado vem antes do segundo elemento passado em uma especifica 
  [strict weak ordering](https://en.wikipedia.org/wiki/Weak_ordering) que isso define.
  
  A função não deve modificar qualquer de seus elementos.
  A função pode ser um ponteiro para função ou uma função objeto.
  
  ```cpp
  int main()
  {
      std::vector<Engine> vec = { Engine(10, 20), Engine(100, 200), Engine(1000, 2000) };   
      
      std::sort(vec.begin(), vec.end(), [](const Engine& rhs, const Engine& lhs) 
      { 
          return rhs.x < lhs.x;  
      });
  }
  ```    

  `Complexidade: O(n * log(n))`
