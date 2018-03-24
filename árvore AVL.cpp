//   Assunto: Árvore binária de busca
//      Site: https://www.youtube.com/watch?v=YkF76cOgtMQ&list=PLxI8Can9yAHf8k8LrUePyj0y3lLpigGcl&index=21 & 
//            https://www.youtube.com/watch?v=NUNe0Mp1MVI&index=22&list=PLxI8Can9yAHf8k8LrUePyj0y3lLpigGcl &
//            http://wiki.icmc.usp.br/images/f/fa/%C3%81rvores_AVL.pdf
//   Opinião: 
//      Data: 24/03/2018
//     Autor: Desconhecido
//       IDE: 

Árvore AVL é uma árvore binária de busca balanceada, ou seja, uma árvore balanceada(árvore completa) são as árvore que minimizam
o número de comparações efetuadas no pior caso para uma busca. Contudo, para garantir essa propriedade em aplicações dinâmicas, é
preciso reconstruir a árvore para seu estado ideal a cada operação sobre seus nós(inclusão ou exclusão).

-------------------------------------------------------------------------------------------------------------------------------------


- ALTURA DE UMA ÁRVORE : altura de uma árvore é o caminho mais longo até seu nó folha.

- ÁRVORE VAZIA POSSUI ALTURA -1.

- FATOR DE BALANCEAMENTO : [altura do filho à direita] - [altura do filho à esquerda] é denominado fator de balanceamento, quando 
                           um nó possui fator de balanço com valor -1, 0 ou 1 então o mesmo é um nó regulado.

- ROTAÇÃO : uma rotação ocorre devido ao desbalanceamento da árvore avl.

-----------------------------------------------------------------------------------------------------------------------

ROTAÇÃO SIMPLES:

Raiz de uma subárvore com FB -2 (ou 2) e um nó filho com FB -1 (ou 1).

 - Os fatores de balanceamento têm sinais iguais:
   * Subárvores de nó raiz e filho pendem para o mesmo lado, ou seja, se o nó que produz o desbalanceamento é filho de uma
     subárvore mais externa.

       8  -> desbalanceamento ocorrendo aqui.                
      / \         
     4   10           
    / \
   2   6
    \
     3  -> causando o desbalanceamento.
   
   no(8).FB = -2      no(4).FB = -1
   
   utilize rotação a direita:
   
        4
      /   \
     2     8
      \   / \
       3 6   10
     
 E foi agora pertence a A.
 B agora é o nó raiz.

Quando subárvores do pai e filho pendem para um mesmo lado:
* Rotação simples para o lado oposto

ABS:

em um caso como esse ->

       10
      /  
     7   
    / \ 
   4   8
 
 percebe que todos os valores a esquerda do nó 1 são menores que ele, então quando uma rotação à direita for executada,
 o nó 8 é adotado pelo nó 1, assim:
 
   7
 /   \
4     10
     /
    8
     
----------------------------------------------------------------------------------------------------------------------------

ROTAÇÃO DUPLA:

Raiz de uma subárvore com FB -2 (ou 2) e um nó filho com FB 1 (ou -1).

- Os fatores de balanceamento têm sinais opostos:
  * Subárvore de nó raiz pende para um lado e subárvore de nó filho pende para o outro (ou o contrário).


        8
       / \ 
      4   10
     / \
    2   6
       /
      5
      
      
 no(8).FB = -2      n(4).FB = 1
 
 Primeira rotação:
 
 - Rotação do nó filho do nó desbalanceado para a esquerda(nó 4):
 
 
        8
       / \ 
      6   10
     / 
    4   
   / \  
  2   5

 Segunda rotação:
 
 - Rotação do nó pai para a direita(nó 8):
 
        6
       / \ 
      4   8
     / \   \
    2   5   10
    
------------------------------------------------------------------------------------------------------------------------------------    
    
FUNÇÃO QUE RETORNA A ALTURA DE UMA SUBÁRVORE:    
    
int height(No *t) 
{
    if (t == NULL)
        return 0;
    else
        return max(height(t->left), height(t->right)) + 1;
}    

para entender a recursividade função eu tive que pegar a imagem deste link 
http://www.mathcs.emory.edu/~cheung/Courses/323/Syllabus/Trees/AVL-delete.html passei pro paint e fiquei tentando
entender, basta pensar que cada nó é uma função height..

FUNÇÃO DE ROTAÇÃO SIMPLES PARA À DIREITA:

No* right(No* root)
{
	No* aux;

	// essas 3 linhas seguintes executam uma 
	// rotação simples para direita
	aux      = root->left;
	r->esq   = aux->right;
	aux->dir = root;

	// essas linhas apenas atribuem as novas alturas dos nós
	// alterados
	root->height = max(height(root->right), height(aux->left)) + 1;
	aux->height  = max(height(aux->left), root->height) + 1;

	return aux;
}

FUNÇÃO DE ROTAÇÃO SIMPLES PARA À ESQUERDA:

No* left(No* root)
{
	No* aux;

	// essas 3 linhas seguintes executam uma 
	// rotação simples para direita
	aux       = root->right;
	r->right  = aux->left;
	aux->left = root;

	// essas linhas apenas atribuem as novas alturas dos nós
	// alterados
	root->height = max(height(root->right), height(aux->left)) + 1;
	aux->height  = max(height(aux->right), root->height) + 1;

	return aux;
}

FUNÇÃO DE ROTAÇÃO DUPLA DireitaEsquerda:

No* leftToRight(No* root)
{
	r->left = left(r->left);
	return right(r);
}

FUNÇÃO DE ROTAÇÃO DUPLA EsquerdaDireita:

No* leftToRight(No* root)
{
	r->right = right(r->right);
	return left(r);
}   

FUNÇÃO DE INSERÇÃO:


