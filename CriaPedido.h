#ifndef CRIAPEDIDO_H
#define CRIAPEDIDO_H
#include <StructTipos.h>







void diminuiTempoPreparo(ListaDuplaEnc<PEDIDO>&pedido){
    ElementoDuplaEnc<PEDIDO>*nav=pedido.inicio;
    while(nav!=NULL){
        nav->dado.tempopreparo--;
        if(nav->dado.tempopreparo<=-1){
            nav->dado.tempopreparo=0;
        }
        nav=nav->proximo;
    }

}

int tempoPreparo(ListaDuplaEnc<PEDIDO>&pedido){
    ElementoDuplaEnc<PEDIDO>*nav=pedido.inicio;
    int tempopreparo=0;
    while(nav!=NULL){
        tempopreparo+=nav->dado.tempopreparo;
        nav=nav->proximo;
    }
    tempopreparo+=5;

    return tempopreparo;

}



void carrinhoParaPedido(ListaEncadeada<PRODUTO>&produto,ListaEncadeada<PRODUTO>carrinho){
    inicializaListaEnc(produto);
    ElementoEncadeado<PRODUTO>*nav=carrinho.inicio;

    while(nav!=NULL){
        InsereFimEnc(produto,nav->dado);
        nav=nav->proximo;
    }
}

void criaPedido(ListaDuplaEnc<PEDIDO>&pedido,ListaEncadeada<PRODUTO>carrinho){
    ElementoDuplaEnc<PEDIDO>*novopedido=new ElementoDuplaEnc<PEDIDO>;
    novopedido->proximo=NULL;
    novopedido->anterior=NULL;

    carrinhoParaPedido(novopedido->dado.produtos,carrinho);
    if(pedido.inicio==NULL){
       pedido.inicio=novopedido;
       novopedido->dado.tempopreparo=5;
       pedido.fim=novopedido;
    }
    else{

        ElementoDuplaEnc<PEDIDO>*nav=pedido.inicio;
        while(nav->proximo!=NULL){

            nav=nav->proximo;

        }


        novopedido->anterior=pedido.fim;
        nav->proximo=novopedido;
        novopedido->dado.tempopreparo=tempoPreparo(pedido);
        pedido.fim=novopedido;


    }
}





#endif // CRIAPEDIDO_H
