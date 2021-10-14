#include <stdio.h>
#include <stdlib.h>
#define OI 4

void main (){
// vetor = uma gaveta com varias variaveis
int vetor[OI], cont ;
//valores para o vetor

vetor[0]=4;
vetor[1]=5;
vetor[2]=6;
vetor[3]=7;

printf("\n\n%d\n\n" , vetor[0]);
printf("\n\n%d\n\n" , vetor[1]);
printf("\n\n%d\n\n" , vetor[2]);
printf("\n\n%d\n\n" , vetor[3]);


for(cont=0 ; cont<OI ; cont++){
    printf("\nposição %d : %d\n" ,cont , vetor[cont]);
}

 for (cont= 0 ; cont < OI ; cont++){
    scanf("%d" , &vetor[cont]);
}
for (cont= 0 ; cont < OI ; cont++){
printf("\n position %d : %d\n" ,cont , vetor[cont]);



    }}
