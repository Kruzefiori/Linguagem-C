#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

void main (){
    setlocale(LC_ALL, "");

    float n1 , n2 , n3 , m;

    printf("\nInsira aqui a nota 1\n");
    scanf("%f" , &n1);
    printf("\n\nInsira aqui a nota 2\n");
    scanf("%f" , &n2);
    printf("\n\nInsira aqui a nota 3\n");
    scanf("%f" , &n3);

    m = (n1+n2+n3)/3;

    if(m>=7){
        printf("APROVADO GARAI SUA MÉDIA FOI %f", m);

    }
    else {
        printf("REPROVADO BURRO FEIO IDIOTA SUA MÉDIA FOI %f" , m);
    }


}
