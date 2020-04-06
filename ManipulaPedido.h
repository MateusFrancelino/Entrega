#ifndef MANIPULAPEDIDO_H
#define MANIPULAPEDIDO_H

#include <StructTipos.h>










int tempoTPedidos (ListaDuplaEnc<PEDIDO>pedidos){
    ElementoDuplaEnc<PEDIDO>*pedido=pedidos.fim;
    return pedido->dado.tempopreparo;

}

/*
=====================================================================================================================
*/

void diminuiTempoPreparo(ListaDuplaEnc<PEDIDO>&pedidos){ // Diminui o Tempo de Preparo dos Pedidos em 1
    ElementoDuplaEnc<PEDIDO>*pedido=pedidos.inicio;
    while(pedido!=NULL){
        pedido->dado.tempopreparo--;
        if(pedido->dado.tempopreparo<=0){//Para Evitar que o Tempo do Pedido Seja Menor que 0
            pedido->dado.tempopreparo=0;
        }
        pedido->dado.tempototal=pedido->dado.tempopreparo+7;  // Calcula o Tempo Total Para o Pedido Ser Entregue
        pedido=pedido->proximo;
    }


}


/*
=====================================================================================================================
*/

float calculaPrecoTotal(ListaEncadeada<PRODUTO>pedido){
    ElementoEncadeado<PRODUTO>*temp=pedido.inicio;
    float precototal=0.00;
    while(temp!=NULL){
        precototal+=temp->dado.preco;
        temp=temp->proximo;
    }
    return precototal;
}

int tempoPreparo(ListaDuplaEnc<PEDIDO>pedido){  //Calcula o Tempo de Preparo de um Pedido
    ElementoDuplaEnc<PEDIDO>*nav=pedido.fim; // Pega o ultimo Pedido
    int tempopreparo=0;
    tempopreparo=nav->dado.tempopreparo;    // Adiciona o Tempo de Preparo do Ultimo Pedido a variavel
    tempopreparo+=5;                        // Adiciona 5 "tempo de preparo padrão de um novo pedido" Para a Variavel
    return tempopreparo; //Retorna a Variavel Com o Tempo Calculado;

}

void transfereProdutos(ListaEncadeada<PRODUTO>&produto,ListaEncadeada<PRODUTO>carrinho){
    inicializaListaEnc(produto); //Inicia a Lista de Produtos
    ElementoEncadeado<PRODUTO>*nav=carrinho.inicio;

    while(nav!=NULL){
        InsereFimEnc(produto,nav->dado); //Transferindo Itens do Carrinho Para a Lista de Produtos
        nav=nav->proximo;
    }
}

void criaPedido(ListaDuplaEnc<PEDIDO>&pedidos,ListaEncadeada<PRODUTO>carrinho,CLIENTE cliente){
    ElementoDuplaEnc<PEDIDO>*novopedido=new ElementoDuplaEnc<PEDIDO>;    //Criando um Novo Elemento do Tipo Pedido
    novopedido->proximo=NULL;
    novopedido->anterior=NULL;


    transfereProdutos(novopedido->dado.produtos,carrinho);            //Transferir Todos os Itens do Carrinho Para a Lista de Produtos do Novo Pedido
    novopedido->dado.precototal=calculaPrecoTotal(novopedido->dado.produtos); // Calcula o Preço Total do Pedido
    novopedido->dado.cliente=cliente;  //Atribui um Cliente ao Pedido

    if(pedidos.inicio==NULL){           //Caso Não Exista Nenhum Pedido
       pedidos.inicio=novopedido;
       novopedido->dado.tempopreparo=5;
       pedidos.fim=novopedido;

    }
    else{ // Caso Ja Exista Pedidos Anteriores

        ElementoDuplaEnc<PEDIDO>*nav=pedidos.inicio;
        while(nav->proximo!=NULL){

            nav=nav->proximo;

        }

        novopedido->dado.tempopreparo=tempoPreparo(pedidos);  // Calcula o Tempo de Preparo do Novo Pedido

        nav->proximo=novopedido;
        novopedido->anterior=nav;
        pedidos.fim=novopedido;

    }

}

/*
=====================================================================================================================
*/

void concluiPedido(ListaDuplaEnc<PEDIDO>&pedidos,ListaDuplaEnc<PEDIDO>&pedidosconcluidos){ //Passa os Dados do Pedido Entregue Para a Lista de Pedidos Concluidos
    ElementoDuplaEnc<PEDIDO>*novopedido=new ElementoDuplaEnc<PEDIDO>;// Cria um Novo Pedido Para ser Adicionado a Pedidos Concluidos
    novopedido->proximo=NULL;
    novopedido->anterior=NULL;
    ElementoDuplaEnc<PEDIDO>*pedido=pedidos.inicio;
    novopedido->dado.entregador=pedido->dado.entregador;     // Passa os Dados do Entregador Para o Pedido Concluido
    novopedido->dado.precototal=pedido->dado.precototal;    // Passa o Preço Total do Pedido Para o Pedido Concluido
    novopedido->dado.cliente=pedido->dado.cliente;          // Passa o Cliente do Pedido Para o Pedido Concluido
    novopedido->dado.data=pedido->dado.data;                // Passa a Data do Pedido Para o Pedido Concluido
    novopedido->dado.tempopreparo=0;                        // O Pedido Ja Foi Preparado Então 0;
    novopedido->dado.tempototal=0;                          //

    transfereProdutos(novopedido->dado.produtos,pedido->dado.produtos); //Tranfere os Produtos do Pedido Para o Pedido Concluido

    if(pedidosconcluidos.inicio==NULL){ // Se a Lista de Pedidos Concluidos Estiver Vazia Adiciona o Primeiro Pedido Concluido
    pedidosconcluidos.inicio=novopedido;
    pedidosconcluidos.fim=novopedido;
    }
    else{                               // Adiciona os Pedidos Concluidos na Lista
        ElementoDuplaEnc<PEDIDO>*pedidoconcluido=pedidosconcluidos.inicio;
        while (pedidoconcluido->proximo!=NULL) {
            pedidoconcluido=pedidoconcluido->proximo;
        }
        pedidoconcluido->proximo=novopedido;
        novopedido->anterior=pedidoconcluido;
        pedidosconcluidos.fim=novopedido;
        }
    }




#endif // MANIPULAPEDIDO_H
