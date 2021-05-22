 #include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct no{
    int dado;
    struct no *proxNo;
} tipoNo;

//Structure that stores the  the information of a linked list
typedef struct manageList{
    no *fim;
    int quant;
}tipoLista;

// Function that initializes the linked list
void initialize(tipoLista *listt){
    listt->fim = NULL;
    listt->quant = 0;
}

int insereListaVazia(tipoLista *listaEnc, int valor){
    tipoNo *novoNo;
    novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    if(novoNo == NULL)
        return 0;
    novoNo->dado = valor;
    novoNo->proxNo = novoNo;  // aqui faz-se a referencia circular
    listaEnc->fim = novoNo;
    listaEnc->quant++;

    return 1;
}

/*Função que percorre a lista exibindo todos os seus dados*/
void exibeLista(tipoLista *listaEnc){
   tipoNo *atual;  /*Variável que será usada para percorrer a lista*/
   atual = listaEnc->fim->proxNo;
   cout << atual->dado << " ";
   while(atual != listaEnc->fim){
       atual = atual->proxNo;
       cout << atual->dado << " ";
   }
   cout << " " << endl;
} // 3

int insereNaFrente(tipoLista *listaEnc, int valor){ // 2
tipoNo *novoNo;
if(listaEnc->fim==NULL)
    insereListaVazia(listaEnc, valor);
else{
    novoNo = (tipoNo*)malloc(sizeof(tipoNo));
    if(novoNo==NULL)
        return 0;
    novoNo->dado=valor;
    novoNo->proxNo = listaEnc->fim->proxNo; //aponta para o que esta
    listaEnc->fim->proxNo=novoNo;  //o que esta aponta para novo
    listaEnc->quant++;
    return 1;
}
}
// Essa é a parte que comeca a parte da ativida passada para casa
int insereNoFim(tipoLista *listaEnc, int valor){

tipoNo *novoNo;
if(listaEnc->fim == NULL)
    insereListaVazia(listaEnc, valor);
else{
    novoNo = (tipoNo*) malloc(sizeof(novoNo));
    if(novoNo == NULL){
         return 0;
    }
     novoNo->dado=valor;
     novoNo->proxNo = listaEnc->fim->proxNo;
     listaEnc->fim->proxNo = novoNo;
     listaEnc->fim = novoNo;
     listaEnc->quant++;
   }
   return 1;
}

//-------------

void removeDaFrente(tipoLista *listaEnc){
tipoNo *aux;
aux = listaEnc->fim->proxNo;
listaEnc->fim->proxNo = listaEnc->fim->proxNo->proxNo;
if(listaEnc->quant == 1)
    listaEnc->fim = NULL;
listaEnc->quant--;
free(aux);
}

int listaVaziax(tipoLista *listaEnc){

    if(listaEnc->fim == NULL){
        return 1;
    }else{
        return 0;
    }
}

void destruirListax(tipoLista *lista){ // ============== ver
   while(!listaVaziax(lista)){
    removeDaFrente(lista);
   }



}

int buscaDado(tipoLista *listaEnc, int valor){
    tipoNo *atual;
    int cont=1;
    atual=listaEnc->fim->proxNo;
    while(atual != listaEnc->fim){
        if(atual->dado == valor){
            return cont;
        }
        cont++;
        atual = atual->proxNo;
    }
    return 0;
}

int main(){

    tipoLista lista;
    int aux, valor, op;
    initialize(&lista);

    do{
        //system(pause); system("cls") o fim para organizar
        cout << "Lista circular " <<  endl;
        cout << "1- Insere em Lista Vazia " << endl;
        cout << "2- Insere na Frente " << endl;
        cout << "3- Insere no Fim da Lista " << endl;
        cout << "4- Remover da frente " << endl;
        cout << "5- Destruir Lista " << endl;
        cout << "44- Busca Dado e Retorna Posicao " << endl;
        cout << "9- Exibir Lista " << endl;
        cout << "Escolha opcao: " << endl;
        cin >> op;

        switch(op){
        case 1:
            cout << "Informe o valor a ser adicionado: " << endl;
            cin  >> aux;
            if(aux=insereListaVazia(&lista, aux)){
                cout << "Adicao feita com sucesso." << endl;
            }else{
                cout << "Erro na operacao! " << endl;
            }
            break;
        case 2:
            cout << "Informe o valor a ser adicionado no Inicio: " << endl;
            cin  >> aux;
            if(aux=insereNaFrente(&lista, aux)){
                cout << "Adicao feita com sucesso." << endl;
            }else{
                cout << "Erro na operacao! " << endl;
            }
            break;
        case 3:
            cout << "Informe o valor a ser adicionado no Fim: " << endl;
            cin  >> aux;
            if(aux=insereNoFim(&lista, aux)){
                cout << "Adicao feita com sucesso." << endl;
            }else{
                cout << "Erro na operacao! " << endl;
            }
            break;

        case 4:
            removeDaFrente(&lista);
            break;
        case 5:
            destruirListax(&lista);
            break;
        case 6:
            cout << "Informe o valor para sabermos sua posicao: " << endl;
            cin  >> aux;
            if(aux=insereNoFim(&lista, aux)){
                cout << "Elemento localizado na posicao: " << aux << endl;
            }else{
                cout << "Elemento nao encontrado " << endl;
            }
            break;
        case 44:
            cout << "Informe o valor para sabermos sua posicao: " << endl;
            cin  >> aux;
            if(aux=buscaDado(&lista, aux)){
                cout << "Elemento localizado na posicao: " << aux << endl;
            }else{
                cout << "Elemento nao encontrado " << endl;
            }
            break;
        case 9:
             exibeLista(&lista);
            break;
        default:
            cout << "Operacao Invalida! " << endl;
        }
    }while(op!=0);


    return 0;
}
