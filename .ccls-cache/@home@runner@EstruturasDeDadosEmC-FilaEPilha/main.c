#include <stdio.h>
#include <stdlib.h>

struct pessoa {
	int senha;
	struct pessoa *prox;
};

struct prato {
	char cor;
	struct prato *prox;
};

typedef struct pessoa Pessoa;

typedef struct prato Prato;

Pessoa *fila;

Prato *pilha;

void addFila(int senha){
	Pessoa *p = (Pessoa*)malloc(sizeof(Pessoa));
	p->senha = senha;
	p->prox = NULL;
	
	if(fila==NULL){
		fila = p;
	}else{
		Pessoa *filaAux = fila;
		while(filaAux->prox!=NULL){
			filaAux = filaAux->prox;
		}
		filaAux->prox = p;
	}
}

void addPilha(char cor){
	Prato *p = (Prato*)malloc(sizeof(Prato));
	p->cor = cor;	
	p->prox=pilha;
	pilha = p;
	
}

void removerFila(){
	if(fila==NULL){
		printf("A fila está vazia.");
	} else{
		fila = fila->prox;
	}
}

void removerPilha(){
	if(pilha==NULL){
		printf("A pilha está vazia.");
	} else{
		pilha = pilha->prox;
	}
}

void imprimeFila(Pessoa *f){
	if(f!=NULL){
		printf("Senha da Pessoa: %d \n", f->senha);
		imprimeFila(f->prox);
	}
}

void imprimePilha(Prato *p){
	if(p!=NULL){
		printf("Cor do prato: %c \n", p->cor);
		imprimePilha(p->prox);
	}
}

int main() {
  	addFila(45);
	addFila(12);
	addFila(123456);	

	Pessoa *filaAux = fila;	
	
	imprimeFila(filaAux);	

	removerFila();
	filaAux = fila;
	removerFila();
	filaAux = fila;
	printf("\n");
	imprimeFila(filaAux);

	addPilha('a');
	addPilha('v');
	addPilha('m');

	Prato *pilhaAux = pilha;	

	removerPilha();

	pilhaAux = pilha;

	imprimePilha(pilhaAux);

	
  return 0;
}