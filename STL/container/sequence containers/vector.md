# Vector

- Random acess(por index)
- Lento na inserção e remoção no meio do container
- Rápido na inserção e remoção no final do container

- Os elementos são armazenados sequencialmente na memória, ou seja, permite acesso aleatório legítimo.

- Lento na inserção e remoção no meio do container, causam lentidão pois todos os outros elementos acima da posição inserida/deletada
  tem suas posições movidas.
    
- Rápido na inserção e remoção de elementos que estão no final do container pois não há elementos para serem movidos.



O metodo `capacity()` retorna a quantidade de elementos que o vetor suporta no momento, diferente do metodo size(), por exemplo,
se resevar-mos 10 espaços pro vector através do metodo `reserve()`, o metodo `size()` retornaria 0, enquanto o `capacity()` retornaria 
10.

A 'capacity' do vetor é importante por duas razões:

  1. Realocação inválida todas as referências, ponteiros, e iterators para elementos do vetor.
  2. Ralocação leva tempo.
  
  Uma maneira de evitar referências inválidas ou ponteiros inválidos é criar um vector de ponteiros para objeto ao invés
  de apenas objetos, isso também acaba com o problema de peso na realocação dos objetos, visto que apenas os endereços dos
  objetos seriam reajustados..
      
  Para evitar realocação, você pode usar `reserve()` para assegurar uma certa capacidade antes de você realmente precisar disto.
  Desta maneira, você pode ter certeza que referências permaneçam válidas enquanto a capacidade não for excedida.

  Basicamente o vector faz uma cópia do elemento quando o elemento é inserido, quando a capacidade do vector é excedida o vector
  vai recolocar todos os elementos em um array maior, então o construtor de cópia/move de todos os elementos são chamados, tornado
  assim a realocação uma operação pesada, use ponteiros ou smart pointers.
  
  ```js
  std::vector<int> v;  // cria um vetor vazio
  v.reserve(80);       // reserva memória para 80 elementos

  
  std::vector<some> vec;

  vec.push_back(something); // copy é chamado.
  vec.push_back(something); // copy é chamado e o vetor é realocado, sendo assim, o primeiro indice tem seu copy 
                            // chamado novamente pro novo array alocado.
  vec.push_back(something); // copy é chamado e o vetor é realocado, os 2 primeiros indices tem seus copy 
                            // chamados novamente..
  ```
  com total de 6 copys chamados..

  Uma outra maneira de evitar realocação é inicializar um vector com elementos suficiente passando um argumento adicional ao 
  construtor. Por exemplo, se você passa um valor númerico como parâmetro, isso é tomado como o tamanho inicial do vetor:

  ```js
  std::vector<T> vec(5);  // cria um vector e inicializa ele com 5 valores
                          // chama 5 vezes o construtor padrão de tipo T
  ```
 
  
## Construtores e destrutore do vetor
    
Operação                       |   Efeito
-------------------------------|-----------------------
vector<Elem> c                 |   Default constructor; creates an empty vector without any elements
vector<Elem> c(c2)             |   Copy constructor; creates a new vector as a copy of c2 (all elements are copied)
vector<Elem> c = c2            |   Copy constructor; creates a new vector as a copy of c2 (all elements are copied)
vector<Elem> c(rv)             |   Move constructor; creates a new vector, taking the contents of the rvalue rv (since C++11)
vector<Elem> c = rv            |   Move constructor; creates a new vector, taking the contents of the rvalue rv (since C++11)
vector<Elem> c(n)              |   Creates a vector with n elements created by the default constructor
vector<Elem> c(n,elem)         |   Creates a vector initialized with n copies of element elem
vector<Elem> c(beg,end)        |   Creates a vector initialized with the elements of the range [beg,end)
vector<Elem> c(initlist)       |   Creates a vector initialized with the elements of initializer list initlist (since C++11)
vector<Elem> c = initlist      |   Creates a vector initialized with the elements of initializer list initlist (since C++11)
c.~vector()                    |   Destroys all elements and frees the memory
 
                                                                                               
## Operadores não modificáveis
                                                                                               
Operação                      |    Efeito
------------------------------|------------------------
c.empty()                     |    Returns whether the container is empty (equivalent to size()==0 but might be faster)
c.size()                      |    Returns the current number of elements
c.max_size()                  |    Returns the maximum number of elements possible
c.capacity()                  |    Returns the maximum possible number of elements without reallocation
c.reserve(num)                |    Enlarges capacity, if not enough yet6
c.shrink_to_fit()             |    Request to reduce capacity to fit number of elements (since C++11)
c1 == c2                      |    Returns whether c1 is equal to c2 (calls == for the elements)
c1 != c2                      |    Returns whether c1 is not equal to c2 (equivalent to !(c1==c2))
c1 < c2                       |    Returns whether c1 is less than c2
c1 > c2                       |    Returns whether c1 is greater than c2 (equivalent to c2<c1)
c1 <= c2                      |    Returns whether c1 is less than or equal to c2 (equivalent to !(c2<c1))
c1 >= c2                      |    Returns whether c1 is greater than or equal to c2 (equivalent to!(c1<c2))                            

## Atribuição

Listas de maneiras para atribuir novos elementos.
                                                                                               
Operação                  |    Efeito
--------------------------|-------------------
c = c2                    |    Assigns all elements of c2 to c
c = rv                    |    Move assigns all elements of the rvalue rv to c (since C++11)
c = initlist              |    Assigns all elements of the initializer list initlist to c (since C++11)
c.assign(n,elem)          |    Assigns n copies of element elem
c.assign(beg,end)         |    Assigns the elements of the range (beg,end)
c.assign(initlist)        |    Assigns all the elements of the initializer list initlist
c1.swap(c2)               |    Swaps the data of c1 and c2
swap(c1,c2)               |    Swaps the data of c1 and c2                                                                                     

## Acesso aos elementos

Para acessar todos os elementos de um vector, você deve usar um range-base for loops, operações especificas, ou iterators.
Como geralmente em C e C++, o primeiro elemento tem índice 0, e o último elemento tem índice `size()` - 1. Embora o n ésimo
elemento tem índice n-1. Para vetores não constantes, essas operações retornam uma referência ao elemento. Porém, você poderia
modificar um elemento usando essas operações.
                                                                 
| Operação  | Efeito                                                                              
| --------- | ----------------------------------------------------------------------------------------
| c[idx]    | Returns the element with index idx (no range checking)                             
| c.at(idx) | Returns the element with index idx (throws range-error exception if idx is out of range) 
| c.front() | Returns the first element (no check whether a first element exists)                     
| c.back()  | Returns the last element (no check whether a last element exists)                                                                       
                                                                 
## Funções iterators                                                          
                                                                 
Iterators permanecem válidos até que um elemento com índice menor é inserido ou removido ou até que uma realocação ocorra e a 
capacidade mude.
                                                                 
| Operação    | Efeito                                                                                        
| ----------- | --------------------------------------------------------------------------------------------------
| c.begin()   | Returns a random-access iterator for the first element                                          
| c.end()     | Returns a random-access iterator for the position after the last element                        
| c.cbegin()  | Returns a constant random-access iterator for the first element (since C++11)                    
| c.cend()    | Returns a constant random-access iterator for the position after the last element (since C++11)   
| c.rbegin()  | Returns a reverse iterator for the first element of a reverse iteration                        
| c.rend()    | Returns a reverse iterator for the position after the last element of a reverse iteration        
| c.crbegin() | Returns a constant reverse iterator for the first element of a reverse iteration (since C++11)     
| c.crend     | Returns a constant reverse iterator for the position after the last element of a reverse iteration 
                                                                                                                                                                                                       
## Inserindo e removendo elementos                                                              
                                                                 
quando nós estamos usando STL, você deve assegurar que os argumentos são válidos. Iterators devem referir-se a posições válidos,
e o inicio de um rage deve ser uma posição que não esteja além do final.                                                        

Como de costume, cabe ao programador garantir que o container não esteja vazio quando pop_back() é chamado. Por exemplo:                                                              
    
```cpp                                                                 
std::vector<Elem> coll;   // vazio
                                                                 
coll.pop_back();          // RUNTIME ERROR ⇒ comportamento indefinido
                                                                 
if (!coll.empty()) 
{
    coll.pop_back();      // OK
}
```                                                                 

Embora, note que em um contexto multithread você tem que garantir que coll não seja modificado entre a checagem do empty() e
pop_back().

A respeito da performance, você deve considerar que inserção e remoção acontecem mais rápido quando:
                                                                 
• Elementos são inseridos ou removidos no final.
• A capacidade é grande o suficiente na entrada do elemento.
• Multiplos elementos são inseridos por uma única chamada ao invés de multiplas chamadas.

Inserção ou remoção de elementos invalidam referências, ponteiros, e iterators que referem-se ao seguintes elementos.
Uma inserção que causa uma realocação invalida todas as referências, iterators e ponteiros. Vector não provém operação
que remova diretamente elementos que tenham um certo valor. Você deve usar um algoritmo para isto.
      
Operação                 |        Efeito
-------------------------|----------------------------------------------------------------------------------------------------
c.push_back(elem)        |   Appends a copy of elem at the end
c.pop_back()             |   Removes the last element (does not return it)
c.insert(pos, elem)      |   Inserts a copy of elem before iterator position pos and returns the position of the new element
c.insert(pos, n, elem)   |   Inserts n copies of elem before iterator position pos and returns the position of the first new element (or pos if there is no new element)
c.insert(pos, beg, end)  |   Inserts a copy of all elements of the range (beg,end) before iterator position pos and returns the position of the first new element (or pos if there is no new element)                                         
c.insert(pos, initlist)  |   Inserts a copy of all elements of the initializer list initlist before iterator position pos and returns the position of the first new element (or pos if there is no new element; since C++11)                                                                                      
c.emplace(pos, args...)  |   Inserts a copy of an element initialized with args before iterator position pos and returns the position of the new element (since C++11)                                                                                  
c.emplace_back(args...)  |   Appends a copy of an element initialized with args at the end (returns nothing; since C++11)
c.erase(pos)             |   Removes the element at iterator position pos and returns the position of the next element
c.erase(beg, end)        |   Removes all elements of the range (beg,end) and returns the position of the next element
c.resize(num)            |   Changes the number of elements to num (if size() grows new elements are created by their default constructor)                         
c.resize(num, elem)      |   Changes the number of elements to num (if size() grows new elements are copies of elem)
c.clear()                |   Removes all elements (empties the container)                                               
