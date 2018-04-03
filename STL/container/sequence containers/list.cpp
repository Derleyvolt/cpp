
- rápido na inserção ou remoção em qualquer localização
- rápido acesso em ambas as extremidades
- lento acesso aleatório


É uma lista bi-dimensional que permite inserção e remoção rápida de elementos em qualquer posição. Elementos na lista não são continuos.

Um list gerencia seus elementos como um doubly linked list.

========================================== HABILIDADE DAS LISTAS ======================================================================

A estrutura interna de uma lista é totalmente diferente de um array, vector, ou de um deque. Um objeto list provém dois ponteiros,
os chamados ancoras, no qual referem-se ao primeiro e último elemento. Cada elemento tem ponteiro para o elemento antecessor e su-
cessor. Para inserir um novo elemento, você apenas manipula os ponteiros correspondentes.

Portanto, listas diferem de várias maneiras de vectors, deques e arrays:

• Uma lista não provém random access. Por exemplo, para acessa o quinto elemento, você deve navega os primeiros quatro elementos,
  seguindo a corrente de ligações. Portanto, acessando um elemento arbitrário usando listas é lento. Embora, você pode navegar por
  uma lista de ambas as extremidades. Então o acesso ao primeiro e último elemento é rápido.

• Inserir e remover elementos é rápido em toda posição, diferente de vectors e deques, internamente apenas alguns ponteiros são
  manipulados.

• Inserção e remoção de elements não inválida ponteiros, referências e iterators a outros elementos.

• Uma lista suporta 'exception handling' de tal maneira que quase todas as operações são bem-sucedidas ou são no-op.
  Embora, você não pode estar em um estado intermediário no qual apenas metade da operação está completa.

As funções membros providas pela list refletem essas diferenças de arrys, vectors e deques:

• Listas provém front(), push_front(), e pop_front(), também back(), push_back(),
  e pop_back().

• Listas não possuem nem um operator subscript nem at(), porque acesso aleatório/random acess não é possível.

• Listas não provém operações para capacidade ou realocação, pois isso não é necessário. Cada elemento tem sua própria
  memória que permanece válida até o elemento ser deletado.
  
• Listas provém várias funções membros especiais para mover e remover elementos. Essas funções membros são versões mais
  rapidas doque algoritmos gerais que possuem o mesmo nome. Elas são mais rapidas porque elas apenas redirecionam ponteiros
  ao invés de copiar e mover valores.

================================= CONSTRUTORES E DESTRUTORES DA LIST =========================================================

Operação                                  Efeito

list<Elem> c                              Default constructor; creates an empty list without any elements
list<Elem> c(c2)                          Copy constructor; creates a new list as a copy of c2 (all elements are copied)
list<Elem> c = c2                         Copy constructor; creates a new list as a copy of c2 (all elements are copied)
list<Elem> c(rv)                          Move constructor; creates a new list, taking the contents of the rvalue rv (since C++11)
list<Elem> c = rv                         Move constructor; creates a new list, taking the contents of the rvalue rv (since C++11)
list<Elem> c(n)                           Creates a list with n elements created by the default constructor
list<Elem> c(n,elem)                      Creates a list initialized with n copies of element elem
list<Elem> c(beg,end)                     Creates a list initialized with the elements of the range [beg,end)
list<Elem> c(initlist)                    Creates a list initialized with the elements of initializer list initlist (since C++11)
list<Elem> c = initlist                   Creates a list initialized with the elements of initializer list initlist (since C++11)
c.~list()                                 Destroys all elements and frees the memory

===============================================================================================================================

========================================= OPERAÇÕES NÃO MODIFICADORAS =========================================================

Listas provém as operações usuais para size e comparações.


Operação                                  Efeito

c.empty()                                 Returns whether the container is empty (equivalent to size()==0 but might be faster)
c.size()                                  Returns the current number of elements
c.max_size()                              Returns the maximum number of elements possible
c1 == c2                                  Returns whether c1 is equal to c2 (calls == for the elements)
c1 != c2                                  Returns whether c1 is not equal to c2 (equivalent to !(c1==c2))
c1 < c2                                   Returns whether c1 is less than c2
c1 > c2                                   Returns whether c1 is greater than c2 (equivalent to c2<c1)
c1 <= c2                                  Returns whether c1 is less than or equal to c2 (equivalent to !(c2<c1))
c1 >= c2                                  Returns whether c1 is greater than or equal to c2 (equivalent to !(c1<c2))

===============================================================================================================================

========================================= ATRIBUIÇÃO =========================================================

Listas também provém usuais operações de atribuição para containers sequenciais. Como sempre, as operações de inserção
se assemelham com os construtores para prover diferentes fontes para inicialização.


Operação                                Efeito

c = c2                                  Assigns all elements of c2 to c
c = rv                                  Move assigns all elements of the rvalue rv to c (since C++11)
c = initlist                            Assigns all elements of the initializer list initlist to c (since C++11)
c.assign(n,elem)                        Assigns n copies of element elem
c.assign(beg,end)                       Assigns the elements of the range [beg,end)
c.assign(initlist)                      Assigns all the elements of the initializer list initlist
c1.swap(c2)                             Swaps the data of c1 and c2
swap(c1,c2)                             Swaps the data of c1 and c2
