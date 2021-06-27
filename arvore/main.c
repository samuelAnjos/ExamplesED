#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int dado;
    struct node *pai;
    struct node *filhoEsq;
    struct node *filhoDir;
}tipoNode;

tipoNode *achou;

/*Função para criação de um nó*/
tipoNode* criarNo(tipoNode *p, int dado){
    tipoNode *novo;
    novo = (tipoNode*) malloc(sizeof(tipoNode));
    novo->dado = dado;
    novo->filhoEsq = NULL;
    novo->filhoDir = NULL;
    novo->pai = p;

    return novo;
}

void exibirPreOrdem(tipoNode *atual){
    if(atual != NULL){
        printf("%8d", atual->dado);
        exibirPreOrdem(atual->filhoEsq);
        exibirPreOrdem(atual->filhoDir);
    }
}

void exibirInOrdem(tipoNode *atual){
    if(atual != NULL){
        exibirInOrdem(atual->filhoEsq);
        printf("%8d", atual->dado);
        exibirInOrdem(atual->filhoDir);
    }
}

void exibirPosOrdem(tipoNode *atual){
    if(atual != NULL){
        exibirPosOrdem(atual->filhoEsq);
        exibirPosOrdem(atual->filhoDir);
        printf("%d", atual->dado);
    }
}

int estaVazia(tipoNode *atual){
    if(atual == NULL)
        return 1;
    else
        return 0;
}

void destruirArvore(tipoNode *atual){
    if(estaVazia(atual)){
        destruirArvore(atual->filhoEsq);
        destruirArvore(atual->filhoDir);
        free(atual);
    }
}

/*Função recursiva que busca um nó na árvore binária.
  Após sua chamada o endereço do nó estará no ponteiro achou, caso o nó tenha sido encontrado*/
void buscaNo(tipoNode *atual, int dado){
    if(atual != NULL){
        if(atual->dado == dado){
            achou = atual;
            return atual;
        }
        buscaNo(atual->filhoEsq, dado);
        buscaNo(atual->filhoDir, dado);
    }
}

int temFilhoEsq(tipoNode *no){
    if(no->filhoEsq != NULL)
        return 1;
    else
        return 0;
}

int temFilhoDir(tipoNode *no){
    if(no->filhoDir != NULL)
        return 1;
    else
        return 0;
}

//Função para inserção de um nó, não raiz, na árvore
int insereNo(tipoNode *pai, int n, char tipoFilho){
    tipoNode *novo; // que nao vai ser utilizado
    if(tipoFilho == 'e'){
        if(temFilhoEsq(pai)){
            printf("Impossivel inserir. Nó já tem filho na esqueda. ");
            return 0;
        }
        pai->filhoEsq = criarNo(pai, n);
        return 1;
    }else{
        if(temFilhoDir(pai)){
            printf("Impossivel inserir. Nó já tem filho na direita. ");
            return 0;
        }
        pai->filhoDir = criarNo(pai, n);
        return 1;
    }
}

char getPosNo(tipoNode *no){
    if(no->pai->filhoEsq == no)
        return 'e';
    else
        return 'd';
}

// falta o remover no
tipoNode* removeNo(tipoNode *no){
    if(no != NULL){
        if(no->filhoEsq != NULL){
            if(no->filhoDir != NULL){
                printf("\nNo nao pode ser removido, tem dois(2) filhos.");
                return NULL;
            }else{//Situacao em que so tem filho da esquerda
                if(no->pai == NULL){// Se o no for a raiz
                    tipoNode *antigo = no;
                    no = no->filhoEsq;//No recebe o endereco de filho da esq (filho da esq ta assumido o lugar dele)
                    no->pai = NULL;
                    free(antigo);
                    printf("\nNo removido com Sucesso. ");
                    return no;
                }

                char posicao = getPosNo(no);
                if(posicao == 'e')
                    no->pai->filhoEsq = no->filhoEsq; //No filho esq recebe seu filho da esq
                else
                    no->pai->filhoDir = no->filhoEsq;//No filho dir recebe seu filho da esq
                no->filhoEsq->pai = no->pai;//Reconhece o  avo como o pai
                tipoNode *aux = no;
                free(no);
                printf("\nNo removido com sucesso.");
                return NULL;
            }
        }else{//Situacao em que tem filho da direita ou filho nenhum
            if(no->pai == NULL){ // Se for a raiz
                tipoNode *antigo = no;
                no = no->filhoDir;
                if(no != NULL) // SE o que eu coloquei na raiz nao for null, ou seja, nao tinha filho na direita
                    no->pai = NULL;
                free(antigo);
                printf("\nNo removido com sucesso.");
                return no;
            }else{
                 char posicao = getPosNo(no);
                 if(posicao == 'e')
                    no->pai->filhoEsq = no->filhoDir;
                 else
                    no->pai->filhoDir = no->filhoDir;
                 if(no->filhoDir != NULL){
                    no->filhoDir->pai = no->pai;
                 }
                 free(no);
                 printf("\nNo removido com sucesso.");
                 return NULL;
            }
        }
    }
    return NULL;
}

int main(){
    tipoNode *raiz = NULL;
    int op, valor, valorPai;
    char esqOuDir;
    do{
       printf("/nEscolha uma opcao ");
       printf("\n1 - Insere um no na arvore");
       printf("\n2 - Exibe a arvore em ordem simetrica");
       printf("\n3 - Exibe a arvore em pre ordem");
       printf("\n4 - Exibe a arvore pos ordem");
       printf("\n5 - Mostra se um no existe na arvore");
       printf("\n6 - Remove no da arvore");
       printf("\n0 - Encerra o programa");
       printf("\n Escolha sua opcao: ");
       scanf("%d", &op);
       switch(op){
       case 1:
           printf("\nDigite o valor que deseja inserir na arvore:");
           scanf("%d",&valor);
           if(raiz == NULL) /*É o primeiro nó da árvore*/
               raiz = criarNo(NULL, valor);
           else{
               printf("\nDigite o pai do no: ");
               scanf("%d", &valorPai);
               achou = NULL;
               buscaNo(raiz, valorPai);
               if(achou == NULL)
                  printf("\nPai nao encontrado. Insercao nao efetuada.");
               else{
                  fflush(stdin);
                  printf("\nDigite se o no sera filho da esquerda <e> ou da direita <d>:");
                  scanf("%c", &esqOuDir);
                  if(insereNo(achou,valor,esqOuDir))
                    printf("\nNo inserido com sucesso ");
               }
           }
        break;
       case 2:
           printf("\nElementos da arvore em ordem simetrica:\n");
           exibirInOrdem(raiz);
           printf("\n");
        break;
       case 3:
           printf("\nElementos da arvore em pre-ordem:\n");
           exibirPreOrdem(raiz);
           printf("\n");
        break;
       case 4:
           printf("\nElementos da arvore em ordem pos-ordem:\n");
           exibirPosOrdem(raiz);
           printf("\n");
        break;

       case 5:
           printf("\nDigite o dado que deseja ver se esta na arvore: ");
           scanf("%d", &valor);
           achou = NULL;
           buscaNo(raiz, valor);
           if(achou == NULL)
               printf("\nNo procurado nao se encontra na arvore!");
           else
               printf("\nNo encontra-se na arvore");
        break;
       case 6:
           printf("\nDigite o valor que deseja remover: ");
           scanf("%d", &valor);
           if(raiz->dado == valor) // Quero remover a raiz
               raiz = removeNo(raiz);
           else{
               achou = NULL;
               buscaNo(raiz, valor);
               if(achou == NULL)
                   printf("\nNo nao encontrado. Removao nao efetuada!");
               else
                removeNo(achou);
           }
        break;
        case 0:
            printf("\nEncerrando programa.");
            destruirArvore(raiz);
        break;
       }
    }while(op != 0);
    return 0;
}
