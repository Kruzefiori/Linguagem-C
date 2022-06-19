#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

typedef struct tno{
  char c;
}no;

no* cria_no(char c){
  no* N = (no*) malloc(sizeof(no));
  N->c = c;
  return N;
}

//funcao que recebe um endereco de no (mas como void*)
//faz o cast para um ponteiro de no, e ja libera
//a memoria do no.
char abre_no(void* Nn){
  no* N = (no*) Nn;
  char aux = N->c;
  free(N);
  return aux;
}

int main(){
  int i, linha = 1;
  char aux, aux2;
  P_pilha P = criar_pilha();

  //scanf devolve -1 caso nao consiga ler nenhum caractere.
  //vou usar isso para encerrar o laço principal.
  i = scanf("%c", &aux);
  while(i >= 0){
    if(aux == '\n') {
      ++linha;
    }
    
    switch (aux){
      
      //Caso abra parenteses, colchetes ou chaves.
      case '(':
        push(P, (void*) cria_no('('));
        break;
      case '[':
        push(P, (void*) cria_no('['));
        break;
      case '{':
        push(P, (void*) cria_no('{'));
        break;
        
      //Caso feche parenteses, colchetes ou chaves.
      case ']':
        if(tamanho_pilha(P) == 0 || abre_no(pop(P)) != '['){
          printf("Problema com ']' na linha %d\n", linha);
          destroi_pilha(P);
          return 0;
        }
        break;
      case ')':
        if(tamanho_pilha(P) == 0 || abre_no(pop(P)) != '('){
          printf("1Problema com ')' na linha %d\n", linha);
          destroi_pilha(P);
          return 0;
        }
        break;
      case '}':
        if(tamanho_pilha(P) == 0 || abre_no(pop(P)) != '{'){
          printf("Problema com '}' na linha %d\n", linha);
          destroi_pilha(P);
          return 0;
        }
        break;
      default:
        break;  
    }
    
    i = scanf("%c", &aux);
  }
  
  //Se sobrou algo na pilha no final da entrada, entao algo deixou de ser fechado.
  if(tamanho_pilha(P) != 0){
    aux2 = abre_no(pop(P));
    printf("Sobrou um '%c'\n", aux2);
  }else{
    printf("tudo ok\n");
  }
  

  destroi_pilha(P);
  
  return 0;
}
