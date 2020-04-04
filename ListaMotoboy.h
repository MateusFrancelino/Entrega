#ifndef LISTAMOTOBOY_H
#define LISTAMOTOBOY_H


#include <StructTipos.h>

void CriaListaMotoboy(ListaCircular<ENTREGADOR>&motoboy){
    ElementoCircular<ENTREGADOR>*novo=new ElementoCircular<ENTREGADOR>;
    novo->dado.nome="carlos";
    novo->dado.tempoentrega=7;
    novo->dado.disponivel=true;
    InsereCicurlarFim(motoboy,novo->dado);
    novo->dado.nome="cuba";
    novo->dado.tempoentrega=7;
    novo->dado.disponivel=true;
    InsereCicurlarFim(motoboy,novo->dado);
    novo->dado.nome="lulalivre";
    novo->dado.tempoentrega=7;
    novo->dado.disponivel=true;
    InsereCicurlarFim(motoboy,novo->dado);
    novo->dado.nome="cleytom";
    novo->dado.tempoentrega=7;
    novo->dado.disponivel=true;
    InsereCicurlarFim(motoboy,novo->dado);
    novo->dado.nome="tiao";
    novo->dado.tempoentrega=7;
    novo->dado.disponivel=true;
    InsereCicurlarFim(motoboy,novo->dado);
    novo->dado.nome="jose";
    novo->dado.tempoentrega=7;
    novo->dado.disponivel=true;
    InsereCicurlarFim(motoboy,novo->dado);
    novo->dado.nome="ursal";
    novo->dado.tempoentrega=7;
    novo->dado.disponivel=true;
    InsereCicurlarFim(motoboy,novo->dado);
    novo->dado.nome="vladimir";
    novo->dado.tempoentrega=7;
    novo->dado.disponivel=true;
    InsereCicurlarFim(motoboy,novo->dado);
    novo->dado.nome="salnorabo";
    novo->dado.tempoentrega=7;
    novo->dado.disponivel=true;
    InsereCicurlarFim(motoboy,novo->dado);
    novo->dado.nome="campeao";
    novo->dado.tempoentrega=7;
    novo->dado.disponivel=true;
    InsereCicurlarFim(motoboy,novo->dado);
    novo->dado.nome="vruuuuum";
    novo->dado.tempoentrega=7;
    novo->dado.disponivel=true;
    InsereCicurlarFim(motoboy,novo->dado);




}




bool disponibilidadeMotoboy (ListaCircular<ENTREGADOR>motoboy){
   ElementoCircular<ENTREGADOR>*nav=motoboy.inicio;
   int i=0;
   while(nav!=motoboy.inicio||(motoboy.inicio!=NULL&&i==0)){
       if(nav->dado.disponivel==true){
           return true;
       }
       i++;
       nav=nav->proximo;
   }

       return false;
}


#endif // LISTAMOTOBOY_H
