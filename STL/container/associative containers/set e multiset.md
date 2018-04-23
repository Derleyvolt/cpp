# Set e Multiset

• Sets e multisets são implementados como red-black trees.

• Sets e multisets possuem um cretério de organização/sorting criterion.

• Sets e multisets não permite acesso direto aos elementos.

• Sets e multisets podem ser comparados, pois existem sobrecargas dos operadores de comparação pra eles, todos os operadores de 
  comparação executam uma comparação lexicográfica exeto os operadores == e != 
  [multiset cmp operator](http://en.cppreference.com/w/cpp/container/multiset/operator_cmp) & [set cmp operator](http://en.cppreference.com/w/cpp/container/set/operator_cmp)
  
• Sets e multisets por serem otimizados para busca rápida de elementos, eles fornecem funções de busca especiais. Essas funções são
  versões especiais de algoritmos gerais que possuem o mesmo nome. Você deve sempre preferir versões otimizadas para sets e multisets
  para alcançar complexidade logartica ao invés de complexidade linear de algortimos gerais.

• Sets e multisets possuem iterators bidimensional, portanto, não se deve usá-los em algoritmos que utilizem `random-access iterators`.

• Sets e multisets não permitem alterar o valor de um elemento, isso assegura que você não comprometerá a ordem dos elementos mudando
  seus valores.
  
• Sets e multisets possuem algumas funções com retornos diferentes pelo fato de um permitir duplicatas e o outro não.

   
set e multiset organizam seus elementos automaticamente de acordo com um certo "sorting criterion"/ critério de organização.
A diferença entre os dois tipos de containers é que multisets permitem elementos duplicads, e o set não.

 ```cpp
template <typename T,
          typename Compare = less<T>,
          typename Allocator = allocator<T>>
class set;

template <typename T,
          typename Compare = less<T>,
          typename Allocator = allocator<T>>
class multiset;
```

Os elementos de um set ou multiset pode ter qualquer tipo T que é comparavél de acordo com o `sorting criterion`. O segundo template
adicional define o `sorting criterion`. Se um `sorting criterion` especial não é passado, o padrão `criterion less` é usado.
A função objeto `less` organiza os elementos comparando-os com o `operador<`.

O `sorting criterion` deve definir um  [strict weak ordering](https://en.wikipedia.org/wiki/Weak_ordering).

Note que isto significa que você tem que distinguir entre menor e igual. Um critério tal como o operador `<=` não preencheria este
requerimento. Baseado nessas propriedades (que eu não coloquei aqui), o `sorting criterion` também é usado para checar equivalência.
isto é, dois elementos são considerados duplicados se nenhum é menor do que o outro. Para multisets, a ordem dos elementos equivalentes
é aleatória, mas estável. Portanto, inserções e deletações preservam a ordem relativa de elementos equivalentes.

## Habilidades de set e multiset

Como todo container associativo padronizado, sets e multisets são geralmente implementados como árvores binárias balanceadas.
A maior vantagem de organização automatica é que uma árvore binária executa bem quando elementos com um certo valor são buscados.
De fato, buscas tem complexidade logaritmica. Embora, organização automatica também impõe uma importante restrição em sets e multisets:
Você pode não mudar o valor de um elemento diretamente, porque isso pode comprometer a ordem correta.

De fato, sets e multisets são tipicamentes implementados como [red-black trees](https://pt.wikipedia.org/wiki/%C3%81rvore_rubro-negra), 
que são bons tanto para mudar o número de elementos e busca de elementos. Eles garantem no máximo dois relinks internos em inserções e
que o caminho mais longo é no máximo duas vezes maior que o caminho mais curto até uma folha. Portanto, para modificar o valor de um 
elemento, você deve remover o elemento tendo o valor antigo e inserir um novo elemento com um novo valor. As interfaces refletem esse 
comportamento:

• Sets e multisets não fornecem operações para acessar o elemento diretamente.
• Acesso indireto via iterators tem a limitação que, do ponto de vista de iterators, o valor do elemento é constante.

## Operações de set e multiset

Você pode definir um `sorting criterion` de duas maneiras:

1. Como um parâmetro template. Por exemplo:

```cpp
std::set<int, std::greater<int>> coll;
```

Neste caso, o `sorting criterion` é parte do tipo. Portanto, o sistema de tipos garante que apenas containers com o mesmo `sorting
criterion` possam ser combinados (ou seja, um `set<int, std::greater<int>>` não pode ser atribuido a um `set<int, std::less<int>>`.
Isto é uma maneira usual para especificar o `sorting criterion`. Para ser mais preciso, o segundo parâmetro é o tipo do 
`sorting criterion`. Um `sorting criterion` concreto é a função objeto que é criada com o container. Para fazer isso, o construtor do
container chama o construtor padrão do `sorting criterion`.

2. Como um parâmetro do constructor. Neste caso, você pode ter um tipo para vários `sorting criterion` que permite ter diferentes
valores iniciais ou estados. Isto é útil quando processando o `sorting criterion` em tempo de execução e quando são necessários
`sorting criterion` diferentes mas dos mesmos dados. Se nenhum `sorting criterion` especial é usado, o padrão `sorting criterion`,
função objeto `less<>`, é usado, o qual organiza os elementos usando o operador `<`.  Note que o `sorting criterion` também é usado 
para checar equivalência de dois elementos no mesmo container (exemplo, para encontrar duplicatas). Portanto, quando o padrão `sorting
criterion` é usado, a checagem por equivalência de dois elementos parece com isso:

```cpp
if (! (elem1<elem2 || elem2<elem1))
```
                                  
Isto tem três vantagens:
1. Você precisa passa apenas um argumento como `sorting criterion`.
2. Você não precisa fornecer o operador `==` para o tipo de elemento.
3. Você pode ter definições contrarias entre equivalência e igualdade (embora, isto pode uma fonte de confusão).

Checando por equivalência desta meneira leva um pouco mais de tempo porque duas comparações podem ser necessárias para avaliar
a expressão anterior. Note, embora, que se o resultado da primeira comparação retorna true, a segunda comparação não é avaliada.

Note também que se dois containers são comparados pelo operador ==, os elementos em ambos os containers são comparados usando seus
operadores ==, no qual significa que o operador == tem de ser fornecido pelo tipo elemento, o operador == possui uma versão sobreca-
rregada para cada container, no caso do set, primeiro é verificado o tamanho dos 2 containers, se ambos tiverem o mesmo tamanho, então
uma comparação lexográfica é realizada nos elementos de ambos os containers.

O construtor para um início e o fim de um range poderia ser usado para inicializar o container com elementos de um container que
possui outro tipo, ou arrays, ou de um `standard input`.

Initializando um container com os elementos de um outro container:
                                  
```cpp
std::list<int> l; // l é um linked list de inteiros
...

// copia todos os elementos da lista como float em um vector
std::vector<float> c(l.begin(),l.end());
```

Operação              |           Efeito
----------------------|---------------------------------
set c                 |           Default constructor; creates an empty set/multiset without any elements
set c(op)             |           Creates an empty set/multiset that uses op as the sorting criterion
set c(c2)             |           Copy constructor; creates a copy of another set/multiset of the same type (all elements are copied)
set c = c2            |           Copy constructor; creates a copy of another set/multiset of the same type (all elements are copied)
set c(rv)             |           Move constructor; creates a new set/multiset of the same type, taking the contents of the rvalue rv
set c = rv            |           Move constructor; creates a new set/multiset of the same type, taking the contents of the rvalue rv
set c(beg,end)        |           Creates a set/multiset initialized by the elements of the range (beg,end)
set c(beg,end,op)     |           Creates a set/multiset with the sorting criterion op initialized by the elements of the range (beg,end)
set c(initlist)       |           Creates a set/multiset initialized with the elements of initializer list initlist
set c = initlist      |           Creates a set/multiset initialized with the elements of initializer list initlist (since C++11)
c.~set()              |           Destroys all elements and frees the memory


Aqui, set pode ser um dos seguintes tipos:

Set                       |       Efeito
--------------------------|-----------------------------
set<Elem> A               |       set that by default sorts with less<> (operator <)
set<Elem,Op> A            |       set that by default sorts with Op
multiset<Elem> A          |       multiset that by default sorts with less<> (operator <)
multiset<Elem,Op> A       |       multiset that by default sorts with Op

## Operações não modificadoras

Sets and multisets fornecem as habituais operações não modificadoras para consultar o tamanho e fazer comparações

Operação              |           Efeito
----------------------|-----------------------------------------------
c.key_comp()          |           Returns the comparison criterion
c.value_comp()        |           Returns the comparison criterion for values as a whole (same as key_comp())
c.empty()             |           Returns whether the container is empty (equivalent to size() == 0 but might be faster)
c.size()              |           Returns the current number of elements
c.max_size()          |           Returns the maximum number of elements possible
c1 == c2              |           Returns whether c1 is equal to c2 (calls == for the elements)
c1 != c2              |           Returns whether c1 is not equal to c2 (equivalent to !(c1==c2))
c1 < c2               |           Returns whether c1 is less than c2
c1 > c2               |           Returns whether c1 is greater than c2 (equivalent to c2<c1)
c1 <= c2              |           Returns whether c1 is less than or equal to c2 (equivalent to !(c2<c1))
c1 >= c2              |           Returns whether c1 is greater than or equal to c2 (equivalent to !(c1<c2))

Comparações são fornecidas apenas para containers do mesmo tipo. Portanto, os elementos e o "sorting criterion" devem ter os mesmos
tipos, por outro lado, o compilador irá mostrar um erro em tempo de compilação. Por exemplo:

```cpp
std::set<float> c1; // sorting criterion: std::less<>
std::set<float, std::greater<float> > c2;
...
if (c1 == c2) { // ERROR: tipos diferentes
...
}
```

A checagem se o container é menor do que um outro container é feito por comparação lexográfica. Para comparar container de tipos 
diferentes (sorting criteria difrentes), você deve usa algoritmos de comparação.


## Operações especiais de busca

Pelo fato deles serem otimizados para busca rápida de elementos, sets e multisets fornecem funções de busca especiais. Essas funções
são versões especiais de algoritmos gerais que possuem o mesmo nome. Você deve sempre preferir versões otimizadas para sets e multisets
para alcançar complexidade logaritmica ao invés de complexidade linear de algortimos gerais. Por exemplo, a busca de uma coleção de 1000
elementos requer em média apenas 10 comparações ao invés de 500.
                                                                                                                                 

Operação                 |          Efeito
-------------------------|-------------------------------------------------
c.count(val)             |          Returns the number of elements with value val
c.find(val)              |          Returns the position of the first element with value val (or end() if none found)
c.lower_bound(val)       |          Returns the first position, where val would get inserted (the first element >= val)
c.upper_bound(val)       |          Returns the last position, where val would get inserted (the first element > val)
c.equal_range(val)       |          Returns a range with all elements with a value equal to val (i.e., the first and last position, where val would get inserted)
                                   
                                   
A função membro `find()` procura o primeiro elemento que tem o valor que foi passado como argumento e retorna um iterator da posição.
Se tal elemento não for encontrado, fid() retorna `end()` do container. `lower_bound()` e `upper_bound()` return a primeira e última 
posição, respectivamente, no qual um elemento com o valor passado seria inserido. Em outras palavras, `lower_bound()` retorna a posição
do primeiro elemento que tem o mesmo ou maior valor que o argumento, enquanto que upper_bound retorna a posição do primeiro elemento com
um valor maior. `equal_range()` retorna ambos os retornos de `lower_bound()` e `upper_bound()` como um pair. Portanto, `equal_range()` 
retorna um range de elementos que tem o mesmo valor que o argumento. Se `lower_bound()` ou o primeiro valor de `equal_range()` é igual 
ao `upper_bound()` ou o segundo valor de `equal_range()`, não existem elementos com o mesmo valor no set ou multiset. Naturalmente, o 
range de elementos tendo o mesmo valor poderiam conter no máximo on elemento no set.

O seguinte exemplo mostra como usar `lower_bound()`, `upper_bound()`, e `equal_range()`:

```cpp
#include <iostream>
#include <set>
using namespace std;

int main ()
{
    set<int> c;
    c.insert(1);
    c.insert(2);
    c.insert(4);
    c.insert(5);
    c.insert(6);
    cout << "lower_bound(3): " << *c.lower_bound(3) << endl;
    cout << "upper_bound(3): " << *c.upper_bound(3) << endl;
    cout << "equal_range(3): " << *c.equal_range(3).first << " " << *c.equal_range(3).second << endl;
    cout << endl;
    cout << "lower_bound(5): " << *c.lower_bound(5) << endl;
    cout << "upper_bound(5): " << *c.upper_bound(5) << endl;
    cout << "equal_range(5): " << *c.equal_range(5).first << " " << *c.equal_range(5).second << endl;
}
```

O output do programa é o seguinte:

```
lower_bound(3): 4
upper_bound(3): 4
equal_range(3): 4 4
lower_bound(5): 5
upper_bound(5): 6
equal_range(5): 5 6
```

Se você usar um multiset ao invés de um set, o programa tem o mesmo output.

## Atribuição

Sets e multisets fornecem apenas as operações de atribuição fundamentais que todos os containers fornecem. Para essas operações, ambos
containers devem ter o mesmo tipo. Em particular, o tipo do critério de comparação deve ser o mesmo, embora o próprios critério de 
comparação possam ser diferentes.

Operação            |           Efeito
--------------------|------------------------------------
c = c2              |           Assigns all elements of c2 to c
c = rv              |           Move assigns all elements of the rvalue rv to c (since C++11)
c = initlist        |           Assigns all elements of the initializer list initlist to c (since C++11)
c1.swap(c2)         |           Swaps the data of c1 and c2
swap(c1, c2)        |           Swaps the data of c1 and c2

## Funções de iterator

Sets e multisets não fornecem acesso direto ao elemento, então você tem que usar um range-based for loop ou iterators. Sets e multisets
fornecem as usuais funções membros para iterators.

Operação         |       Efeito
-----------------|-------------------------------------------
c.begin()        |       Returns a bidirectional iterator for the first element
c.end()          |       Returns a bidirectional iterator for the position after the last element
c.cbegin()       |       Returns a constant bidirectional iterator for the first element (since C++11)
c.cend()         |       Returns a constant bidirectional iterator for the position after the last element (since C++11)
c.rbegin()       |       Returns a reverse iterator for the first element of a reverse iteration
c.rend()         |       Returns a reverse iterator for the position after the last element of a reverse iteration
c.crbegin()      |       Returns a constant reverse iterator for the first element of a reverse iteration (since C++11)
c.crend()        |       Returns a constant reverse iterator for the position after the last element of a reverse iteration (since C++11)


Como com todas as classes de contêineres associativos, os iterators são iterators bidimensional. Portanto, você não pode usa-los em
algoritmos que são fornecidos apenas para iterators de acesso aleatório/random-access iterators, tal como algoritmos para sorting ou
embaralhamento aleatório/random shuffling.
Mais importante é a limitação que, do ponto de vista do interator, todos os elementos são considerados constantes. Isto é necessário
para assegurar que você não possa comprometer a ordem dos elementos mudando seus valores. Embora, como um resultado, você não pode
chamar qualquer algoritmo modificador nos elements de um set ou multiset. Por exemplo, você não pode chamar o algoritmo `remove()`,
porque ele `remove` sobrescrevendo o elemento `removido` com os seguintes elementos. Para remover elementos em sets e multisets, você
pode apenas usar funções membros fornecidas pelo container.
                                                                                                                                 
## Inserir e remover elementos

Operação                            |          Efeito
------------------------------------|------------------------------------------------------------------------
c.insert(val)                       |          Inserts a copy of val and returns the position of the new element and, for sets, whether it succeeded
c.insert(pos,val)                   |          Inserts a copy of val and returns the position of the new element (pos is used as a hint pointing to where the insert should start the search)
c.insert(beg,end)                   |          Inserts a copy of all elements of the range (beg,end) (returns nothing)
c.insert(initlist)                  |          Inserts a copy of all elements in the initializer list initlist (returns nothing;  since C++11)
c.emplace(args...)                  |          Inserts a copy of an element initialized with args and returns the position of the new element and, for sets, whether it succeeded (since C++11)
c.emplace_hint(pos,args...)         |          Inserts a copy of an element initialized with args and returns the position of the new element (pos is used as a hint pointing to where the insert should start the search)
c.erase(val)                        |          Removes all elements equal to val and returns the number of removed elements
c.erase(pos)                        |          Removes the element at iterator position pos and returns the following position  (returned nothing before C++11)
c.erase(beg,end)                    |          Removes all elements of the range (beg,end) and returns the following position  (returned nothing before C++11)
c.clear()                           |          Removes all elements (empties the container)

                                                                                  
Como sempre quando usando STL, você deve garantir que os argumentos são válidos. Iterators devem se referir a posições válidas, e o
início de um range deve ter uma posição que não esteja após o fim do container. Inserir e remover é mais rápido se, quando trabalhando
com multiplos elementos, você use uma única chamada para todos os elementos ao invés de multiplas chamadas.
Para multisets, desde C++11 é garantido que `insert()`, `emplace()`, e `erase()` preservam a ordem relativa de elementos equivalentes,
e que inserção de elementos são colocados no final de valores equivalentes existentes. Note que os tipos de retorno das funções de 
inserção `insert()` e `emplace()` diferem no seguinte:

Sets fornece a seguinte interface:
                                                                                  
```cpp                                                                                  
pair<iterator,bool>           insert (const value_type& val);
           iterator           insert (const_iterator posHint,
                                      const value_type& val);
template <typename... Args>
pair<iterator, bool>          emplace (Args&&... args);
template <typename... Args>
iterator                      emplace_hint (const_iterator posHint,
                                            Args&&... args);
```                                         
                                            
• Multisets fornecem a seguinte interface:

```cpp                                                                
iterator                      insert (const value_type& val);
iterator                      insert (const_iterator posHint,
                                      const value_type& val);
template <typename... Args>
iterator                      emplace (Args&&... args);
template <typename... Args>
iterator                      emplace_hint (const_iterator posHint,
                              Args&&... args);
```

A diferença nos tipos de retrno resulta porque multisets permitem duplicatas, enquanto que sets não. Portanto, a inserção de um elemento
pode falir para um set se já existe um elemento com o mesmo valor. Portanto, um set retorna dois valores usando uma estrutura pair.

1. O segundo membro da estrutura pair retorna se a inserção foi bem sucedida.
2. O primeiro membro da estrutura pair retorna a posição do novo elemento inserido ou a posição de um elemento existente.

Em todos os outros casos, as funções retornam a posição do novo elemento ou de um elemento existente se o set já contém um elemento
com o mesmo valor.
Os seguintes exemplos mostram como usar esta interface para inserir um elemento em um set. Isto tenta inserir um elemento com valor
3.3 em um set:

```cpp
std::set<double> c;
...
if ( c.insert(3.3).second ) 
{
    std::cout << "3.3 inserted" << std::endl;
}
else {
    std::cout << "3.3 already exists" << std::endl;
}                           
```

se você quiser processar a nova e velha posição:

```cpp                                                                                  
// insere o valor e processa o retorno
auto status = c.insert(value);
if ( status.second ) 
{
    std::cout << value << " inserted as element "
}
else {
    std::cout << value << " already exists as element "
}
                                                                                  
std::cout << std::distance(c.begin(),status.first) + 1 << std::endl;
```

O output das 2 chamadas desta sequência pode as seguintes:

        8.9 inserted as element 4
        7.7 already exists as element 3

Neste exemplo, o tipo do status é o seguinte:
                                                                                  
```cpp
std::pair<std::set<float>::iterator, bool>
```

Observe que os tipos de retorno das funções de inserção com um parâmetro de posição adicional não são diferentes.
Essas funções retornam um único iterator para ambos, set e multiset. Embora, essas funções possuem o mesmo efeito que funções
sem o parâmetro de posição. Elas diferem apenas em suas performances. Você pode passa a posição de um iterator, mas esta posição
é processada como uma dica para otimiza a performance. De fato, se o elemento é inserido logo após a posição que é passada como
primeiro argumento, o tempo de complexidade muda de logaritmico para constante. O fato de que o tipo de retorno para funções de in-
serção com a posição adicional como argumento não ter a mesma diferença que as funções de inserção sem a posição como
argumento garante que você tem uma função de inserção que tem a mesma interface para todos os tipos de containers. De fato, esta
interface é usada por `inserters` gerais. Para remover um elemento que tem um certo valor, você simplesmente chama `erase()`:

```cpp
std::set<Elem> coll;
...
// remove todos os elementos com o valor passado
coll.erase(value);
```

Perceba que essa função membro tem um nome diferente de `remove()` fornecida por lists. erase se comporta diferentemente na medida em que
retorna o número de elementos removidos. Quando chamado por sets, ela retorna apenas 0 ou 1, pois não existem elementos equivalentes em
sets. Se um multiset contém duplicatas, você não pode usar `erase()` para remover apenas o primeiro elemento dessas duplicatas. Ao invés,
você pode usar o seguinte:

```cpp
std::multiset<Elem>::iterator pos;

pos = coll.find(value);
if (pos != coll.end()) 
{
    coll.erase(pos);
}
```

Pelo fato de ser mais rápido, você deve usar a função membro `find()` ao invés do algoritmo `find()`.
Perceba que antes C++11, as funções `erase()` de containers associativos não retornavam nada (tinha tipo de retorno void). A razão era
performance. Pode custar tempo para encontrar e retornar o sucessor em um container associativo, pois o container é implementado como
uma árvore binária. Portanto, este é um muito complicado código onde você apaga elementos enquanto itera sobre eles.
Oberve também que para sets que usam iteratos como elementos, chamar `erase()` pode ser 'ambiguous'. Por esta razão, C++11 fornece
sobrecargas para ambos erase(iterator) e erase(const_iterator). Para multisets, todas as operações `insert()`, `emplace()`, e `erase()`
preservam a ordem relativa dos elementos equivalentes. Desde C++11, chamar insert(val) ou emplace(args...) garante que o novo elemento
é inserido no final do range dos elementos equivalentes.
