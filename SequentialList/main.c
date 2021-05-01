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

// adding to ordered list

int addingOrderedList(int *lista, int elementToBeInserted){

    int i = quantidade;
    if(quantidade < maximo){
       while((i >0) && (elementToBeInserted < lista[i-1])){
          lista[i] = lista[i-1];
          i--;
       }

       lista[i] = elementToBeInserted;
       quantidade++;
       return 1;

        }
       return 0;
}


// Delete from an ordered list
int deleteFromAnOrderedLis(int *lista, int element){
    int number = pesqSequencial(lista, element);
    if(quantidade>=0){
    while(number<quantidade-1){
       lista[number] = lista[number+1];
       number++;
     }
    quantidade--;
    return 1;
   }
   return 0;
}

int pesquisaBinaria(int *lista, int valorHaSerPesquisdo){
    int inicio=0, meio, fim=quantidade-1;

    while(inicio<=fim){
        meio=(inicio+fim)/2;
        if(valorHaSerPesquisdo==lista[meio]){
           return meio;
        }else if(valorHaSerPesquisdo<lista[meio]){
            fim = meio-1;
        }else{
            inicio = meio+1;
        }
    }
    return -1;
}

void main(){
    int* vetor;
    int op, aux, resp;
    vetor = criaLista();
    do{
        printf("\nEscolha uma opcao: >>");
        printf("\n1 - Insere elemento em lista nao ordenada");
        printf("\n2 - Pesquisa elemento em lista nao ordenada");
        printf("\n3 - Remocao nao ordenada");
        printf("\n4 - Inserir em lista ordenada");
        printf("\n5 - Apagar elementos da lista ordenada");
        printf("\n6 - Pesquisa binaria");
        printf("\n7 - Exibe elementos da lista");
        printf("\n0 - Sair do programa");
        printf("\nDigite sua opcao:");
        scanf("%d",&op);
        switch(op){
        case 1:
            insereNaoOrd(vetor);
            break;
        case 2:
            printf("\n>  Digite o elemento a ser buscado: >\n");
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
        case 4:

                printf("\n>  Digite o elemento a ser inserido de forma ordenada: >\n");
                scanf("%d",&aux);
                resp = addingOrderedList(vetor, aux);
            if(resp)
                printf("\n>  Adicao realizada com sucesso\n");
            else
                printf("\n>  Adicao nao realizada\n");

            break;
          case 5:

                printf("\n>  Digite o elemento a ser removido de forma ordenada:\n");
                scanf("%d",&aux);
                resp = deleteFromAnOrderedLis(vetor, aux);
            if(resp)
                printf("\n>  Remocao realizada com sucesso\n");
            else
                printf("\n>  Remocao nao realizada\n");

            break;

        case 6:
            printf("\n>  Digite o elemento a ser pesquisado : >\n");
            scanf("%d",&aux);
            resp = pesquisaBinaria(vetor, aux);
            if(resp)
                printf("\n>  Elemento encontrado na posicao: %i", resp);
            else
                printf("\n>  Elemento nao encontrado\n");
            break;
        case 7:
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
