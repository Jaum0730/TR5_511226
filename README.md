# TR5_511226
#Baixe o arquivo .c

#Com o arquivo na sua maquina você terá que fazer um .h declarando as respectivas "typedef int COMP(void* x, void* y), 
typedef struct heap{
	int N;//tamanho do vetor
	int P;//numero de elementos no vetor
	void** elems;//o vetor de elementos
	COMP* comparador;//a funcao de comparacao
}HEAP; , 
void swap(void * a, void * b, void* newelem), HEAP* HEAP_create(int n, COMP* compara), void HEAP_add(HEAP* heap, void* newelem), void* HEAP_remove(HEAP* heap)"


#Para compilar este codigo .c vá na pasta em que ele esta localizado abra o terminal linux na pasta respectiva pasta e digite: gcc TR4_511226.c -o prog1

#Com as funcoes declaradas em um arquivo .h basta apenas chamar essa biblioteca(por exemplo: #include "nome_biblioteca") em sua main e codigo funcionara normalmente
