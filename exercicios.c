#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"

PtNo* insert(PtNo* head,InfoNo info){//inserts a node in the double linked list
    //ascending order
if(head==NULL){//checks if the head node  is NULL
    head=malloc(sizeof(PtNo));
    if(head==NULL){
        return head;
    }
    head->info.codigo=info.codigo;
    head->prox=NULL;
    head->ant=NULL;
    return head;
}
//creates a new node
PtNo *newnode;
newnode=malloc(sizeof(PtNo));
newnode->info.codigo=info.codigo;
newnode->prox=NULL;
newnode->ant=NULL;
if(info.codigo<head->info.codigo){
    newnode->prox=head;
    newnode->prox->ant=newnode;
    return newnode;
}
PtNo *after,*prev;
after=head;
while(after!=NULL&&after->info.codigo<=info.codigo){
    prev=after;
    after=after->prox;
}
newnode->prox=after;
if(after!=NULL){
    after->ant=newnode;
}
newnode->ant=prev;
prev->prox=newnode;
return head;
}
void printlinkedlist(PtNo* PtLista)
{
    PtNo* PtAux=PtLista;
    if (PtLista == NULL)
    puts("lista vazia");
    else
    do {
    printf("Codigo = %d \n",
    PtAux->info.codigo);
    PtAux =
    PtAux->prox
    ;
    } while (
    PtAux != NULL
    );
}
void printlkinverted(PtNo *PtLista){
    PtNo *PtAux;
    if (PtLista==NULL){
    printf("Lista vazia ! ");
    }else
    {
    PtAux=PtLista;
    while (PtAux->prox!=NULL)
    PtAux=PtAux->prox;
    while (
    PtAux!=NULL
    ) {
    printf("Codigo = %d Nome = %s Preco = %f\n",
    PtAux->info.codigo,
    PtAux->info.nome,
    PtAux->info.preco);
    PtAux=
    PtAux->ant
    ;
    }
    }
}
PtNo* destroy(PtNo* ptLista)
{
    PtNo *PtAux;
    //ponteiro auxiliar para percorrer a lista
    while (ptLista != NULL)
    {
    PtAux = ptLista;
    ptLista = ptLista->prox;
    free(PtAux);
    }
    free(ptLista);
    return NULL;
}
int main(){
InfoNo info[4];
PtNo *x;
x=NULL;
for(int i=0;i<=3;i++){
    info[i].codigo=i;
}
x=insert(x,info[1]);
x=insert(x,info[2]);
x=insert(x,info[3]);
x=insert(x,info[2]);
x=insert(x,info[2]);
x=insert(x,info[3]);
printlinkedlist(x);
printlkinverted(x);
x=destroy(x);
printlinkedlist(x);

}
