#ifndef MANIPULAPEDIDO_H
#define MANIPULAPEDIDO_H

#include <StructTipos.h>



void diminuiTempoPreparo(ListaDuplaEnc<PEDIDO>&pedido){
    ElementoDuplaEnc<PEDIDO>*nav=pedido.inicio;
    while(nav!=NULL){
        nav->dado.tempopreparo--;
        if(nav->dado.tempopreparo<=0){
            nav->dado.tempopreparo=0;
        }
        nav=nav->proximo;
    }

}

int tempoPreparo(ListaDuplaEnc<PEDIDO>pedido){
    ElementoDuplaEnc<PEDIDO>*nav=pedido.fim;
    int tempopreparo=0;
    tempopreparo=nav->dado.tempopreparo;
    tempopreparo+=5;
    return tempopreparo;

}



void transfereProdutos(ListaEncadeada<PRODUTO>&produto,ListaEncadeada<PRODUTO>carrinho){
    inicializaListaEnc(produto);
    ElementoEncadeado<PRODUTO>*nav=carrinho.inicio;

    while(nav!=NULL){
        InsereFimEnc(produto,nav->dado);
        nav=nav->proximo;
    }
}

float calculaPrecoTotal(ListaDuplaEnc<PEDIDO>pedido){
    ElementoDuplaEnc<PEDIDO>*nav=pedido.inicio;
    ElementoEncadeado<PRODUTO>*temp=nav->dado.produtos.inicio;
   nav->dado.precototal=0.0;
    while(temp!=NULL){
        nav->dado.precototal+=temp->dado.preco;
        temp=temp->proximo;
    }
    return nav->dado.precototal;
}



void criaPedido(ListaDuplaEnc<PEDIDO>&pedido,ListaEncadeada<PRODUTO>carrinho,CLIENTE cliente){
    ElementoDuplaEnc<PEDIDO>*novopedido=new ElementoDuplaEnc<PEDIDO>;
    novopedido->proximo=NULL;
    novopedido->anterior=NULL;


    transfereProdutos(novopedido->dado.produtos,carrinho);
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

        novopedido->dado.tempopreparo=tempoPreparo(pedido);


        nav->proximo=novopedido;
        novopedido->anterior=nav;
        pedido.fim=novopedido;
        novopedido->dado.precototal=calculaPrecoTotal(pedido);
        novopedido->dado.cliente=cliente;


    }


}





void concluiPedido(ListaDuplaEnc<PEDIDO>&pedido,ListaDuplaEnc<PEDIDO>&pedidoconcluido){
    ElementoDuplaEnc<PEDIDO>*novo=new ElementoDuplaEnc<PEDIDO>;
    novo->proximo=NULL;
    novo->anterior=NULL;
    ElementoDuplaEnc<PEDIDO>*nav=pedido.inicio;
    novo->dado.entregador=nav->dado.entregador;
    novo->dado.precototal=calculaPrecoTotal(pedido);
    novo->dado.tempopreparo=nav->dado.tempopreparo;

    transfereProdutos(novo->dado.produtos,nav->dado.produtos);
    if(pedidoconcluido.inicio==NULL){
    pedidoconcluido.inicio=novo;

    pedidoconcluido.fim=novo;

    }
    else{
        ElementoDuplaEnc<PEDIDO>*nav=pedidoconcluido.inicio;
        while (nav->proximo!=NULL) {
            nav=nav->proximo;
        }
        nav->proximo=novo;
        novo->anterior=nav;
        pedidoconcluido.fim=novo;
        }

    }





#endif // MANIPULAPEDIDO_H
