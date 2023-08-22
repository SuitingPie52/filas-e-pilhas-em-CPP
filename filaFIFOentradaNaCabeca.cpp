 ///////////////////////////////////////////////////
 //   Programa que implementa uma Fila FIFO      //
 // A fila implementada tem a entrada na cabeça // 
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
	novoNo -> proximo = cabeca;
	cabeca = novoNo;
	
}

int remover () {
	
	struct no *ponteiroPenultimo = cabeca;
	int retorno = 0;
	
	if (cabeca != NULL) {
	
		if (cabeca -> proximo == NULL) {
			
			retorno = cabeca -> numero;
			free(cabeca);
			cabeca = NULL;
			
		} else {
			
			while (ponteiroPenultimo -> proximo -> proximo != NULL) {
				
				ponteiroPenultimo = ponteiroPenultimo -> proximo;
				
			}
			
			retorno = ponteiroPenultimo -> proximo -> numero;
			free(ponteiroPenultimo -> proximo);
			ponteiroPenultimo -> proximo = NULL;
			
		}
	
	} else {
		
		printf("Lista vazia, voce nao removeu ninguem.\n");
		
	}
	
	return retorno;
	
}

void imprimir () {
	
	struct no *ponteiro = cabeca;
	
	while (ponteiro != NULL) {
		
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
		
	}
	
}

int main () {

	printf("%d\n", remover());
	imprimir();	
	
	printf("====================\n\n");
	
	inserir(1);
	inserir(2);
	inserir(3);
	inserir(4);
	
	imprimir();
	
	printf("====================\n\n");
	
	remover();
	remover();
	
	imprimir();

	printf("====================\n\n");	

	printf("%d\n", remover());
	printf("%d\n", remover());

}
