#include "estrutura.h"
#include <stdio.h>
#include <stdlib.h>
TipoPilha* PushPilha (TipoPilha *Topo, TipoInfo Dado)
{
    TipoPilha *novo;
    //novo elemento
    /*aloca um novo nodo */
    novo = (TipoPilha*) malloc(sizeof(TipoPilha));
    /*insere a informação no novo nodo*/
    novo->dado = Dado;
    /*encadeia o elemento */
    novo->elo = Topo;
    /*retorna novo topo */
    return novo;
}

int PopPilha (TipoPilha **Topo, TipoInfo *Dado) //retorna 1 se
{
    TipoPilha* ptaux;
    if (VaziaPilha(*Topo))
    return 0;
    // a pilha está vazia
    else
    {
    *Dado = (*Topo)->dado;
    // devolve o valor do topo
    ptaux = *Topo;
    //guarda o endereço do topo
    *Topo = (*Topo)->elo;
    //o próximo passa a ser o topo
    free(ptaux);
    //libera o que estava no topo
    ptaux=NULL;
    return 1;
}
}

int VaziaPilha(TipoPilha *Topo){
    if(Topo==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

TipoPilha* exercicio(TipoPilha *pilha1 ,TipoPilha *pilha2){
if(pilha1==NULL&&pilha2==NULL){
    return NULL;
}
TipoPilha *Ptaux1;
TipoPilha *PtQReturn=(TipoPilha*)malloc(sizeof(TipoPilha));
TipoPilha *PTAux3=(TipoPilha*)malloc(sizeof(TipoPilha));
PtQReturn=NULL;
PTAux3=NULL;
TipoInfo dado;
while(pilha1!=NULL||pilha2!=NULL){
  if(pilha1==NULL||pilha2==NULL){
  if(pilha1==NULL){
    while(pilha2!=NULL){
        if(PopPilha(&pilha2,&dado)){
        PTAux3=PushPilha(PTAux3,dado);
    }
    else{
        return NULL;
    }
    }
  }
  else {
    while(pilha1!=NULL){
        if(PopPilha(&pilha1,&dado)){
        PTAux3=PushPilha(PTAux3,dado);
    }
    else{
        return NULL;
    }
    }
  }
  }
  else{
  if(pilha1->dado<pilha2->dado){
    if(PopPilha(&pilha2,&dado)){
        PTAux3=PushPilha(PTAux3,dado);
    }
    else{
        return NULL;
    }
  }
  else{
    if(PopPilha(&pilha1,&dado)){
        PTAux3=PushPilha(PTAux3,dado);
    }
    else{
        return NULL;
    }
  }
}
}
if(PTAux3==NULL){
    printf("zero");
    return NULL;
}
   while(PTAux3!=NULL){
    if(PopPilha(&PTAux3,&dado)){
        PtQReturn=PushPilha(PtQReturn,dado);
    }
    else{
        return NULL;
    }
}
return PtQReturn;
}
int main(){//
    TipoPilha *PI1=(TipoPilha*)malloc(sizeof(TipoPilha));
    TipoPilha*PI2=(TipoPilha*)malloc(sizeof(TipoPilha));
    TipoPilha *PI3=(TipoPilha*)malloc(sizeof(TipoPilha));
    printf("teste");
    PI1=NULL;
    PI2=NULL;
    PI3=NULL;
    PI1=PushPilha(NULL,1);
    PI2=PushPilha(NULL,1);
    PI1=PushPilha(PI1,2);;
    PI2=PushPilha(PI2,2);
    PI3=exercicio(PI1,PI2);
    TipoPilha *aux;
    aux=PI3;
    for(aux;aux!=NULL;aux=aux->elo){
     printf("%i \n",aux->dado);
    }
}

