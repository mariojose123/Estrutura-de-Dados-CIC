#include <stdio.h>
typedef int TipoInfo;
struct TPtPilha{
TipoInfo dado;
struct TPtPilha *elo;
};
typedef struct TPtPilha TipoPilha;
TipoPilha* InicializaPilha (void);
// cria pilha vazia
int VaziaPilha (TipoPilha *Topo);
// retorna 1 se pilha vazia, e 0 em caso contrário
TipoPilha* PushPilha (TipoPilha *Topo, TipoInfo Dado);
// insere nodo no topo da pilha, retorna novo topo
int PopPilha (TipoPilha **Topo, TipoInfo *Dado);
// remove nodo no no topo da pilha
TipoInfo ConsultaPilha (TipoPilha *Topo);
// retorna informação no topo da pilha
TipoPilha* DestroiPilha (TipoPilha *Topo);
// libera posições ocupadas pela pilha
