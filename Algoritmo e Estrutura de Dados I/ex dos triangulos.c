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
        printf("� um tri�ngulo equil�tero");
    }
    else {
        printf("N�o � um tri�ngulo equil�tero");
    }

    }
