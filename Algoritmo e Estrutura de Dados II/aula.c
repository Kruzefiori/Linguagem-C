#include<stdio.h>
#include<stdlib.h>

//devolve um numero negativo se pa vem antes de pb na ordenação
//devolve um numero positivo se pb vem antes de pa na ordeção
//devolve zero se a ordenação deles não importa
int compara_inteiro(const void * pa, const void * pb){
    int * a = (int *) pa;
    int * b = (int *) pb;
    if(*a < *b)return -1;
    if(*a > *b)return 1;
    return 0;    
}

int compara_inteiro_desc(const void * pa, const void * pb){
    int * a = (int *) pa;
    int * b = (int *) pb;
    if(*a < *b)return 1;
    if(*a > *b)return -1;
    return 0;    
}

void imprime_inteiro(const void * pa){
    int *a = (int *) pa;
    printf("%d\n", *a);
return;
}

void imprime_string(const void * pa){
    char * a = (char*) pa;
    printf("%s\n",a);
    return;
}

typedef struct sele{
    void * valor;
    void (*imprime)(const void*);
}elemento;

int main(int argc, char * argv[]){
int * vetor = (int*) malloc(5* sizeof(int));
vetor[0] = 50;
vetor[1] = 10;
vetor[2] = 25;
vetor[3] = 40;
vetor[4] = 30;

qsort(vetor , 5, sizeof(int) , compara_inteiro);

for(int i = 0; i< 5; i++){
printf("%d\n" , vetor[i]);
}

int a = 5;
char * b = "teste";
int c = 4;
char * d = "com112";

elemento * v_generico =(elemento*) malloc(4*sizeof(elemento));
v_generico[0].valor = (void *) &a;
v_generico[0].imprime = imprime_inteiro;

v_generico[1].valor = (void *) b;
v_generico[1].imprime = imprime_string;

v_generico[2].valor = (void *) &c;
v_generico[2].imprime = imprime_inteiro;

v_generico[3].valor = (void *) d;
v_generico[3].imprime = imprime_string;

for(int i = 0; i<4;i++){
    v_generico[i].imprime(v_generico[i].valor);
}

free(vetor);
return 0;
}
