#include <iostream>
#include <ListaGenerica.h>
#include <StructTipos.h>
#include <CardapioEstatico.h>
#include <ListaMotoboy.h>
#include <PedidosPreCarregados.h>
#include <Debug.h>
#include <CriaPedido.h>
#include <Entregas.h>
using namespace std;




void concluiPedido(ListaDuplaEnc<PEDIDO>&pedido,ListaDuplaEnc<PEDIDO>&pedidoconcluido){
    ElementoDuplaEnc<PEDIDO>*novo=new ElementoDuplaEnc<PEDIDO>;
    novo->proximo=NULL;
    novo->anterior=NULL;
    ElementoDuplaEnc<PEDIDO>*nav=pedido.inicio;
    novo->dado.entregador=nav->dado.entregador;
    novo->dado.precototal=nav->dado.precototal;
    novo->dado.tempopreparo=nav->dado.tempopreparo;

    carrinhoParaPedido(novo->dado.produtos,nav->dado.produtos);
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





void diminuiTempoEntrega(ListaCircular<ENTREGADOR>&motoboy){
    ElementoCircular<ENTREGADOR>*nav=motoboy.inicio;
    int i=0;
    while(nav!=motoboy.inicio||(motoboy.inicio!=NULL&&i==0)){

        if(nav->dado.disponivel==false){
            nav->dado.tempoentrega--;
            if(nav->dado.tempoentrega==0)
                nav->dado.disponivel=true;


            }
    i++;
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








int main()
{

    ListaEstatica<PRODUTO,5>cardapio;
    IniciaCardapioEstatico(cardapio);

    ListaEncadeada<PRODUTO>carrinho;
    inicializaListaEnc(carrinho);

    ListaDuplaEnc<PEDIDO>pedido;
    inicializaListaDuplaEnc(pedido);

    ListaDuplaEnc<PEDIDO>pedidoconcluido;
    inicializaListaDuplaEnc(pedidoconcluido);

    ListaCircular<ENTREGADOR>motoboy;
    inicializaListaCircular(motoboy);
    CriaListaMotoboy(motoboy);


int numeropedido=0;

    for(int tempo=0; tempo<300; tempo++){


        if(tempo%2==0){
          CarregarPedidos(cardapio,carrinho,numeropedido);
         // debug(carrinho);
          //cout<<numeropedido<<endl;
          criaPedido(pedido,carrinho);
          ExcluiListaEnc(carrinho);

        }


        if(pedido.inicio!=NULL){
            //debug(pedido);


            diminuiTempoPreparo(pedido);

            if(disponibilidadeMotoboy(motoboy)==true && entregaPronta(pedido)==true){

                entregarPedido(motoboy,pedido);


                concluiPedido(pedido,pedidoconcluido);

                ExcluirListaDuplaEnc(pedido);
             }


        diminuiTempoEntrega(motoboy);

       }



    }




cout<<"conlcuido"<<endl;
debug(pedidoconcluido);




















    return 0;
}
