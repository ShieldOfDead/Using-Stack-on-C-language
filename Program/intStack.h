#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct Stack {
	int stack[MAX];
	int top;
};

typedef struct Stack Stack; // Substitui "struct Stack" pela variavel "Stack"

void Init(Stack *s){ // Inicializa uma pilha
	s->top = -1;
}

bool isEmpty(Stack *s){ // Verifica se a pilha está vazia
	return s->top == -1;
}

bool isFull(Stack *s){ // Verifica se a pilha está cheia
	return s->top + 1 == MAX;
}

int getSize(Stack *s){ // Retorna o numero de elementos em uma pilha
	return s->top + 1;
}

bool Push(Stack *s, int element){ // Empilha um elemento
	if( !isFull(s) ){
		s->top++;
		s->stack[s->top] = element;
		return true;
	}
	return false;
}

int Pop(Stack *s){ // Desempilha e retorna um elemento
	if( !isEmpty(s) ){
		return s->stack[s->top--];
	};
}

bool Show(Stack *s){ // Mostra a pilha
    int i;
	if( !isEmpty(s) ){
		printf("[");
		if (s->top == 0){
			printf("%d", s->stack[0]);
		}else{
			for(i = 0; i < getSize(s) - 1; i++){
				printf("%d, ", s->stack[i]);
			}
			printf("%d", s->stack[s->top]);
		}
		printf("]\n");
		return true;
	}
	return false;
}

bool Capacity(Stack *s) { //Retorna a capacidade máxima da pilha
    return MAX;
}

#endif
