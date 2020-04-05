#ifndef LISTAMOTOBOY_H
#define LISTAMOTOBOY_H


#include <StructTipos.h>

void CriaListaMotoboy(ListaCircular<ENTREGADOR>&entregadores){
    ENTREGADOR entregador; //Cria um Entregador
    entregador.nome="Carlos"; // Atribui Nome ao Entregador
    entregador.tempoentrega=7; // Atribui um Tempo de Entrega Inicial
    entregador.disponivel=true;// Atribui A Disponibilidade do Entregador
    InsereCicurlarFim(entregadores,entregador); //Insere o Entregador na Lista de Entregadores

    entregador.nome="Joel";
    entregador.tempoentrega=7;
    entregador.disponivel=true;
    InsereCicurlarFim(entregadores,entregador);

    entregador.nome="Eduardo";
    entregador.tempoentrega=7;
    entregador.disponivel=true;
    InsereCicurlarFim(entregadores,entregador);

    entregador.nome="Cleyton";
    entregador.tempoentrega=7;
    entregador.disponivel=true;
    InsereCicurlarFim(entregadores,entregador);

    entregador.nome="Tiago";
    entregador.tempoentrega=7;
    entregador.disponivel=true;
    InsereCicurlarFim(entregadores,entregador);

    entregador.nome="Jose";
    entregador.tempoentrega=7;
    entregador.disponivel=true;
    InsereCicurlarFim(entregadores,entregador);

    entregador.nome="Omar";
    entregador.tempoentrega=7;
    entregador.disponivel=true;
    InsereCicurlarFim(entregadores,entregador);

    entregador.nome="Vladimir";
    entregador.tempoentrega=7;
    entregador.disponivel=true;
    InsereCicurlarFim(entregadores,entregador);

    entregador.nome="Samuel";
    entregador.tempoentrega=7;
    entregador.disponivel=true;
    InsereCicurlarFim(entregadores,entregador);

    entregador.nome="Jonas";
    entregador.tempoentrega=7;
    entregador.disponivel=true;
    InsereCicurlarFim(entregadores,entregador);

    entregador.nome="Vinicius";
    entregador.tempoentrega=7;
    entregador.disponivel=true;
    InsereCicurlarFim(entregadores,entregador);




}




bool disponibilidadeEntregador (ListaCircular<ENTREGADOR>entregadores){ // Verificar se Existe Entregador Disponivel
   ElementoCircular<ENTREGADOR>*nav=entregadores.inicio;
   int i=0;
   while(nav!=entregadores.inicio||(entregadores.inicio!=NULL&&i==0)){
       if(nav->dado.disponivel==true){ // Se o Entregador Esta Disponivel
           return true;                // Retorna Verdadeiro
       }
       i++;
       nav=nav->proximo;
   }

       return false;  // Caso Passe a Lista E Não Houver Entregador Disponivel Retornara Falso
}


#endif // LISTAMOTOBOY_H
