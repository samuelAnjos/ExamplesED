#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//Structure that represents a list node
typedef struct no{
   int data;
   struct no *proxNo;
}no;

//Structure that stores the  the information of a linked list
typedef struct manageList{
    no *start;
    no *endd;
    int quantity;
}Manage;

// Function that initializes the linked list
void initialize(Manage *listt){
    listt->start = NULL;
    listt->endd = NULL;
    listt->quantity = 0;
}

//Function that inserts a node into an empty list
int addingNode(Manage *listt, int value){
    no *newNode;
    newNode = (no *) malloc(sizeof(no));

    if(newNode == NULL){
        return 0;
    }else{
        newNode->data = value;
        newNode->proxNo = NULL;
        listt->start = newNode;
        listt->endd = newNode;
        listt->quantity++;
        return 1;
    }
}

// Function show list
void showList(Manage *listt){
    no *current;
    current = listt->start;
    while(current != NULL){
       printf("  %d", current->data);
       current = current->proxNo;

    }
}

int main(){

    Manage listt;
    int temporary;
    printf("\nDigite um numero inteiro:");
    scanf("%d",&temporary);
    addingNode(&listt, temporary);
    showList(&listt);

    return 0;
}
