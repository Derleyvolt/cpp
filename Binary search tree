//   Assunto: Árvore binária de busca
//      Site: https://www.geeksforgeeks.org/find-the-minimum-element-in-a-binary-search-tree/ & 
//            https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/ &
//            https://www.youtube.com/watch?v=gcULXE7ViZw      
//   Opinião: 
//      Data: 19/03/2018
//     Autor: 
//       IDE: 



MENOR VALOR DE UMA ÁRVORE BINÁRIA DE BUSCA: 

É bastante simples. Apenas percorra a árvore da raiz até o nó esquerdo recursivamente até encontrar um nó esquerdo null.
O nó cujo o membro left seja null é o nó que contém o menor valor..

int minValue(node* root) 
{
   node* current = root;
 
   while (current->left != NULL) 
   {
      current = current->left;
   }
  
   return(current->data);
}



BUSCAR UM ELEMENTO EM UMA ÁRVORE BINÁRIA DE BUSCA:

Para procurar um dado valor em uma árvore binária de busca, nós primeiros comparamos o valor com a raiz,
se o valor está presente na raiz, nós retornamos a raiz. Se o valor é maior do que a raiz, nós repetimos
o processo na subarvore a direita do nó raiz. Por outro lado nós repetimos o processo na subarvore a esquerda
do nó raiz.

node* search(node* root, int key)
{
    if (root == NULL || root->key == key)
       return root;
   
    if (root->key < key)
       return search(root->right, key);
 
    return search(root->left, key);
}

INSERIR UM ELEMENTO EM UMA ÁRVORE BINÁRIA DE BUSCA: https:

Uma nova chave sempre é inserida em um nó folha. Nós começamos procurando a chave da raiz até encontrarmos um nó
folha. Quando o nó folha é encontrado, um novo nó é adicionado a ele.

	void insert(No* root, int key)
	{
		if ( key < root->getKey() )
		{
			if ( root->getLower() == nullptr )
			{
				No* root = new No(key);
				root->setLower(root);
			}
			else
				insert(root->getLower(), key);
		}
		else if ( key > root->getKey() )
		{
			if ( root->getUpper() == nullptr )
			{
				No* root = new No(key);
				root->setUpper(root);
			}
			else
				insert(root->getUpper(), key);
		}
	}

DELETANDO UM NÓ DA ÁRVORE BINÁRIA DE BUSCA:

Essa é a operação mais complexa, existem três cenários neste caso:

1 - O nó que será deletado é um nó folha:

    Simplesmente o remova da árvore.
    
2 - O nó que será deletado tem apenas um filho:

    Copie o filho pro nó e depois delete o nó filho.
    
3 - O nó que será deletado tem dois filhos:

    Encontre o valor minimo da subarvore a direita, substitua pelo nó que será deletado e depois o delete.
    
    
 ELEMENTOS DA ÁRVORE BINÁRIA DE BUSCA:
 
 
 Nó           - Valores que a árvore possui.
 Grau         - Os nós de uma árvore binária possuem grau zero, um ou dois.
 Folha        - Um nó de grau zero é denomiado folha.
 Raiz         - É o primeiro nó da árvore.
 Subarvore    - Cada nó aponta pra uma subarvore a esquerda ou a direita.
 Profundidade - A profundidade de um nó é a distância deste nó até a raiz.

 Uma árvore binária de busca precisa ter as seguintes caracteristicas: 
 
 - Os elementos da subarvore a esquerda são sempre menores que a raiz.
 - Os elementos da subarvore a direita são sempre maiores que a raiz.
 - As chaves devem ser únicas.



