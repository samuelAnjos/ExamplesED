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

void removerInicio(tipoLista *lista){ // new code
    tipoNo *noInicio;
    noInicio = lista->inicio;
    if(noInicio->proxNo == NULL){
        lista->inicio = NULL;
        lista->fim = NULL;
    }else{
         lista->inicio = noInicio->proxNo->antNo;
         noInicio->proxNo->antNo = NULL;
    }

    free(noInicio);
    lista->qtdade--;
}

void removerFim(tipoLista *lista){
    tipoNo *atual;
    atual = lista->fim;
    if(atual->antNo == NULL){
        lista->inicio = NULL;
        lista->fim = NULL;
    }else{

     atual->antNo->proxNo = NULL;
     lista->fim = atual->antNo;
    }
    free(atual);
    lista->qtdade--;
}

// FALTA
//  inserir em determinada posicao
int inserirEmDeterminadaPosicao(tipoLista *lista, int pos, int valor){ // tem erro!!!
        tipoNo *novoNo, *atual; // sera q precisso de 2
        atual = lista->inicio;
        if(pos>0 && pos<=lista->qtdade){  // se posicao valida
            if(pos==1){
                inserirfrente(lista, valor);
            }else if(pos==lista->qtdade){
                inserirFim(lista, valor);
            }else{
                tipoNo *novoNo;
                novoNo = (tipoNo *) malloc(sizeof(tipoNo));
                if(novoNo==NULL){
                    return 0;
                }
                for(int i=1; i<=pos-1; i++){
                    atual = atual->proxNo;
                }
                novoNo = novoNo->dado;
                novoNo->proxNo = atual->antNo;
                novoNo->antNo = atual->antNo;
                atual->antNo->proxNo = novoNo->antNo;
                lista->qtdade++;

            }
        }
        return 1;
}
//  pesquisar elemento

int main()
{
    tipoLista lista;
    int aux,op, pos;
    inicializarValoresDaLista(&lista);
    printf("LISTA DUPLAMENTE ENCADEADA");
    do{
        printf("\nMenu\n\n1 - Insere elemento em lista vazia:");
        printf("\n2 - Insere elemento na frente da lista");
        printf("\n3 - Insere no fim");
        printf("\n4 - Remover do fim.");
        printf("\n5 - Remove Inicio");
        printf("\n6 - Inserir em determinada posicao");
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

            case 4:
                  removerFim(&lista);
            break;

            case 5:
                removerInicio(&lista);
            break;

            case 6:
                printf("Informe o elemento para ser inserido na posicao");
                 scanf("%d", &aux);
                 printf("Informe posicao");
                 scanf("%d", &pos);
                 if(inserirEmDeterminadaPosicao(&lista, pos, aux))
                     printf("Valor inserido com sucesso");
                 else
                    printf("Insercao nao efetuada!");
            break;
            case 9: showList(&lista);
            break;
            case 0: printf("\nEncerrando programa.");
                //destruirLista(&lista);
            break;
        }
    }while(op != 0);
return 0;
}
