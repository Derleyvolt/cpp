//   Assunto: Busca binária
//     Fonte: https://www.hackerearth.com/practice/algorithms/searching/binary-search/tutorial/
//   Opinião: Melhor site que encontrei explicando o algoritmo
//      Data: 17/03/2018
//     Autor: Desconhecido
//       IDE: Visual Studio 2017

#include "stdafx.h"
#include <iostream>

using namespace std;

int binary_s(int vec[], int size, int search_num)
{
	int low  = 0;          // aqui é o lower bound do vetor
	int high = size - 1;   // aqui é o upper bound do vetor

	while ( low <= high )  // equanto low for menor que high, significa que ainda é possível dividir o vetor
	{                      // em busca da key

		int mid = (low + high) / 2;

		if ( vec[mid] < search_num )
		{
			low = mid + 1;
		}
		else if ( vec[mid] > search_num )
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}

	return -1;
}

int main()
{
	int arr[] = { 14, 22, 37, 43, 57, 78, 98, 102, 245 };

	std::cout << binary_s(arr, 9, 97) << std::endl;

	getchar();
    return 0;
}

// Requesito do algoritmo: os valores precisam estar ordenados.
//
// O algoritmo consiste basicamente em dividir o array ao meio e comparar se o valor da key é maior ou menor
// do que o valor que está no meio, caso seja maior, a segunda metade do array é esquecida, caso seja menor, a
// primeira metade do array é esquecida, e o processo se repete com a metade remanescente até que o valor seja
// encontrado, e seu indice retorne, caso contrário, a função retorna -1.

