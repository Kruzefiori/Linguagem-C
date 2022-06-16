#include <stdio.h>
#include <stdlib.h>

#define M 466547

typedef struct cel {
int x;
int y;
struct cel* prox;
} celula;


int conta_pontos(celula * p){
if(p == NULL) return 0;
return 1 + conta_pontos(p->prox);

}

int hash(int x , int y){
return (x * y ) % M; 
}

void insere_na_tabela(celula** tabela , int x , int y)
{
int h = hash(x , y);
celula *p = tabela[h];
while(p != NULL && !(p->x == x && p->y == y) )p = p-> prox;

if(p == NULL){
//INSERE
celula * novo = (celula*) malloc(sizeof(celula));
novo -> x = x;
novo -> y = y;
novo -> prox = tabela[h];
tabela[h]=novo;
}

}

int main(int argc , char * argv[]){
    celula ** tabela =(celula**) malloc(M * sizeof(celula*));
    for(int i = 0 ; i < M; i++)tabela[i] = NULL;
    
    int quantidade_pontos;
    scanf("%d", &quantidade_pontos);
    srand(quantidade_pontos);
    for(int i= 0; i< quantidade_pontos; i++){
    int x = rand() % 1000;
    int y = rand() % 1000;
    insere_na_tabela(tabela, x,y);
    }
    
    for (int h = 0; h< M; h++){
    int x = conta_pontos(tabela[h]);
    printf("Tabela[%d] tem %d pontos\n" , h , x);
    }    

    
    return 0;
}
