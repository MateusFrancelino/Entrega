#ifndef CARDAPIOESTATICO_H
#define CARDAPIOESTATICO_H
#include <StructTipos.h>

template <typename TIPO,int MAX>
void IniciaCardapioEstatico(ListaEstatica<TIPO,MAX> &cardapio){
    PRODUTO produto; //Cria um Produto Para Ser Adicionado ao Cardapio

    produto.nome = "Hamburguer vegetariano";  //Adiciona o Nome do Produto
    produto.descricao = " Pao, mussarela, alface, tomate, cebola, hamburguer de soja";   //Adiciona a Descrição do Produto
    produto.preco = 24.90;  // Adiciona o Preço do Produto
    InserePListaEstatica(cardapio,produto,0); // Insere o Produto no Cardapio


    produto.nome = "Hamburguer de costela";
    produto.descricao = " Pao, cheddar, alface, tomate, cebola, hamburguer de costela";
    produto.preco = 35.90;
    InserePListaEstatica(cardapio,produto,1);

    produto.nome = "Hamburguer tradicional";
    produto.descricao=" Pao, cheddar, maionese artesanal, hamburguer de carne bovina";
    produto.preco = 19.90;
    InserePListaEstatica(cardapio,produto,2);

    produto.nome = "Hamburguer duplo";
    produto.descricao = " Pao, cheddar, maionese artesanal, 2 hamburgueres bovinos";
    produto.preco = 30.00;
    InserePListaEstatica(cardapio,produto,3);

    produto.nome = "Hamburguer de frango";
    produto.descricao = " Pao com gergelim, mussarela, maionese artesanal, hamburguer de frango";
    produto.preco = 25.99;
    InserePListaEstatica(cardapio,produto,4);

    produto.nome = "Hamburguer da casa";
    produto.descricao = " Pao, cheddar, maionese artesanal, alface, ovo, cebola roxa, hamburguer de frango";
    produto.preco = 35.00;
    InserePListaEstatica(cardapio,produto,5);

    produto.nome = "Hamburguer de porco";
    produto.descricao = " Pao, maionese, bacon, alface, hamburguer suino";
    produto.preco = 25.99;
    InserePListaEstatica(cardapio,produto,6);

    produto.nome = "Batata Frita - pequena";
    produto.descricao = " 250g";
    produto.preco = 15.00;
    InserePListaEstatica(cardapio,produto,7);

    produto.nome = "Batata Frita - media";
    produto.descricao = " 375g";
    produto.preco = 20.00;
    InserePListaEstatica(cardapio,produto,8);

    produto.nome = "Batata Frita - grande";
    produto.descricao = " 500g";
    produto.preco = 26.00;
    InserePListaEstatica(cardapio,produto,9);

    produto.nome = " Asa de frango";
    produto.descricao = " 500g, Acompanha molho especial";
    produto.preco = 29.00;
    InserePListaEstatica(cardapio,produto,10);

    produto.nome = " Agua mineral sem gas";
    produto.descricao = " 500ml";
    produto.preco = 4.00;
    InserePListaEstatica(cardapio,produto,11);

    produto.nome = " Agua mineral com gas";
    produto.descricao = " 500ml";
    produto.preco = 4.00;
    InserePListaEstatica(cardapio,produto,12);

    produto.nome = " Coca-cola lata";
    produto.descricao = " 350ml";
    produto.preco = 4.50;
    InserePListaEstatica(cardapio,produto,13);

    produto.nome = " Coca-cola garrafa";
    produto.descricao = " 1,5 litro";
    produto.preco = 7.50;
    InserePListaEstatica(cardapio,produto,14);

    produto.nome = " Suco de laranja";
    produto.descricao = " 375ml";
    produto.preco = 5.00;
    InserePListaEstatica(cardapio,produto,15);

    produto.nome = " Suco de maracuja";
    produto.descricao = " 375ml";
    produto.preco = 5.00;
    InserePListaEstatica(cardapio,produto,16);

    produto.nome = " Suco de limao";
    produto.descricao = " 375ml";
    produto.preco = 5.00;
    InserePListaEstatica(cardapio,produto,17);
}



template <int MAX>
bool buscaItem(ListaEstatica<PRODUTO,MAX>&l,PRODUTO dado){

    for(int i=0;i<l.qtd;i++){
        if(l.item[i].dado.nome==dado.nome){
            return true;
        }
    }
    return false;
}

template <int MAX>
int descobreIndiceLista(ListaEstatica<PRODUTO,MAX>&l,PRODUTO dado){
    for(int i=0;i<l.qtd;i++){
        if(l.item[i].dado.nome==dado.nome){
            return i;
        }
    }
    return -1;
}



#endif // CARDAPIOESTATICO_H
