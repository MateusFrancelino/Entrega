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
#include <FechamentoCaixa.h>



using namespace std;















// listas genéricas
//2 listas estaticas : cardapio e cliente
//1 lista circular: entregador
//2 listas encadeadas: carrinho e produtos
//2 listas duplamente encadeadas: pedido e pedidoconcluido


// explicação sobre as escolhas adotadas e resultados obtidos

// a listas estaticas do cardapio e cliente, e a lista circular motoboy foram preenchidas antes da simulaçao comecar
// implementamos uma funçao pre carregada de pedidos onde é sorteado aleatoriamente novos pedidos, para melhor simulaçao de um restaurante
// apos o inicio da simulacao do restaurante, o primeiro "carrinho" é feito aleatoriamente pela funcao sorteio() chamada na funçao CarregarPedidos() no PedidosPreCarregados.h
// apos isso, é chamada a funçao criaPedido() para passar os produtos selecionados do carrinho para o pedido, logo, a funcao ExcluiListaEnc() é chamada para esvaziar o carrinho para a proxima compra








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

            diminuiTempoPreparo(pedidos); // Diminuir o Tempo de Preparo de Todos os Pedidos na Fila
            diminuiTempoEntregador(entregadores); // Diminuir o Tempo de Entrega dos Entregadores Que Ja Estao Entregando



            if(disponibilidadeEntregador(entregadores)==true && entregaPronta(pedidos)==true){  //  disponibilidadeEntregador() Verifica se Existe Algum Entregador Disponivel Para Realizar a Entrega
                                                                                             //  entregaPronta() Verifica se Existe Algum Pedido Pronto Para Ser Entregue

                entregarPedido(entregadores,pedidos);  //Atribiu um Entregador ao Pedido
                concluiPedido(pedidos,pedidosconcluidos); //Passa o Pedido Entregue Para a Lista de Pedidos Concluidos
                ExcluirListaDuplaEnc(pedidos); //Exclui o Pedido Entregue Da Lista de Pedidos
            }

       }

    }


fechaCaixa(pedidosconcluidos);//ter que ver isso meu parça

//cout<<"conlcuido"<<endl;
//debug(pedidosconcluidos);




















    return 0;
}
