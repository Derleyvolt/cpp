
- rápido na inserção ou remoção em qualquer localização
- rápido acesso em ambas as extremidades
- lento acesso aleatório


É uma lista bi-dimensional que permite inserção e remoção rápida de elementos em qualquer posição. Elementos na lista não são continuos.

Um list gerencia seus elementos como um doubly linked list.

## Habilidade das listas

A estrutura interna de uma lista é totalmente diferente de um array, vector, ou de um deque. Um objeto list provém dois ponteiros,
os chamados ancoras, no qual referem-se ao primeiro e último elemento. Cada elemento tem ponteiro para o elemento antecessor e su-
cessor. Para inserir um novo elemento, você apenas manipula os ponteiros correspondentes.

Portanto, listas diferem de várias maneiras de vectors, deques e arrays:

Uma lista não provém random access. Por exemplo, para acessa o quinto elemento, você deve navega os primeiros quatro elementos,
seguindo a corrente de ligações. Portanto, acessando um elemento arbitrário usando listas é lento. Embora, você pode navegar por
uma lista de ambas as extremidades. Então o acesso ao primeiro e último elemento é rápido.

Inserir e remover elementos é rápido em toda posição, diferente de vectors e deques, internamente apenas alguns ponteiros são
manipulados.

Inserção e remoção de elements não inválida ponteiros, referências e iterators a outros elementos.

Uma lista suporta 'exception handling' de tal maneira que quase todas as operações são bem-sucedidas ou são no-op.
Embora, você não pode estar em um estado intermediário no qual apenas metade da operação está completa.

As funções membros providas pela list refletem essas diferenças de arrys, vectors e deques:

Listas provém front(), push_front(), e pop_front(), também back(), push_back(),
e pop_back().

Listas não possuem nem um operator subscript nem at(), porque acesso aleatório/random acess não é possível.

Listas não provém operações para capacidade ou realocação, pois isso não é necessário. Cada elemento tem sua própria
memória que permanece válida até o elemento ser deletado.
  
Listas provém várias funções membros especiais para mover e remover elementos. Essas funções membros são versões mais
rapidas doque algoritmos gerais que possuem o mesmo nome. Elas são mais rapidas porque elas apenas redirecionam ponteiros
ao invés de copiar e mover valores.

## Construtores e destrutores da lista

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

## Operações não modificadoras

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

## Atribuição

Listas também provém usuais operações de atribuição para containers sequenciais. Como sempre, as operações de inserção
se assemelham com os construtores para prover diferentes fontes para inicialização.


Operação                                Efeito

c = c2                                  Assigns all elements of c2 to c
c = rv                                  Move assigns all elements of the rvalue rv to c (since C++11)
c = initlist                            Assigns all elements of the initializer list initlist to c (since C++11)
c.assign(n,elem)                        Assigns n copies of element elem
c.assign(beg,end)                       Assigns the elements of the range (beg, end)
c.assign(initlist)                      Assigns all the elements of the initializer list initlist
c1.swap(c2)                             Swaps the data of c1 and c2
swap(c1,c2)                             Swaps the data of c1 and c2


## Acesso aos elementos
   
Para acessar todos os elementos da lista, você deve usar range-based for loops, operações especificas ou iterators. Porque listas
não possuem random acess/acesso aleatório, listas provém apenas front() e back() para acessar os elementos diretamente.
                                                                                                                                                                                                                          
Operação                               Efeitos

c.front()                              Returns the first element (no check whether a first element exists)
c.back()                               Returns the last element (no check whether a last element exists)                                                                           

                                                                                                                                                      
Como sempre, essas operações não checam se o container está vazio. Se o container estiver vazio, chamar essas operações resultará
em 'undefined behavior'. Portanto, o chamador deve garantir que o container contém pelo menos um elemento. Por exemplo:
                                                                                                                                                                                                                               
std::list<Elem> coll;      // vazio!
std::cout << coll.front(); // RUNTIME ERROR ⇒ undefined behavior
                                                                           
if (!coll.empty()) 
{
    std::cout << coll.back(); // OK
}

Note que este código está OK apenas em ambientes single-thread. Em contextos multithread, você precisa que os mecanismos de sincroni-
zação garantam que coll não seja modificado entre a checagem de seu tamanho e o acesso ao elemento.
                                                                           

## Acesso aos elementos
                                                                           
Para acessar todos os elemento de uma lista, você deve usar iterators. Listas fornecem as funções usuais dos iterators. Embora,
pelo fato da lista não possuir random acess, esses iterators são apenas bidirecionais. Portanto, você não pode chamar algoritmos
que requerem random-acess iterators. Todos os algoritmos que manipulam a ordem de muitos elementos, especialmente algortimos de 
'sort', são desta categoria. Embora, para ordenar/sorting os elementos, listas fornecem a função membro especial sort().
                                                                           
Operação                                 Efeitos

c.begin()                                Returns a bidirectional iterator for the first element
c.end()                                  Returns a bidirectional iterator for the position after the last element
c.cbegin()                               Returns a constant bidirectional iterator for the first element (since C++11)
c.cend()                                 Returns a constant bidirectional iterator for the position after the last element (since C++11)
c.rbegin()                               Returns a reverse iterator for the first element of a reverse iteration
c.rend()                                 Returns a reverse iterator for the position after the last element of a reverse iteration
c.crbegin()                              Returns a constant reverse iterator for the first element of a reverse iteration (since C++11)
c.crend()                                Returns a constant reverse iterator f

## Inserção e remoção de elementos

Listas fornecem todas as funções do deque, complementando com implementações especiais dos algoritmos remove() e remove_if().                                                                          
Como de costume quando usando STL, você deve garantir que os argumentos são válidos. Iterators devem se referir a posições
válidas, e o início do range deve ter a posição que não esteja depois do final do range. Inserção e remoção são mais rapidas se,
quando trabalhando com multiplos elementos, você use uma única chamada para todos os elementos ao invés de multiplas chamadas.                                                                          
Para remover elementos, listas provém implementações especiais do algoritmo remove(). Essas funções membros são mais rapidas 
doque o algoritmo remove() porque elas manipulam apenas os ponteiros internos ao invés dos elementos. a contrário dos vectors
ou deques, você deve chamar a função membro remove() ao invés do algoritmo remove(). Para remover todos os elementos que tem 
um certo valor, você pode fazer o seguinte:
                                                                           
std::list<Elem> coll;
...
// remover todos os elementos com o valor val
coll.remove(val);
                                                                           
Embora, para remover apenas a primeira ocorrência de um valor, você deve usar um algoritmo, como find(), para encontrar
a primeira ocorrência do valor e depois o deletar. Você pode usar remove_if() para definir o critério para remoção dos
elementos por uma função ou uma função object. remove_if() remove todo elemento para qual a função passada retorna true.
Um exemplo do uso de remove_if() é uma declaração para remover todos os elementos que tem um valor par:                                                                           
                                                                           

You can use remove_if() to define the criterion for the removal of the elements by a function
or a function object. remove_if() removes each element for which calling the passed operation
yields true. An example of the use of remove_if() is a statement to remove all elements that have
an even value:
                                                                           
// remover todos os elementos que são par
coll.remove_if ([] (int i) 
{
    return i % 2 == 0;
});                                                                           

Aqui, um lambda é usado para descobrir quais elementos remover. o valor de cada elemento da lista é passado para função lambda,
se o elemento passado for par, ele será removido, assim, ao final de todos os elementos, todos os elementos par serão removidos.
As seguintes operações não invalidam iterators e referências para outros membros: insert(), emplace(), emplace...(), push_front(),
push_back, pop_front() e erase().                                                                           
                                                                                                                                                                                                                                      
Operação                             Efeito

c.push_back(elem)                    Appends a copy of elem at the end
c.pop_back()                         Removes the last element (does not return it)
c.push_front(elem)                   Inserts a copy of elem at the beginning
c.pop_front()                        Removes the first element (does not return it)
c.insert(pos,elem)                   Inserts a copy of elem before iterator position pos and returns the position of the new element
c.insert(pos,n,elem)                 Inserts n copies of elem before iterator position pos and  returns the position of the first new
                                     element (or pos if there is no new element)
c.insert(pos,beg,end)                Inserts a copy of all elements of the range (beg,end) before iterator position pos and returns the
                                     position of the first new element (or pos if there is no new element)
c.insert(pos,initlist)               Inserts a copy of all elements of the initializer list initlist before iterator position pos and 
                                     returns the position of the first new element (or pos if there is no new element; since C++11)
c.emplace(pos,args...)               Inserts a copy of an element initialized with args before iterator position pos and returns the 
                                     position of the new element (since C++11)
c.emplace_back(args...)              Appends a copy of an element initialized with args at the end (returns nothing; since C++11)
c.emplace_front(args...)             Inserts a copy of an element initialized with args at the beginning (returns nothing; since C++11)
c.erase(pos)                         Removes the element at iterator position pos and returns the position of the next element
c.erase(beg,end)                     Removes all elements of the range (beg,end) and returns the position of the next element
c.remove(val)                        Removes all elements with value val
c.remove_if(op)                      Removes all elements for which op(elem) yields true
c.resize(num)                        Changes the number of elements to num (if size() grows new elements are created by their default 
                                     constructor)
c.resize(num,elem)                   Changes the number of elements to num (if size() grows new elements are copies of elem)
c.clear()                            Removes all elements (empties the container)                                                       
                                                                        
                                                                        
                                                                        
                                                                        

Operação                          |   Efeito
----------------------------------|--------------------
c.push_back(elem)                 |   Appends a copy of elem at the end
c.pop_back()                      |   Removes the last element (does not return it)
c.push_front(elem)                |   Inserts a copy of elem at the beginning
c.pop_front()                     |   Removes the first element (does not return it)
c.insert(pos,elem)                |   Inserts a copy of elem before iterator position pos and returns the position of the new element
c.insert(pos,n,elem)              |   Inserts n copies of elem before iterator position pos and  returns the position of the first new  
c.insert(pos, beg, end)           |   Inserts a copy of all elements of the range (beg,end) before iterator position pos and returns the
                                  |   position of the first new element (or pos if there is no new element)
rato                              |   10                                                        





