#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *antNo;
    struct no *proxNo;
}tipoNo;

typedef struct gerenciadora{
    tipoNo *inicio;
    tipoNo  *fim;
    int qtdade;
}tipoLista;

void inicializarValoresDaLista(tipoLista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtdade = 0;
}

int inserirListaVazia(tipoLista *lista, int valor){
    tipoNo *novoNo;
    novoNo = (tipoNo *) malloc(sizeof(tipoNo));

    if(novoNo == NULL){
        return 0;
    }else{
        novoNo->dado = valor;
        novoNo->antNo = NULL;
        novoNo->proxNo = NULL;
        lista->fim = novoNo;
        lista->inicio = novoNo;
        lista->qtdade++;
        return 1;
    }
}

int inserirfrente(tipoLista *lista, int valor){
    tipoNo *novoNo;
    if(lista->inicio == NULL){
        inserirListaVazia(lista, valor);
    }else{
      novoNo = (tipoNo *) malloc(sizeof(tipoNo));
      if(novoNo == NULL)
         return 0;
      novoNo->dado = valor;//
      novoNo->proxNo = lista->inicio;//
      novoNo->antNo = NULL;//
      lista->inicio->antNo = novoNo;
      lista->inicio=novoNo;
      lista->qtdade++;
      return 1;

    }
}

void showList(tipoLista *lista){
    tipoNo *atual;
    atual = lista->inicio;
    while(atual != NULL){ //lista->fim
        printf("%8d", atual->dado);
        atual = atual->proxNo;
    }
}

int inserirFim(tipoLista *lista, int valor){
    tipoNo *novoNo;
    if(lista->inicio == NULL){
        inserirListaVazia(lista, valor);
    }else{
        novoNo = (tipoNo*) malloc(sizeof(novoNo));
        if(novoNo == NULL)
            return 0;
        novoNo->dado = valor;//
        novoNo->proxNo = NULL;
        novoNo->antNo = lista->fim; // so lista->fim
        lista->fim->proxNo = novoNo;
        lista->fim = novoNo;
        lista->qtdade++;
        return 1;
    }
}

//to do remove do fim 1:06

int main()
{
    tipoLista lista;
    int aux,op;
    inicializarValoresDaLista(&lista);
    printf("LISTA DUPLAMENTE ENCADEADA");
    do{
        printf("\nMenu\n\n1 - Insere elemento em lista vazia:");
        printf("\n2 - Insere elemento na frente da lista");
        printf("\n3 - Insere no fim");
        //printf("\n4 - Insere elemento no fim da lista");
        //printf("\n5 - Busca dado na lista");
        //printf("\n6 - Remove elemento do fim da lista");
        printf("\n9 - Exibe lista");
        printf("\n0 - Encerra programa");
        printf("\nEscolha sua opcao: ");
        scanf("%d",&op);
        switch(op){
            case 1: printf("\nDigite o elemento que deseja inserir: ");
                scanf("%d",&aux);
                inserirListaVazia(&lista, aux);
            break;
            case 2: printf("\nDigite o elemento que deseja inserir: ");
                scanf("%d",&aux);
                inserirfrente(&lista, aux);
            break;
            case 3:
                 printf("Informe o elemento para ser inserido no fim");
                 scanf("%d", &aux);
                 if(inserirFim(&lista, aux))
                     printf("Valor inserido com sucesso");
                 else
                    printf("Insercao nao efetuada!");
            break;
            /*
            case 4: printf("\nDigite o elemento que deseja inserir: ");
                scanf("%d",&aux);
                insereNoFim(&lista, aux);
            break;
            case 5: printf("\nDigite o elemento que deseja buscar: ");
                    scanf("%d",&aux);
                    if(aux2 = buscaDado(&lista, aux))
                        printf("\nElemento encontrado na posicao %d.",aux2);
                    else
                        printf("\nElemento não encontrado.");
            break;
            case 6: removeDoFim(&lista);
            break; */
            case 9: showList(&lista);
            break;
            case 0: printf("\nEncerrando programa.");
                //destruirLista(&lista);
            break;
        }
    }while(op != 0);
return 0;
}
