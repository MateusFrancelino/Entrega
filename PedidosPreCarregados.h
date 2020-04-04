#ifndef PEDIDOSPRECARREGADOS_H
#define PEDIDOSPRECARREGADOS_H
#include <StructTipos.h>
#include <FuncaoRandom.h>

template <typename TIPO,int MAX>
int CarregarPedidos (ListaEstatica<TIPO,MAX>cardapio,ListaEncadeada<PRODUTO>&carrinho){


for(int i=0;i<2;i++){
        InsereFimEnc(carrinho,cardapio.item[sorteio((MAX-1))].dado);

}


}


#endif // PEDIDOSPRECARREGADOS_H
