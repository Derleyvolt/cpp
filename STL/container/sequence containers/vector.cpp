
- random acess(por index)
- lento na inserção e remoção no meio do container
- rápido na inserção e remoção no final do container

1 - Os elementos são armazenados sequencialmente na memória, ou seja, permite acesso aleatório legitimo.

2 - Lento na inserção e remoção no meio do container causam lentidão pois todos os outros elementos acima da posição inserida/deletada
    tem suas posições movidas.
    
3 - Rápido na inserção e remoção de elementos que estão no final do container pois não há elementos para serem movidos.



O metodo capacity() retorna a quantidade de elementos que o vetor suporta no momento, diferente do metodo size(), por exemplo,
se resevar-mos 10 espaços pro vector através do metodo reserve(), o metodo size() retornaria 0, enquanto o capacity() retornaria 10.

A 'capacity' do vetor é importante por duas razões:

  1. Realocação inválida todas as referências, ponteiros, e iterators para elementos do vetor.
  2. Ralocação leva tempo.
  
  Para evitar realocação, você pode usar reserve() para assegurar uma certa capacidade antes de você realmente precisar disto.
  Desta maneira, você pode ter certeza que referências permaneçam válidas enquanto a capacidade não for excedida.

  Basicamente o vector faz uma cópia do elemento quando o elemento é inserido, quando a capacidade do vector é excedida o vector
  vai recolocar todos os elementos em um array maior, então o construtor de cópia/move de todos os elementos são chamados, tornado
  assim a realocação uma operação pesada, use ponteiros ou smart pointers.
      
  std::vector<int> v;  // cria um vetor vazio
  v.reserve(80);       // reserva memória para 80 elementos

  
  std::vector<some> vec;

  vec.push_back(something); // copy é chamado.
  vec.push_back(something); // copy é chamado e o vetor é realocado, sendo assim, o primeiro indice tem seu copy chamado novamente
                            // pro novo array alocado.
  vec.push_back(something); // copy é chamado e o vetor é realocado, os 2 primeiros indices tem seus copy chamados novamente..

  com total de 6 copys chamados..

 







