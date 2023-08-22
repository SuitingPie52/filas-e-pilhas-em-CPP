///////////////////////////////////////////////////
//   Programa que implementa uma Fila FIFO      //
// A fila implementada tem a entrada no final  // 
////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

struct no {	
	int numero;
	struct no *proximo;
};

struct no *cabeca = NULL; 

void inserir (int numero) {
	
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = NULL;
	
	if (cabeca != NULL) {
	
		struct no *ultimo = cabeca; 
		
		while (ultimo -> proximo != NULL) {
		
			ultimo = ultimo -> proximo;
		
		}

		ultimo -> proximo = novoNo;

	} else {
		
		cabeca = novoNo;
		
	}
	
}

void imprimir () {
	
	struct no *ponteiro = cabeca;
	
	while (ponteiro != NULL) {
		
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
		
	}
	
}

int remover () {
	
	int retorno = 0;
	
	if (cabeca != NULL) {
		
		struct no *remover = cabeca;
		retorno = remover -> numero;
		
		cabeca = cabeca -> proximo;
		free(remover);
		
	} else {
		
		printf("Lista vazia, voce nao removeu ninguem.\n");
		
	}
	
	return retorno;
	
}

int main() {
	
	imprimir();
	
	printf("\n===========================================\n");
	
	inserir(1);
	inserir(2);
	inserir(3);
	inserir(4);
	inserir(5);
	
	imprimir();
	
	printf("\n===========================================\n");
	
	printf("%d\n", remover());
	printf("%d\n", remover());
	printf("%d\n", remover());
	
	printf("\n===========================================\n");
	
	imprimir();
	
	
}
