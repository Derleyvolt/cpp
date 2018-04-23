**Acesso sequencial**: significa que o custo de acessar o quinto elemento de um vetor é 5 vezes maior de que acessar o primeiro elemento.
Basicamente para você ter acesso ao quinto elemento, é necessario passar por todos os outros quatro elementos antes de acessar o quinto,
dessa forma, quanto maior for o vetor, maior será o tempo de busca.

**Acesso aleatório**: significa que o custo de acessar o quinto elemento é o mesmo de que acessar o primeiro ou qualquer outro elemento 
em um dado vetor. Encontrar o quinto elemento de um vetor/array é necessario apenas uma 'operação', ao contrário do acesso sequencial.


Exemplo de acesso aleatório:

pegando elementos, independente da ordem ou sequencia.
o fator importante é que nós estamos selecionando itens por algum tipo de index.

```cpp
auto a = container[25];
auto b = container[1];
auto c = container["hi"];
```

Observações:

é importante notar que o termo "sequencial" pode se referir a armazenamento ou acesso. Por exemplo:

`std::vector` é um container com armazenamento sequencial e com acesso aleatório, enquanto `std::list` é um container
de armazenamento sequencial e acesso sequencial. 
