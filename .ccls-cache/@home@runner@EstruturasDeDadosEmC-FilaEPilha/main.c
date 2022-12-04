#include <stdio.h>
#include <stdlib.h>

struct pessoa {
	int senha;
	struct pessoa *prox;
};

typedef struct pessoa Pessoa;

Pessoa *fila;

void add(int senha){
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

void remover(){
	if(fila==NULL){
		printf("A fila está vazia.");
	} else{
		fila = fila->prox;
	}
}

void imprime(Pessoa *f){
	if(f!=NULL){
		printf("Senha da Pessoa: %d \n", f->senha);
		imprime(f->prox);
	}
}

int main() {
  add(45);
	add(12);
	add(123456);

	Pessoa *filaAux = fila;
	imprime(filaAux);

	remover();
	filaAux = fila;
	remover();
	filaAux = fila;
	printf("\n");
	imprime(filaAux);
  return 0;
}