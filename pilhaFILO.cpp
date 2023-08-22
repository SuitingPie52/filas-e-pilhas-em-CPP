/////////////////////////////////////////////
// Programa que Implementa uma PILHA FILO //
///////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

struct no {	
	int numero;
	struct no *proximo;
};

struct no *cabeca = NULL;



void push (int numero) { // inserir um No na pilha
	
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = cabeca;
	cabeca = novoNo;
	
}

int top () {
	
	int retorno = 0;
	
	if (cabeca != NULL) {
		
		retorno = cabeca -> numero;
		
	} else {
		
		printf("Lista vazia, nao existe um numero no topo.\n");
		
	}
	
	return retorno;
	
}

int pop () {
	
	int retorno = 0;
	
	if (cabeca != NULL) {
		
		retorno = cabeca -> numero;
		
		struct no *temp = cabeca;
		cabeca = temp -> proximo;
		free(temp);
		
	} else {
		
		printf("Lista vazia, nao existe um numero no topo.\n");		
		
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
	
	
	imprimir();
	
	printf("\n=================================\n");
	
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	
	printf("%d\n", top());
	
	pop();
	
	printf("%d\n", top());
	
	imprimir();
		
}

