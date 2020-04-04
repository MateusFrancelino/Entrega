#ifndef LISTACLIENTES_H
#define LISTACLIENTES_H
#include <StructTipos.h>
template<typename TIPO,int MAX>
void iniciaCliente(ListaEstatica<TIPO,MAX>&cliente){

     CLIENTE pessoa;
     pessoa.nome="roberval";
     pessoa.endereco=" Logo ali";
     InserePListaEstatica(cliente,pessoa,0);

     pessoa.nome="roberval";
     pessoa.endereco=" Logo ali";
     InserePListaEstatica(cliente,pessoa,1);

     pessoa.nome="roberval";
     pessoa.endereco=" Logo ali";
     InserePListaEstatica(cliente,pessoa,2);

     pessoa.nome="roberval";
     pessoa.endereco=" Logo ali";
     InserePListaEstatica(cliente,pessoa,3);

     pessoa.nome="roberval";
     pessoa.endereco=" Logo ali";
     InserePListaEstatica(cliente,pessoa,4);


}





#endif // LISTACLIENTES_H
