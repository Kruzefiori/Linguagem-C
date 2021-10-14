#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

void main (){
    setlocale(LC_ALL ,"");
float a , b , c;


    printf("Insira 3 valores");
    scanf("%f %f %f" ,&a ,&b ,&c);

    if(a==b && b==c){
        printf("é um triângulo equilátero");
    }
    else {
        printf("Não é um triângulo equilátero");
    }

    }
