#ifndef RESTAURANTE_H
#define RESTAURANTE_H


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




void executaPedidos(ListaDuplaEnc<PEDIDO>&pedidos,ListaCircular<ENTREGADOR>&entregadores,ListaDuplaEnc<PEDIDO>&pedidosconcluidos){


    diminuiTempoPreparo(pedidos); // Diminuir o Tempo de Preparo de Todos os Pedidos na Fila
    diminuiTempoEntregador(entregadores); // Diminuir o Tempo de Entrega dos Entregadores Que Ja Estao Entregando

    if(disponibilidadeEntregador(entregadores)==true && entregaPronta(pedidos)==true){  //  disponibilidadeEntregador() Verifica se Existe Algum Entregador Disponivel Para Realizar a Entrega
                                                                                     //  entregaPronta() Verifica se Existe Algum Pedido Pronto Para Ser Entregue
        entregarPedido(entregadores,pedidos);  //Atribiu um Entregador ao Pedido
        concluiPedido(pedidos,pedidosconcluidos); //Passa o Pedido Entregue Para a Lista de Pedidos Concluidos
        ExcluirListaDuplaEnc(pedidos); //Exclui o Pedido Entregue Da Lista de Pedidos
    }
}






#endif // RESTAURANTE_H
