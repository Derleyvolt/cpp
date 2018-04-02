
- random acess(por index)
- lento na inserção e remoção no meio do container
- rápido na inserção e remoção no final do container

1 - Os elementos são armazenados sequencialmente na memória, ou seja, permite acesso aleatório legitimo.

2 - Lento na inserção e remoção no meio do container causam lentidão pois todos os outros elementos acima da posição inserida/deletada
    tem suas posições movidas.
    
3 - rápido na inserção e remoção de elementos que estão no final do container pois não há elementos para serem movidos.





o metodo capacity() retorna a quantidade de elementos que o vetor suporta no momento, diferente do metodo size(), por exemplo,
se resevar-mos 10 espaços pro vector através do metodo reserve(), o metodo size() retornaria 0, enquanto o capacity() retornaria 10.

A 'capacity' do vetor é importante por duas razões:

  1. Realocação invalida todas as referências, ponteiros, e iterators para elementos do vetor.
  2. Ralocação leva tempo.
  
  para evitar realocação, você pode usar reserve() para assegurar uma certa capacidade antes de você realmente precisar disto.
  Desta maneira, você pode ter 
  To avoid reallocation, you can use reserve() to ensure a certain capacity before you really need
it. In this way, you can ensure that references remain valid as long as the capacity is not exceeded:
std::vector<int> v; // create an empty vector
v.reserve(80); // reserve memory for 80 elements

 







