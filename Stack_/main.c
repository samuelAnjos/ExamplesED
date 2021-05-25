#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proxNo;
}tipoNo;

typedef struct listaGerenciadora{ // Since we are in this area we go up with humility
    tipoNo *topo;
    int qtadade;
}tipoLista;

void stack_inicializar(tipoLista *lista){
    lista->topo = NULL;
    lista->qtadade = 0;
}

int stack_push(tipoLista *lista, int valor){ // empilhar
    tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));

    if(novoNo == NULL){
        return 0;
    }else{
        novoNo->valor = valor;
        novoNo->proxNo = lista->topo;

        lista->topo = novoNo;
        lista->qtadade++;
        return 1;
    }
}

int stack_vazia(tipoLista *lista){
    if(lista->topo==NULL)
        return 1;

    return 0;
}

int stack_pop(tipoLista *lista){ // desempilhar e retornar valor
    tipoNo *temp;
    int retorno;

    if(stack_vazia(lista)){        /* Essa funcao pode ser separada de acordo com SLIDE*/
        return 0;
    }else{
        retorno = lista->topo->valor; // temp->valor;
        temp = lista->topo; // guarda o topo para apagar de forma segura
        lista->topo = lista->topo->proxNo; // topo aponta para o proximo
        temp->proxNo = NULL;    //entigo no nao aponta mais para a pilha

        free(temp);
        lista->qtadade--;
        return retorno;
    }
}

int main(){

    tipoLista lista;
    int aux = 12, x2 = 56, x3 = 20;

    stack_inicializar(&lista);
    stack_push(&lista, aux);
    stack_push(&lista, x2);
    stack_push(&lista, x3);
    printf("%d", aux = stack_pop(&lista));


    return 0;
}
