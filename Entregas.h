#ifndef ENTREGAS_H
#define ENTREGAS_H
#include <StructTipos.h>
/*
=====================================================================================================================
*/

bool entregaPronta(ListaDuplaEnc<PEDIDO>pedidos){
    ElementoDuplaEnc<PEDIDO>*nav=pedidos.inicio;
    while(nav!=NULL){
        if(nav->dado.tempopreparo<=0){ // Se o Tempo De Preparo Chegou em 0 Existe um Pedido Pronto
            return true;               // Retorna Verdadeiro
        }
        nav=nav->proximo;
    }

    return false;// Se Não Houver Pedidos Prontos Retorna Falso
}

/*
=====================================================================================================================
*/
void diminuiTempoEntregador(ListaCircular<ENTREGADOR>&entregadores){ // Diminui o Tempo da Entrega em 1
    ElementoCircular<ENTREGADOR>*entregador=entregadores.inicio;
    int i=0;
    while(entregador!=entregadores.inicio||(entregadores.inicio!=NULL&&i==0)){

        if(entregador->dado.disponivel==false){ // Se o Entregador Estiver Entregando um Pedido
            entregador->dado.tempoentrega--;    // Diminui o Tempo da Entrega em 1
            if(entregador->dado.tempoentrega==0) // Tempo de Entrega em 0 o Entregador Terminou a Entrega
                entregador->dado.disponivel=true;// Entao Ele ira ficar Disponivel novamente


            }
    i++;
    entregador=entregador->proximo;
    }
}

/*
=====================================================================================================================
*/


ENTREGADOR escolheEntregador(ListaCircular<ENTREGADOR>&entregadores){ //Encontra Um Entregador Disponivel Para a Entrega
    ElementoCircular<ENTREGADOR>*entregador=entregadores.inicio;
    while(entregador==entregadores.inicio||entregador->dado.disponivel!=true){ //Procurando um Entregador Disponivel na Lista Circular
        entregador=entregador->proximo;
    }
    entregadores.inicio=entregador->proximo;
    entregador->dado.disponivel=false;
    entregador->dado.tempoentrega=7;
    return entregador->dado;
}

void entregarPedido(ListaCircular<ENTREGADOR>&entregadores,ListaDuplaEnc<PEDIDO>&pedidos){ //Atribuindo um Entregador Disponivel ao Pedido
    ElementoDuplaEnc<PEDIDO>*pedido=pedidos.inicio;
    pedido->dado.entregador=escolheEntregador(entregadores);        //Passa Um Entregador Disponivel Para a Entrega do Pedido
}





#endif // ENTREGAS_H
