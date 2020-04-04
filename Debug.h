#ifndef DEBUG_H
#define DEBUG_H
#include <StructTipos.h>
#include <windows.h>

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


void calculaTempoTotal(ListaDuplaEnc<PEDIDO>&pedido){
    ElementoDuplaEnc<PEDIDO>*nav=pedido.inicio;


    while(nav!=NULL){
    if(nav->dado.entregador.disponivel==false){
        nav->dado.tempototal=nav->dado.tempopreparo+nav->dado.entregador.tempoentrega;
    }
    else{
        nav->dado.tempototal=nav->dado.tempopreparo+7;
    }
     nav=nav->proximo;
    }


}


void debug (ListaDuplaEnc<PEDIDO>pedido){
    ElementoDuplaEnc<PEDIDO>*nav=pedido.inicio;
    int i=0;
    while(nav!=NULL){
        cout<<"==================================="<<endl;
        cout<<"Pedido:"<<i++<<endl;
        debug(nav->dado.produtos);


        cout<<"Tempo de Preparo: "<< nav->dado.tempopreparo<<" Minutos"<<endl;

        cout<<"Nome Do motoboy: "<<nav->dado.entregador.nome<<endl;


       cout<<"tempo ate a entrega do pedido: "<<nav->dado.tempototal<<endl<<
             "Cliente: "<<nav->dado.cliente.nome<<endl<<
             "Endereco"<<nav->dado.cliente.endereco<<endl<<
             "Dia: "<<nav->dado.data<<endl;




        cout<<"Preco total: "<<nav->dado.precototal<<endl;
        cout<<"==================================="<<endl;


        nav=nav->proximo;

    }

}



void debug(ListaCircular<ENTREGADOR>motoboy){
    ElementoCircular<ENTREGADOR>*nav=motoboy.inicio;
    int i=0;

    while(nav!=motoboy.inicio||(motoboy.inicio!=NULL&&i==0)){

        cout<<"nome do entregador : "<<nav->dado.nome<<endl<<"tempo para entregar "<<nav->dado.tempoentrega<<endl<<"o entregador esta:"<<nav->dado.disponivel<<endl;
        i++;
        nav=nav->proximo;
    }
}





#endif // DEBUG_H
