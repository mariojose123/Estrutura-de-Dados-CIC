#include <stidio.h>
struct TipoInfoNo{
int codigo;
char nome[20];
float preco;
};
typedef struct TipoInfoNo InfoNo;
struct TipoPtNo{
InfoNo info;
struct TipoPtNo* ant;
struct TipoPtNo* prox;
};
typedef struct TipoPtNo PtNo;
