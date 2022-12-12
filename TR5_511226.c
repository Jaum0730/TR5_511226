#include <stdio.h>
#include <stdlib.h>

#ifndef HEAP_H
#define HEAP_H

/*Definicao do tipo de funcao a ser utilizado para comparacao
Esta funÃ§Ã£o recebe dois valores x e y e retorna

1 : se x Ã© menor que y.
0 : se x Ã© equivalente a y.
-1: se x Ã© maior que y na ordem.

*/
typedef int COMP(void* x, void* y);

//Uma Heap estatico. Os elementos do vetor estao colocadoo no vetor
//de acordo com a ordem indicada por comparador.
typedef struct heap{
	int N;//tamanho do vetor
	int P;//numero de elementos no vetor
	void** elems;//o vetor de elementos
	COMP* comparador;//a funcao de comparacao
}HEAP;

/**
Cria um heap vazio de tamanho n e com funcao de comparacao compara

@param n: o tamanho do heap
@param compara: a funcao de comparacao

@return um ponteiro para uma estrutura HEAP, observe que este ponteiro ja
deve apontar para a estrutura, ou seja, a alocacao de memoria deve ser feita nele.
*/
//agiliza algumas coisas
//faz a troca de variaveis
void swap(void * a, void * b){
	void * aux; 
	aux = a;
	a = b;
	b = aux;

}




HEAP* HEAP_create(int n, COMP* compara){
HEAP * pont_heap =malloc(sizeof(HEAP));
pont_heap->N = n;
pont_heap->P = 0;
pont_heap->elems = malloc(sizeof(void) * n);
pont_heap->comparador = compara;

return pont_heap;
}





/**
Adiciona o elemento newelem ao Heap, na posicao correta se for possÃ­vel
ainda incluir o elemento (se existe espaco no vetor elems). Observe que 
a estrutura deve respeitar a regra da heap, ou seja, para todo i temos que 
x[i] Ã© menor que ou equivalente a x[2*i] e a x[2*i+1].

@param heap: o heap a ter o elemento incluÃ­do
@param newelem: o elemento a ser adicionado
*/
void HEAP_add(HEAP* heap, void* newelem){
	if (heap->P == heap->N) {
	printf("Heap cheio!\n");
	return;
	}
	heap->elems[heap->P] = newelem;
	heap->P++;
	//o index agira como a posicao em vet estatico
	int index = heap->P - 1;
	int index_son = (index -1)/2;
		while (index != 0 && heap->comparador(heap->elems[index], heap->elems[index_son]) ==-1) {
			//aqui eh feita troca do pai e do filho
			void *ptr_1 = heap->elems[index];
			void *ptr_2 = heap->elems[(index - 1) / 2];	
			void swap(void*ptr1, void*ptr2);
			
			index = index_son;
			
			
		}
}

/**
Remove o menor elemento do heap, de acordo com a funcao compara

@param heap: o heap a ter seu elemento removido

@return um ponteiro para o elemento que foi removido do heap.
*/
void* HEAP_remove(HEAP* heap){
	//verifica se a heap estah vazia ou nao
	if (heap->P <= 0) {
		printf("Heap vazio!");
		return NULL;
	}
	//busca pelo menor elemento
	int position = heap->P / 2;
	void* minimum = heap->elems[position];
		for (int index = position + 1; index < heap->P; index++) {
			//verifica se o elemento do index eh menor que o minimo e oh substitui
			//depois armazena 
			if (heap->comparador(heap->elems[index], minimum) > 0) {
				minimum = heap->elems[index];
				position = index;
			}
		}
	//guarda os elementos para troca	
	void* ptr_1 = heap->elems[heap->P - 1];
	void* ptr_2 = heap->elems[position];
	swap(ptr_1,ptr_2);
		//verifica se o elemento da outra metade eh o minimo 
		
		while (heap->comparador(heap->elems[position], heap->elems[(position - 1 / 2)]) < 0) {
			void* newptr = heap->elems[position];
			void* newptr2 = heap->elems[(position - 1) / 2];
			//reordenando a heap
			swap(newptr, newptr2);
			position = (position - 1) / 2;
			heap->P--;
		}
return minimum;


}

#endif
