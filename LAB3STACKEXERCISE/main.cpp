#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"


int main ()
{
      TipoPilha *pilha1=InicializaPilha();
      TipoPilha *pilha2=InicializaPilha();
      TipoPilha *pilha3=InicializaPilha();
      TipoPilha *pilha4=InicializaPilha();
      pilha1=PushPilha(pilha1,1);
      pilha1=PushPilha(pilha1,2);
      pilha1=PushPilha(pilha1,3);
      pilha1=PushPilha(pilha1,4);
      pilha2=PushPilha(pilha1,2);
      pilha2=PushPilha(pilha1,3);
      pilha2=PushPilha(pilha1,4);
      pilha3=PushPilha(pilha3,4);
      pilha3=PushPilha(pilha3,3);
      pilha3=PushPilha(pilha3,2);
      pilha3=PushPilha(pilha3,1);
      pilha4=PushPilha(pilha4,4);
      pilha4=PushPilha(pilha4,3);
      pilha4=PushPilha(pilha4,2);
      pilha4=PushPilha(pilha4,1);
      ImprimirPilha(pilha1);
      printf("/n");
      ImprimirPilha(pilha2);
      printf("/n");
      ImprimirPilha(pilha3);
      printf("/n");
      ImprimirPilha(pilha4);
      printf("/n");
      printf("primeira comparação:%i /n",Compara(pilha1,pilha2));
      printf("segunda comparação:%i /n",Compara(pilha3,pilha4));




    return 0;
}
