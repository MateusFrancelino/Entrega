#ifndef PEDIDOSPRECARREGADOS_H
#define PEDIDOSPRECARREGADOS_H
#include <StructTipos.h>
#include <FuncaoRandom.h>

template <typename TIPO,int MAX>
void CarregarPedidos (ListaEstatica<TIPO,MAX>cardapio,ListaEncadeada<PRODUTO>&carrinho){
PRODUTO item;

for(int i=0;i<2;i++){
    InsereFimEnc(carrinho,cardapio.item[sorteio((MAX-1))].dado); //Sorteia e Insere o Pedido na Lista Encadeada Carrinho
}
}


#endif // PEDIDOSPRECARREGADOS_H
