#ifndef CARDAPIOESTATICO_H
#define CARDAPIOESTATICO_H
#include <StructTipos.h>

template <typename TIPO,int MAX>
void IniciaCardapioEstatico(ListaEstatica<TIPO,MAX> &L){
    PRODUTO cardapio;

    cardapio.nome = "Hamburguer de siri";
    cardapio.descricao = "Bob esponja calca quadrada";
    cardapio.preco = 500.00;
    InserePListaEstatica(L,cardapio,0);


    cardapio.nome = "Hamburguer de carne";
    cardapio.descricao = "Carne e ervilhas";
    cardapio.preco = 1.50;
    InserePListaEstatica(L,cardapio,1);

    cardapio.nome = "Hamburguer de salame";
    cardapio.descricao=".i.";
    cardapio.preco = 80.00;
    InserePListaEstatica(L,cardapio,2);

    cardapio.nome = "Misto quente";
    cardapio.descricao = "torra na torrada";
    cardapio.preco = 5.00;
    InserePListaEstatica(L,cardapio,3);

    cardapio.nome = "batatatAS";
    cardapio.descricao = "fritas";
    cardapio.preco = 20.00;
    InserePListaEstatica(L,cardapio,4);

}

#endif // CARDAPIOESTATICO_H
