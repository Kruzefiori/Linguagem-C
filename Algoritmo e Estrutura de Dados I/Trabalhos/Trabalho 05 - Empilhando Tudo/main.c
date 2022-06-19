#include <stdlib.h>
#include <stdio.h>

//pilha.h do projeto
#include "Pilha.h"

int main(){
//cria a pilha no sistema
P_pilha p = criar_pilha();
char option; // variavel usada pra ler
int cont = 0; //variavel NÃO utilizada mas que o tamanho só funciona com ela existindo (não entendo o pq)
scanf("%c", &option);//Lê a primeira opção

do{
  //chamada de opção pra empilhar o valor lido
    if(option == 'e'){

      char* x = malloc (4 * sizeof(char));//alloca um endereço de char* pra enviar à função push
      scanf("%s" , x); //lê o valor pra ser empilhado
      push( p , x);//chamada da função push

    }

    if(option== 'd'){

      char* d = 0; // cria uma variavel pra receber o retorno da desempilha
      d =(char*) pop(p);//chama a função que retorna o valor desempilhado
      printf("%s\n" , d );//imprime o valor desempilhado

    }

    if(option== 't'){   

      printf("%d\n" , p->topo); //imprime o valor do tamanho (inteiro)

    }

      scanf("%s", &option); // lê novamente a opção 
      
}while (option!='x');//sai se a opção for x

destroi_pilha(p);

return 0;//retorna sem erros
}
