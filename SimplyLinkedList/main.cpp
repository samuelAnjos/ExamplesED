#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// THIS IS THE FINAL !!!

//Structure that represents a list node
typedef struct no
{
    int data;
    struct no *proxNo;
} no;

//Structure that stores the  the information of a linked list
typedef struct manageList
{
    no *start;
    no *endd;
    int quantity;
} Manage;

// Function that initializes the linked list
void initialize(Manage *listt)
{
    listt->start = NULL;
    listt->endd = NULL;
    listt->quantity = 0;
}

//Function that inserts a node into an empty list
int addingNode(Manage *listt, int value)
{
    no *newNode;
    newNode = (no *) malloc(sizeof(no));

    if(newNode == NULL)
    {
        return 0;
    }
    else
    {
        newNode->data = value;
        newNode->proxNo = NULL;
        listt->start = newNode;
        listt->endd = newNode;
        listt->quantity++;
        return 1;
    }
}

//Insert a node in front of the list

int insertFront(Manage *listt, int valor)
{
    no *newNode;
    if(listt->start == NULL)
        addingNode(listt, valor);
    else
    {
        newNode = (no *) malloc(sizeof(no));
        if(newNode == NULL)
            return 0;
        newNode->data = valor;
        newNode->proxNo = listt->start;
        listt->start = newNode;
        listt->quantity++;
        return 1;
    }


}


// Function show list
void showList(Manage *listt)
{
    no *current;
    current = listt->start;
    while(current != NULL)
    {
        printf("  %d", current->data);
        current = current->proxNo;

    }
}

// Função para inserir elemento no fim da lista encadeada
int inserirFinal(Manage *listt, int dado)
{
    no *newNode;

    if(listt->start == NULL)
    {
        addingNode(listt, dado);
    }
    else
    {
        newNode = (no *) malloc(sizeof(no));
        if(newNode == NULL)
        {
            return 0;
        }
        newNode->data = dado;
        newNode->proxNo = NULL;
        listt->endd->proxNo = newNode;// indexacao indireta liga ao final criado agora
        listt->endd = newNode;
        listt->quantity++;
        return 1;
    }
}

// Função que remove primeiro elemento da lista encadeada
void removePrimeiroElemento(Manage *listt)
{
    no *aux;
    aux = listt->start;
    listt->start = listt->start->proxNo;

    if(listt->quantity == 1)
    {
        listt->endd = NULL;
        listt->quantity--;
        free(aux);
    }
    //=================================================

}




//da aula de hoje
//Remover do fim
// atua <- inicio

void removerFim(Manage *listt)  // tem que Percorrer para chegar ao fim
{
    no *atual, *anterior;
    atual  = listt->start;
    if(atual->proxNo != NULL)
    {
        while(atual->proxNo != NULL)
        {
            anterior=atual;
            atual = atual->proxNo;
        }
        anterior->proxNo = NULL;
        listt->endd = anterior;
    }
    else
    {
        listt->start = NULL; // se so um elemento na lista
        listt->endd = NULL;
    }

    free(atual);
    listt->quantity--;
}

// void destruir lista (hoje)
//auxiliar na destruicao
int listaVazia(Manage *lista)
{
    if(lista->endd == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void destruirLista(Manage *listt)
{
    while(!listaVazia(listt))
    {
        removePrimeiroElemento(listt);
    }
}

int inserirPosicao(Manage *listt, int posicao, int dado)
{
    no *newNode, *atual;
    if(posicao >0 && posicao<=listt->quantity+1)
    {
        if(posicao==1)
        {
            insertFront(listt,dado);
        }
        else
        {
            newNode = (no *) malloc(sizeof(no));
            if(newNode==NULL)
            {
                return 0;
            }
            else
            {
                newNode->data = dado;
                atual = listt->start;
                for(int x=1; x<posicao-1; x++)
                {
                    atual = atual->proxNo;
                }
                newNode->proxNo = atual->proxNo;
                atual->proxNo = newNode;
                listt->quantity++;
                if(newNode->proxNo==NULL)
                {
                    listt->endd=newNode;
                }
            }
        }
    }
    // como pegar a posisao de um elemento em lista encadeada sendo que eu não trnho posi tipo ponteiro
    return 1;
}

void removerDeterminadaPosicao(Manage *listt, int pos)
{
    /*no *atual, *toBeMoved;
    if(pos > 0 && pod <= listt->quantity){
        if(pos==1){
           removePrimeiroElemento(listt);
        }else{
          // 2:5  que foi passado para fazer em casa FAZER
        }
    }
    */
}

int RetornaPosicao(Manage *listt, int dado)
{
    no *current;
    int cont=1;
    current = listt->start;
    while(current != NULL)
    {
        //printf("  %d", current->data);
        if(current->data==dado)
        {
            return cont;
        }
        current = current->proxNo;
        cont++;
    }
    return 0;
}


int main()
{

    Manage listt;

    int op, aux, resp, aux2;
    do
    {
        printf("\n Escolha uma opcao: >>");
        printf("\n1 - Adicionar um no"); // nao precisa no menu
        printf("\n2 - Adicionar um elemento na frente");
        printf("\n3 - Inserir no final");
        printf("\n4 - Remove elemento do inicio");
        printf("\n5 - REMOVER FIM");
        printf("\n6 - INseri na POSICAO");
        printf("\n7 - >> Exibe elementos da lista");
        printf("\n8 - Mostra posicao LISTA");
        printf("\n0 - Sair do programa");
        printf("\nDigite sua opcao:");
        scanf("%d",&op);

        switch(op)
        {

        case 1:
            printf("\n> Adicionado um no: >\n");
            scanf("%d",&aux);
            resp = addingNode(&listt, aux);
            if(resp != -1)
                printf("\n>  Elemento adicionado com suceso");
            else
                printf("\n>  Elemento nao adicionado\n");
            break;
        case 2:
            printf("\n> Adicionado Na Frente >\n");
            scanf("%d",&aux);
            resp = insertFront(&listt, aux);
            if(resp != -1)
                printf("\n>  Elemento adicionado com suceso");
            else
                printf("\n>  Elemento nao adicionado\n");
            break;
        case 3:
            printf("\n> Inserir no final >\n");
            scanf("%d",&aux);
            resp = inserirFinal(&listt, aux);
            if(resp != -1)
                printf("\n>  Elemento adicionado com suceso");
            else
                printf("\n>  Elemento nao adicionado\n");
            break;
        case 4:
            removePrimeiroElemento(&listt);

            break;
        case 5:
            removerFim(&listt);
            break;

        case 6:
            cout<< "Informe a posicao a ser inserido:\n";
            cin >> aux;
            cout << "Informe a posicao:\n";
            cin >> aux2;
            if(inserirPosicao(&listt,aux, aux2))
            {
                cout << "Inserido com sucesso";
            }
            else
            {
                cout << "Não inserido";
            }
            break;
        case 7:
            cout << "---------/n";
            showList(&listt);
            break;
        case 0:
            printf("\n>  Encerrando programa.\n");
            destruirLista(&listt);
            break;

        case 8:
            cout << "Informe um numero para ver a posicao: " << endl;
            cin >> aux;
            if(aux = RetornaPosicao(&listt, aux))
            {
                cout << "Está na posicao: " << aux << endl;
            }
            else
            {
                cout << "Operacao não bem sucedida " << endl;
            }

            break;
        default:
            printf("\n>  Opcao invalida!\n");
        }


    }
    while(op != 0);


    return 0;
}
