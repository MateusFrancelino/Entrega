#ifndef DEBUG_H
#define DEBUG_H
#include <StructTipos.h>

void debug(ListaEncadeada<PRODUTO>carrinho){

    if(carrinho.inicio==NULL){
        cout<<"Lista vazia";
    }
    ElementoEncadeado<PRODUTO>*nav=carrinho.inicio;
    while(nav!=NULL){
        cout<<" nome: "<< nav->dado.nome<< endl;
        cout<<" descricao: " << nav->dado.descricao<<endl;
        cout<<" preco: "<<nav->dado.preco<<endl;
        nav=nav->proximo;
    }


}



void debug (ListaDuplaEnc<PEDIDO>pedido){
    ElementoDuplaEnc<PEDIDO>*nav=pedido.inicio;
    int i=0;
    while(nav!=NULL){

        cout<<"Pedido:"<<i++<<"================="<<endl;
        debug(nav->dado.produtos);


        cout<<"Tempo de Preparo: "<< nav->dado.tempopreparo<<endl;

        cout<<"Nome Do motoboy: "<<nav->dado.entregador.nome<<endl;
        nav=nav->proximo;

    }

}





#endif // DEBUG_H
