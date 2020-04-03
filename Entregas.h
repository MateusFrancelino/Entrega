#ifndef ENTREGAS_H
#define ENTREGAS_H
#include <StructTipos.h>

bool entregaPronta(ListaDuplaEnc<PEDIDO>pedido){
    ElementoDuplaEnc<PEDIDO>*nav=pedido.inicio;
    while(nav!=NULL){
        if(nav->dado.tempopreparo==0){
            return true;
        }
        nav=nav->proximo;
    }

    return false;
}



ENTREGADOR escolheEntregador(ListaCircular<ENTREGADOR>&motoboy){
    ElementoCircular<ENTREGADOR>*nav=motoboy.inicio;
    while(nav->dado.disponivel!=true){
        nav=nav->proximo;
    }
    motoboy.inicio=nav->proximo;
    nav->dado.disponivel=false;
    nav->dado.tempoentrega=7;
    return nav->dado;

}
void entregarPedido(ListaCircular<ENTREGADOR>&motoboy,ListaDuplaEnc<PEDIDO>&pedido){
    ElementoDuplaEnc<PEDIDO>*nav=pedido.inicio;
    nav->dado.entregador=escolheEntregador(motoboy);


}



#endif // ENTREGAS_H
