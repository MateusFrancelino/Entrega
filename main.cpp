#include <iostream>
#include <ListaGenerica.h>
#include <StructTipos.h>
#include <CardapioEstatico.h>
#include <ListaMotoboy.h>
#include <PedidosPreCarregados.h>
#include <Debug.h>
#include <Entregas.h>
#include <ManipulaPedido.h>
#include <ListaClientes.h>
#include <FuncaoRandom.h>



using namespace std;




void quebracaixa(ListaDuplaEnc<PEDIDO>pedidoconcluido){

    ElementoDuplaEnc<PEDIDO>*nav=pedidoconcluido.inicio;

    float conferencia1=0.00, conferencia2=0.00;

    while(nav!=NULL){
        conferencia1+=nav->dado.precototal;
        nav=nav->proximo;
    }

    nav=pedidoconcluido.fim;

    while(nav!=NULL){
        conferencia2+=nav->dado.precototal;
        nav=nav->anterior;
    }


    cout<<conferencia1<<endl;
    cout<<conferencia2<<endl;
    if(conferencia1==conferencia2){
        cout<<"Total arrecadado =[R$ "<<conferencia1<<"]"<<endl;
    }

}


template <int MAX>
bool buscaItem(ListaEstatica<PRODUTO,MAX>&l,PRODUTO dado){

    for(int i=0;i<l.qtd;i++){
        if(l.item[i].dado.nome==dado.nome){
            return true;
        }
    }
    return false;
}

template <int MAX>
int descobreIndiceLista(ListaEstatica<PRODUTO,MAX>&l,PRODUTO dado){
    for(int i=0;i<l.qtd;i++){
        if(l.item[i].dado.nome==dado.nome){
            return i;
        }
    }
    return -1;
}



























int main()
{
    ListaEstatica<CLIENTE,5>cliente;
    iniciaCliente(cliente);

    ListaEstatica<PRODUTO,5>cardapio;
    IniciaCardapioEstatico(cardapio);
    PRODUTO coisa;
    coisa=obterItemLista(cardapio,2);
    //cout<<coisa.nome<<endl;
    bool l;
    l=buscaItem(cardapio,coisa);
    //cout<<l<<endl;





    int coisado;
    coisado=descobreIndiceLista(cardapio,coisa);


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

    for(int tempo=0; tempo<150000; tempo++){


        if(tempo%2==0){
          CarregarPedidos(cardapio,carrinho);
         // debug(carrinho);
          //cout<<numeropedido<<endl;
          criaPedido(pedido,carrinho,cliente.item[sorteio(4)].dado);
          ExcluiListaEnc(carrinho);

        }


        if(pedido.inicio!=NULL){
           cout<<tempo;
           system("cls");
            //debug(pedido);




            diminuiTempoPreparo(pedido);
            calculaTempoTotal(pedido);

            if(disponibilidadeMotoboy(motoboy)==true && entregaPronta(pedido)==true){

                entregarPedido(motoboy,pedido);


                concluiPedido(pedido,pedidoconcluido);

                ExcluirListaDuplaEnc(pedido);
             }


        diminuiTempoEntrega(motoboy);

       }



    }


quebracaixa(pedidoconcluido);

//cout<<"conlcuido"<<endl;
debug(pedidoconcluido);




















    return 0;
}
