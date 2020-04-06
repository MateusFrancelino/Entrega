#ifndef LISTACLIENTES_H
#define LISTACLIENTES_H
#include <StructTipos.h>
template<typename TIPO,int MAX>
void iniciaCliente(ListaEstatica<TIPO,MAX>&clientes){

     CLIENTE cliente;       //Cria um Cliente
     cliente.nome="irineu";    // Atribui um Nome ao Cliente
     cliente.endereco=" vc nao sabe nem eu"; // Atribui um Endereço ao Cliente
     InserePListaEstatica(clientes,cliente,0); //insere o Cliente na lista de Clientes

     cliente.nome=" Carlos ";
     cliente.endereco=" Rua 302, numero 96";
     InserePListaEstatica(clientes,cliente,1);

     cliente.nome=" Rodrigo ";
     cliente.endereco=" Rua 280, numero 50";
     InserePListaEstatica(clientes,cliente,2);

     cliente.nome=" Silvana ";
     cliente.endereco=" Rua 128, numero 23";
     InserePListaEstatica(clientes,cliente,3);

     cliente.nome=" Joao ";
     cliente.endereco=" Rua 164, numero 34";
     InserePListaEstatica(clientes,cliente,4);
}





#endif // LISTACLIENTES_H
