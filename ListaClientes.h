#ifndef LISTACLIENTES_H
#define LISTACLIENTES_H
#include <StructTipos.h>
template<typename TIPO,int MAX>
void iniciaCliente(ListaEstatica<TIPO,MAX>&clientes){

     CLIENTE cliente;       //Cria um Cliente
     cliente.nome="roberval";    // Atribui um Nome ao Cliente
     cliente.endereco=" Logo ali"; // Atribui um Endereço ao Cliente
     InserePListaEstatica(clientes,cliente,0); //insere o Cliente na lista de Clientes

     cliente.nome="roberval";
     cliente.endereco=" Logo ali";
     InserePListaEstatica(clientes,cliente,1);

     cliente.nome="roberval";
     cliente.endereco=" Logo ali";
     InserePListaEstatica(clientes,cliente,2);

     cliente.nome="roberval";
     cliente.endereco=" Logo ali";
     InserePListaEstatica(clientes,cliente,3);

     cliente.nome="roberval";
     cliente.endereco=" Logo ali";
     InserePListaEstatica(clientes,cliente,4);
}





#endif // LISTACLIENTES_H
