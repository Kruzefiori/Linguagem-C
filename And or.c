#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

void main (){
    setlocale(LC_ALL ,"");

int a=5;
//and
if (a > 4 && a != 7){
    printf("\n\nteste 1");
}
//or
if(a>4 || a!=7){
    printf("\n\nse leu seu cu é meu");
}
}
