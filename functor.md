# Functor

A habilidade de tratar funções como valores, combinada com o fato de que variáveis locais são recriadas toda vez que uma função é invocada; isso traz à tona uma questão interessante.

O que acontece com as variáveis locais quando a função que as criou não está mais ativa?

O código a seguir mostra um exemplo disso. Ele define uma função wrapValue que cria uma variável local e retorna uma função que acessa e retorna essa variável.

Functions (function objets ou functionals) é simplesmente um objeto + ().
  
Em outras palavras, um functor é qualquer objeto que pode ser usado com () da meneira que uma função..

Isto inclue funções normais, ponteiros para funções, e classes no qual o operator() (operador de chamada de função) é sobrecarregado,
ou seja, classes que possuem a função operator()() definida.

Ás vezes nós podemos usar uma função objeto quando uma função ordinária não funciona. O stl frequetemente usa funções objetos e fornecem
várias funções objetos que são muito úteis.
  
Funções objetos são uma outro exemplo do poder de programação genérica e o conceito de abstração pura. Nós poderiamos dizer que tudo
que se comporta como uma função é uma função. Então, se nós definir-mos um objeto que se comporta como uma função, isso pode ser usado
como uma função.

Por exemplo, nós poderiamos definir uma struct nomeada como absValue que encapsula a operação de converter um valor de tipo float para
seu absoluto valor:
  
```cpp
#include <iostream>

struct absValue
{
    float operator()(float f) 
    {
        return f > 0 ? f : -f;
    }
};

int main( ) 
{ 
    using namespace std;

    float f = -123.45;
    absValue aObj;
    float abs_f = aObj(f);
    cout << "f = " << f << " abs_f = " << abs_f << endl;
    return 0; 
}
```

`output: f = -123.45 abs_f = 123.45`
  
  
Sendo bem direto, as vantagens que uma função objeto tem sobre uma função normal é o fato de que uma função objeto pode ter várias
outras funções membros e atributos. Isso significa que uma função objeto tem um stado.
  
Toda função objeto tem seu próprio tipo, oque não é verdade para uma função comun, funções comuns só tem um tipo diferente se suas
assinaturas são diferentes, onde funçoes objetos tem tipos diferentes mesmo quano suas assinaturas diferem.
  
Funções objetos são geralmente mais rapidas do que funções comuns. O conceito de template permite melhor otimização pois mais detalhes
são definidos em tempo de compilação.
  
[Fonte](http://www.bogotobogo.com/cplusplus/functors.php)  
 
