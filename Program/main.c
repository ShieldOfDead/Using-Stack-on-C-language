#include "intStack.h"

Stack pilha1, pilha2, pilhaShow;

int main()
{
    //Iniciando pilhas
    Init(&pilha1);
    Init(&pilha2);

    //Declara��o de vari�veis
    int tipoItem, elem, i;

    //Empilhndo valores quaisquer na pilha1
    for (i=9; i>0; i--) {
        Push(&pilha1, i);
    };

    //Mostrar a pilha orignal
    for (i=9; i>0; i--) {
        Push(&pilhaShow, i);
    };

    //tipoItem recebe a posi��o do n�mero que deve ser removido
    tipoItem = 5;

    //Desempilhando pilha1 at� encontrar o valor requisitado
    while (tipoItem != elem) {
        elem = Pop(&pilha1);
        Push(&pilha2, elem);
    };

    //Descartando o n�mero
    elem = Pop(&pilha2);

    //Ap�s removido, os outros valores que foram colocados em pilha2 devem voltar para pilha1
    while (!isEmpty(&pilha2)) {
        elem = Pop(&pilha2);
        Push(&pilha1, elem);
    };
    i=0;
    while (i != 10) {
    if (elem < 10) {
        elem = Pop(&pilhaShow);
        printf("\n| %d |", elem);
        if (elem < 9) {
            elem = Pop(&pilha1);
            printf(" -> | %d |", elem);
        } else {
            break;
        }
    };

    i++;
    }
}
