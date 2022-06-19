#include <stdio.h>

//Você deverá modificar apenas a função abaixo, você
//não pode modificar a assinatura dela
int concatena(char* s1, char* s2, char* sres, int* espacos){
  //===============
  //variáveis: i e j para contar a string, cont e spa para auxiliar a contar espaços e caracteres.
    int i,j,cont,spa;
    spa=0; //coloquei separado pois estava dando erro e só depois percebi que tinha que definir como 0
    cont=0;
//verifica a string 1 casa por casa até ter um "contra barra" 0 (fim) e passa casa por casa para a string sres
    for(i=0;s1[i]!='\0';i++)
    {
        sres[i]=s1[i];//aqui onde passa caractere por caractere para Sres
    }
    sres[i-1]=' ';//espaço para não misturar s1 com s2

    for(j=0;s2[j]!='\n';j++)//verifica a string 2 caractere por caractere e passa para a string resposta
    {
        sres[i]=s2[j];
        i++;
    }
    sres[i]='\0';//termina a string se não tiver mais caracteres.
    for(i=0;sres[i]!='\0';i++)//conta caractere e soma para a variavel cont
    {
      cont++;
    if(sres[i]==' ')//conta os espaços e soma a variavel spa.
        {
        spa++;
        }

    }
    *espacos=spa;//passa o valor de spa para espacos utilizando ponteiro.
  //===============
return cont;
//tentei fazer por laço de repetição While porém não estava conseguindo verificar corretamente a string 1 e 2 e acabei optando por usar for e if
}

//Funcao para imprimir uma string, NÃO MODIFIQUE
void print_string(char* str){
  int k = 0;
  while(str[k] != '\0'){
    printf("%c", str[k]);
    k++;
  }
  printf("\n");
}

//NÂO MODIFIQUE a main
int main(int argc, char * argv[]){
  char frase1[40];
  char frase2[40];
  char fraseResultado[80];
  int tamResultado;
  int espacos;

  //lendo a entrada
  fgets(frase1, 40, stdin);
  fgets(frase2, 40, stdin);

  tamResultado = concatena(frase1, frase2, fraseResultado, &espacos);

  print_string(fraseResultado);
  printf("String com %d caracteres e %d espacos.\n", tamResultado, espacos);

  return 0;
}
