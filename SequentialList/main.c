#include <stdio.h>
#include <stdlib.h>

int maximo = 30;
int quantidade = 0;

/*Função que cria dinamicamente uma lista vazia*/
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

/*Função que faz a inserção de um elemento em uma lista não ordenada*/
int insereNaoOrd(int *lista){
    if(quantidade < maximo){
        printf("\nDigite um inteiro:");
        scanf("%d",&lista[quantidade++]);
        return 1;
    }
    return 0;
}

/*Função que exibe a lista*/
void mostraLista(int *lista){
    for(int x=0; x<quantidade; x++){
        printf(" %5d ",lista[x]);
    }
}

/*Função que faz pesquisa sequencial em lista não ordenada retornando o índice do elemento e
  -1 caso o elemento não seja encontrado*/
int pesqSequencial(int *lista, int chave){
    for(int x=0; x<quantidade; x++)
        if(chave == lista[x])
            return x;
    return -1;
}

/*Função que faz a remoção de um valor de uma lista não ordenada, caso o valor a ser removido
não seja encontrado a função retorna 0*/
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
