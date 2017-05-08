#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"


struct TPtPilha{
        TipoInfo dado;
        struct TPtPilha *elo;
};


TipoPilha* InicializaPilha (void)
{
    return NULL;
}

int PilhaVazia (TipoPilha *Topo)
{
    if (Topo==NULL)
       return 1;
    else
       return 0;
}

void ImprimirPilha (TipoPilha *Topo)
{
     TipoPilha *ptaux;

     if (Topo != NULL)
     {
        puts("---Imprimindo pilha---");
        for (ptaux=Topo; ptaux!=NULL; ptaux=ptaux->elo)
            printf("%d\n",ptaux->dado);
        puts("-------Fim pilha------");
     }
     else
       puts("Pilha vazia");

}


TipoPilha* PushPilha (TipoPilha *Topo, TipoInfo Dado)
{
       TipoPilha *novo; //novo elemento
       TipoPilha *ptaux = Topo; //ponteiro auxiliar para percorrer a lista

       /*aloca um novo nodo */
       novo = (TipoPilha*) malloc(sizeof(TipoPilha));
       novo->elo = NULL;

       /*insere a informa��o no novo nodo*/
       novo->dado = Dado;

       /*encaeia o elemento*/
       novo->elo = Topo;
       Topo = novo;
       return Topo;
}


int PopPilha (TipoPilha **Topo, TipoInfo *Dado) //retorna 1 se exclui e zero se n�o exclui
{
   TipoPilha* ptaux;

   if (PilhaVazia(*Topo))
     return 0;   //n�o tem nada na pilha
   else
   {
        *Dado = (*Topo)->dado;     // devolve o valor do topo
        ptaux = *Topo;          //guarda o endere�o do topo
        *Topo = (*Topo)->elo;     //o pr�ximo passa a ser o topo
        free(ptaux);           //libera o que estava no topo
        ptaux=NULL;
        return 1;
   }
}

TipoInfo ConsultaPilha (TipoPilha *Topo)
{
 if (Topo==NULL)
   return 0;
 else
   return Topo->dado;

}

TipoPilha* DestroiPilha (TipoPilha *Topo)
{
        TipoPilha *ptaux;
        while (Topo != NULL)
        {
          ptaux = Topo;          //guarda o endere�o do topo
          Topo = Topo->elo;     //o pr�ximo passa a ser o topo
          free(ptaux);           //libera o que estava no topo
        }
        return NULL;
}
int Compara(TipoPilha *Topo1,TipoPilha *Topo2){
    int data1;
    int data2;
    int flag=0;
    while(!(PilhaVazia(Topo1))||!(PilhaVazia(Topo2))){
     PopPilha(&Topo1,&data1);
     PopPilha(&Topo2,&data2);
     flag=0;
     if(data1==data2){
        flag=1;
     }
     else{
        return 0;
     }
    }
    return flag;
}



