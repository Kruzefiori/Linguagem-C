#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

void main (){
    setlocale(LC_ALL ,"");
int a;
char b;

printf("\ninsira um número entre 1 e 3 e uma letra entre X Y ou Z:\n");
scanf("%d %ch", &a , &b);



switch(a){
case 1:
    printf("\no número é 1\n");
break;
case 2:
    printf("\no número é 2\n");
break;
case 3:
    printf("\no número é 3\n");
break;
}

switch(b){
case 'x':
   printf ("\nA letra é X\n");
    break;
case 'y':
   printf("\nA letra é Y\n");
    break;
case 'z':
   printf("\nA letra é Z\n");
    break;
}

    }
