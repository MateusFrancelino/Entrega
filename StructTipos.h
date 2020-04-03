#ifndef STRUCTTIPOS_H
#define STRUCTTIPOS_H
#include <ListaGenerica.h>
using namespace std;

struct PRODUTO{
    string nome=" ";
    string descricao=" ";
    float preco=0.0;
    };



struct ENTREGADOR{
    string nome=" ";
    int tempoentrega=0;
    bool disponivel=true;
};


struct PEDIDO{
    float precototal=0.0;
    int tempopreparo=0;

    ENTREGADOR entregador;
    ListaEncadeada<PRODUTO>produtos;

};





#endif // STRUCTTIPOS_H




