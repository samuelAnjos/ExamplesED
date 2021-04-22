#include <stdio.h>
#include <stdlib.h>

int maximo = 30;
int quantidade = 0;

/*Fun��o que cria dinamicamente uma lista vazia*/
int* criaLista(){
    int *lista;
    lista = malloc(maximo * sizeof(int));
    if(lista)
        return lista;
    else{
        printf("\nAconteceu algum problema. A lista nao foi alocada.");
        exit(1);
    }
}

/*Fun��o que faz a inser��o de um elemento em uma lista n�o ordenada*/
int insereNaoOrd(int *lista){
    if(quantidade < maximo){
        printf("\nDigite um inteiro:");
        scanf("%d",&lista[quantidade++]);
        return 1;
    }
    return 0;
}

/*Fun��o que exibe a lista*/
void mostraLista(int *lista){
    for(int x=0; x<quantidade; x++){
        printf(" %5d ",lista[x]);
    }
}

/*Fun��o que faz pesquisa sequencial em lista n�o ordenada retornando o �ndice do elemento e
  -1 caso o elemento n�o seja encontrado*/
int pesqSequencial(int *lista, int chave){
    for(int x=0; x<quantidade; x++)
        if(chave == lista[x])
            return x;
    return -1;
}

/*Fun��o que faz a remo��o de um valor de uma lista n�o ordenada, caso o valor a ser removido
n�o seja encontrado a fun��o retorna 0*/
int removeNaoOrd(int *lista, int chave){
    int aux;
    aux = pesqSequencial(lista, chave);
    if(aux != -1){
        lista[aux] = lista[quantidade - 1];
        quantidade--;
        return 1;
    }
    return 0;
}

void main(){
    int* vetor;
    int op, aux, resp;
    vetor = criaLista();
    do{
        printf("\nEscolha uma opcao:");
        printf("\n1 - Insere elemento em lista nao ordenada");
        printf("\n2 - Pesquisa elemento em lista nao ordenada");
        printf("\n3 - Remocao nao ordenada");
        printf("\n5 - Exibe elementos da lista");
        printf("\n0 - Sair do programa");
        printf("\nDigite sua opcao:");
        scanf("%d",&op);
        switch(op){
        case 1:
            insereNaoOrd(vetor);
            break;
        case 2:
            printf("\n>  Digite o elemento a ser buscado:\n");
            scanf("%d",&aux);
            resp = pesqSequencial(vetor, aux);
            if(resp != -1)
                printf("\n>  Elemento encontrado na posicao %d\n",resp);
            else
                printf("\n>  Elemento nao encontrado\n");
            break;
        case 3:
            printf("\n>  Digite o elemento a ser removido:\n");
            scanf("%d",&aux);
            resp = removeNaoOrd(vetor, aux);
            if(resp)
                printf("\n>  Remocao realizada\n");
            else
                printf("\n>  Remocao nao realizada\n");
            break;
        case 5:
            mostraLista(vetor);
            break;
        case 0:
            printf("\n>  Encerrando programa.\n");
            break;
        default:
            printf("\n>  Opcao invalida!\n");
        }
    }
    while(op != 0);
    free(vetor);
}