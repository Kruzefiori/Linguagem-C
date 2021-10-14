#include <stdio.h>

menosum();
aumentaum();

int main(){
    int a;

    printf("digite um valor para A:");
    scanf("%d", &a);
    aumentaum(a);
    menosum(a);
}

int menosum(int Menosum){
printf("\nO antecessor de %d eh %d\n", Menosum , Menosum -1);
}
int aumentaum(int Maisum){
    printf("\nO sucessor de %d eh %d\n",Maisum , Maisum + 1);
}
