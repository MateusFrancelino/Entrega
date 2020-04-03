#ifndef PEDIDOSPRECARREGADOS_H
#define PEDIDOSPRECARREGADOS_H
#include <StructTipos.h>
template <typename TIPO,int MAX>
int CarregarPedidos (ListaEstatica<TIPO,MAX>cardapio,ListaEncadeada<PRODUTO>&carrinho,int &numeropedido){
    if(numeropedido==0){
        InsereFimEnc(carrinho,cardapio.item[1].dado);
        InsereFimEnc(carrinho,cardapio.item[3].dado);
        InsereFimEnc(carrinho,cardapio.item[0].dado);
    }

    else if (numeropedido==1){
        InsereFimEnc(carrinho,cardapio.item[0].dado);
        InsereFimEnc(carrinho,cardapio.item[1].dado);
    }
    else if (numeropedido==2){
        InsereFimEnc(carrinho,cardapio.item[2].dado);
        InsereFimEnc(carrinho,cardapio.item[0].dado);
    }
    else if (numeropedido==3){
        InsereFimEnc(carrinho,cardapio.item[4].dado);
        InsereFimEnc(carrinho,cardapio.item[3].dado);
    }
    else if (numeropedido==4){
        InsereFimEnc(carrinho,cardapio.item[3].dado);
        InsereFimEnc(carrinho,cardapio.item[1].dado);
    }
    else if (numeropedido==5){
        InsereFimEnc(carrinho,cardapio.item[0].dado);
        InsereFimEnc(carrinho,cardapio.item[4].dado);
    }
    else{
        InsereFimEnc(carrinho,cardapio.item[0].dado);
        InsereFimEnc(carrinho,cardapio.item[0].dado);
    }
    return numeropedido++;
}


#endif // PEDIDOSPRECARREGADOS_H
