#include <iostream>
#include <Restaurante.h>


using namespace std;







// listas genéricas
//2 listas estaticas : cardapio e cliente
//1 lista circular: entregador
//2 listas encadeadas: carrinho e produtos
//2 listas duplamente encadeadas: pedido e pedidoconcluido







int main()
{

    ListaEstatica<CLIENTE,5>clientes;          // Cria a Lista Estatica de Clientes
    iniciaCliente(clientes);                   // Atribui Dados a Lista de Clientes

    ListaEstatica<PRODUTO,18>cardapio;       // Cria a Lista Estatica Cardapio
    IniciaCardapioEstatico(cardapio);        // Atribui Dados a Lista Cardapio

    ListaEncadeada<PRODUTO>carrinho;         // Cria Lista Encadeada Carrinho
    inicializaListaEnc(carrinho);            //  Inicia a Lista Encadeada

    ListaDuplaEnc<PEDIDO>pedidos;             // Cria a Lista Duplamente Encadeada de Pedidos
    inicializaListaDuplaEnc(pedidos);         // Inicia a Lista de Pedidos

    ListaDuplaEnc<PEDIDO>pedidosconcluidos;     // Cria a Lista Duplamente Encadeada de Pedidos Concluidos
    inicializaListaDuplaEnc(pedidosconcluidos); // Inicia a Lista de Pedidos Concluidos

    ListaCircular<ENTREGADOR>entregadores;       // Cria a Lista Circular de Entregadores
    inicializaListaCircular(entregadores);       // Inicia a Lista Circular de Entregadores
    CriaListaMotoboy(entregadores);             //  Atribiu Dados a Lista Circular de Entregadores




    for(int tempo=0; tempo<300; tempo++){//  Inicio do loop de 300 Minutos

        if(tempo%2==0){         // A Cada 2 Minutos um Novo Pedido é Efetuado
          CarregarPedidos(cardapio,carrinho);   // Adicionando Itens ao Carrinho de Compras
          criaPedido(pedidos,carrinho,clientes.item[sorteio(4)].dado); //Passando os Itens do Carrinho Para um Pedido  //[sorteio()] Seleciona Aleatoriamente um Cliente da Lista de Clientes Precarregada
          ExcluiListaEnc(carrinho);             //Limpando o Carrinho
        }

        if(pedidos.inicio!=NULL){    // Se Existe um Pedido na Lista de Pedidos
        executaPedidos(pedidos,entregadores,pedidosconcluidos);
       }
    }

    if(pedidos.inicio!=NULL){
        cout<<"faltam :"<<contarListaDuplaEnc(pedidos)<<" Pedidos"<<endl;
        cout<<"Tempo estimado para conluir todos : "<<tempoTPedidos(pedidos)<<"Minutos"<<endl;
        while(pedidos.inicio!=NULL)
        {
        executaPedidos(pedidos,entregadores,pedidosconcluidos);
        }
    }





//fechaCaixa(pedidosconcluidos);//ter que ver isso meu parça

//cout<<"conlcuido"<<endl;
//debug(pedidosconcluidos);




















    return 0;
}
