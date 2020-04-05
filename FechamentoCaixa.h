#ifndef FECHAMENTOCAIXA_H
#define FECHAMENTOCAIXA_H
#include <StructTipos.h>



void impremeProdutos(ListaEncadeada<PRODUTO>produtos){  // funcao para imprimir os dados da lista de produtos de cada pedido
    if(produtos.inicio==NULL){
        cout<<"|Lista vazia";
    }
    ElementoEncadeado<PRODUTO>*produto=produtos.inicio;
    while(produto!=NULL){
        cout<<"| nome: "<< produto->dado.nome<<endl
            <<"| descricao: " << produto->dado.descricao<<endl
            <<"| preco: "<<produto->dado.preco<<endl;
        produto=produto->proximo;
    }
}




void impremeFechamentoCaixa(ListaDuplaEnc<PEDIDO>pedidosconcluidos){  //Imprime os dados dos pedidos concluidos
    ElementoDuplaEnc<PEDIDO>*pedido=pedidosconcluidos.inicio;

    int i=0;
    while(pedido!=NULL){
        cout<<"============================================================================================="<<endl
            <<"| Pedido:"<<i++<<endl;
        impremeProdutos(pedido->dado.produtos); // imprime dados de cada produto da lista
        cout<<"| Tempo de Preparo: "<< pedido->dado.tempopreparo<<endl
            <<"| Nome Do motoboy: "<<pedido->dado.entregador.nome<<endl
            <<"| tempo ate a entrega do pedido: "<<pedido->dado.tempototal<<endl<<
              "| Cliente: "<<pedido->dado.cliente.nome<<endl<<
              "| Endereco: "<<pedido->dado.cliente.endereco<<endl<<
              "| Dia: "<<pedido->dado.data<<endl
            <<"| Preco total: "<<pedido->dado.precototal<<endl
            <<"============================================================================================="<<endl;

        pedido=pedido->proximo;
    }
}

bool verificaConferencias(float primeira,float segunda){  //verifica se os valores das conferencias sao iguais
   int i=(primeira-segunda); //evita erros das casas decimais
    if(i==0)
        return true;
    else
        return  false;
}


void fechaCaixa(ListaDuplaEnc<PEDIDO>pedidoconcluido){ //Ira Contabilizar os Ganhos do Dia de Trabalho

    ElementoDuplaEnc<PEDIDO>*nav=pedidoconcluido.inicio;

    float conferencia1=0;
    float conferencia2=0;

    while(nav!=NULL){  //calcula o valor total do inicio ate o final da lista
        conferencia1+=nav->dado.precototal;
        nav=nav->proximo;
    }

    nav=pedidoconcluido.fim;

    while(nav!=NULL){  //calcula o valor total do final ate o inicio da lista
        conferencia2+=nav->dado.precototal;
        nav=nav->anterior;
    }
    impremeFechamentoCaixa(pedidoconcluido);  //imprime os dados armazenados no pedido concluido

    cout<<"==============================================="<<endl
        <<"| Valor da  conferencia  1: "<<conferencia1<<endl
        <<"| Valor da  conferencia  2: "<<conferencia2<<endl;

    if(verificaConferencias(conferencia1,conferencia2)){
        cout<<"| Total arrecadado =[R$ "<<conferencia2<<"]"<<endl
        <<"==============================================="<<endl;
    }
    else{
        cout<<"Valor De Conferencia não confere";
    }

}





#endif // FECHAMENTOCAIXA_H
