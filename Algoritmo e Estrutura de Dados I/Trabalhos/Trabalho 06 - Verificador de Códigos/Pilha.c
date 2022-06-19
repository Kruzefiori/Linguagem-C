#include <stdlib.h>
#include <stdio.h>
#include "Pilha.h"

//função pra criar a Pilha
P_pilha criar_pilha(){

    P_pilha N = malloc (sizeof (Pilha));//alloca um espaço pro tamanho da struct
    //reseta o topo e o ini(que seria a cabeça)
    N->topo = 0;
    N->ini = NULL;
    return N;//retorna o endereço pra ser usado
    
}

//função empilha
void push(P_pilha Pil , void* dado){

  //alloca um espaço para o no da Pilha
  P_no X = malloc (sizeof (No));
  X->next = Pil->ini;// dá o prox endereço a ser utilizado
  X->dado = (void*) dado; //coloca o dado do tipo generico (void*) 
  Pil->ini = X; //seta o inicio (cabeça)
  Pil->topo++;  //aumenta o tamanho em 1

}

//função desempilha
void* pop(P_pilha Pil){
    //primeiro verifica se há algo a ser desempilhado, caso não retonra NULL
    if(Pil->ini== NULL){
      return NULL;
    }
    //coloca o X como um inicio novo
    P_no X = Pil->ini;
    //o ini vira o prox No
      Pil->ini = Pil->ini->next;
    //diminui 1 no tamanho da Pilha
      Pil->topo--;
    //cria um void* pra devolver o dado desempilhado
      void* Y = X->dado;
      free(X);//libera o no que foi desempilhado
      return Y;//retorna o dado generico
}


int tamanho_pilha(P_pilha p){
  return p->topo;
}

void destroi_pilha(P_pilha P){
  No *no = NULL;
  while (no != NULL) {
  	no = P->ini->next;
    P->ini->next = no->next;
    no->next = NULL;
    free(no);
  }
  free(P);
}

