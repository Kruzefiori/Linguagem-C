//Código para encontrar o maior ponto ( x, y) e foi usado nos próximos trabalhos
#include<stdlib.h>
#include<stdio.h>

typedef struct p{
int x;
int y;
}Ponto;

//retorna -1 se o a for maior
//retorna 0 se a==b
//Retorna 1 se b> a
int compara( Ponto* a, Ponto* b){
    int X_a = a->x;
    int X_b = b->x;
    int Y_a = a->y;
    int Y_b = b->y;

    if(X_a == X_b && Y_a == Y_b)return 0;
    if (X_a > X_b)return -1;
    if(X_b > X_a)return 1;
    if (X_a == X_b){
    if(Y_a > Y_b)return -1;
    if (Y_b > Y_a) return 1;
    } 
return 10;
}

int main(int argc , char *argv[]){
    int tamanho;
    scanf("%d" , &tamanho);
    Ponto* v =(Ponto*) malloc(sizeof(Ponto)*tamanho);   
    srand(tamanho);    
    for(int i =0; i< tamanho; i++){
        v[i].x = rand()%tamanho;
        v[i].y = rand()%tamanho;
    }    
    for(int i = 0 ; i < tamanho; i++){
    printf("(%d, %d) ", v[i].x, v[i].y);
    }
    printf("\n");

    for(int i=0; i < tamanho -1; i++){
        for(int j= i+1; j<tamanho; j++){
            printf("(%d, %d) e (%d, %d) ", v[i].x , v[i].y , v[j].x , v[j].y);       
            int resultado = compara(&(v[i]), &(v[j]));
            if(resultado == -1){
                printf("maior: (%d, %d)\n" , v[i].x , v[i].y);
            }
            if(resultado == 1){
                printf("maior: (%d, %d)\n" , v[j].x , v[j].y);                           
            }
            if(resultado == 0){
                printf("maior: (%d, %d)\n" , v[i].x , v[i].y);
            }                    
        }
}
    

return 0;
}
