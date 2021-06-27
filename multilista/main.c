#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// multilista

// (Não pode faltar vontade)  There can be no lack of desire

typedef struct no{ // representa um aluno
    int mat;
    char nome[30];
    struct no *proxNo;
}tipoAluno;

typedef struct listaDisci{  // representa uma disciplina min 15 cont
    int codDisc;
    char nomeDisc[50];
    struct listaDisci *proxDisc; // ISSO COMO TRABALHAR
    tipoAluno *inicioAlunos; // pode ter um para o fim
    int qtdade;
}tipoDisc;

typedef struct multil{    //----------> na inicializa
    struct tipoDisc *inicio;
    struct tipoDisc *fim;
    struct tipoAluno * fim2; // So para peguar o fim
    int qtdade;  // se quiser nome do curso o que quizer
}tipoMulti;

// vamos por modelo fazer a inicialização
void inicializar(tipoMulti *multi){
    multi->inicio = NULL;
    multi->fim = NULL;
    multi->qtdade = 0;
}

int inserirMultiVazia(tipoMulti *lista, int codParaDisc, char nome[50]){
    tipoDisc *disc;
    disc = (tipoDisc *) malloc(sizeof(tipoDisc));
    if(disc == NULL){
        return 0;
    }else{
        disc->codDisc = codParaDisc;
        strcpy(disc->nomeDisc, nome);
        disc->proxDisc = NULL;
        disc->inicioAlunos = NULL;
        disc->qtdade++;
        lista->fim = disc;
        lista->fim2 = NULL;
        lista->inicio = disc;
        lista->qtdade++;
        return 1;
    }
}

void mostrar(tipoMulti *lista){
    tipoDisc *disc;
    disc = lista->inicio;
    while(disc != NULL){
        printf("\n%d %s", disc->codDisc, disc->nomeDisc);
        disc = disc->proxDisc;

    }
}


int inserirFrente(tipoMulti *lista, int idAlu, int idDiscp, char nomeAlu[50], char nomeDisp[50]){
    tipoAluno *aluno;
    tipoDisc *disc;

    if(lista->fim == NULL){
        inserirMultiVazia(lista, idDiscp, nomeDisp);
    }else{
    // como vou trabalhar com dois tipo No, então tenho q cria 2 no
    aluno = (tipoAluno *) malloc(sizeof(tipoAluno));
    disc = (tipoDisc *) malloc(sizeof(tipoDisc));

    if((aluno == NULL) && (disc == NULL)){
        return 0;
    }else{
        disc->codDisc = idDiscp;
        strcpy(disc->nomeDisc, nomeDisp);
        aluno->mat = idAlu;
        aluno->nome = nomeAlu;
        disc->proxDisc = disc;
        disc->inicioAlunos = aluno; // o quê que eu quero inserir disp ou aluno

     }
    }
}

int main(){

     tipoDisc disc;
     int id;
     char nome[50];
     inicializar(&disc);
     //fflush(stdin);
     printf("Informe seu nome: ");
     scanf("%s", &nome);
     printf("Informe ID: ");
     scanf("%d", &id);
     int resp = inserirMultiVazia(&disc, id, nome);
     if(resp == 1){
        printf("Bem Sucedido");
     }else{
        printf("Erro");
     }
    // ------ mostrar
    mostrar(&disc);

    return 0;
}
