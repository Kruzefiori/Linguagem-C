//Selection Sort implementado e adaptado para funcionar com a Struct de pontos (x , y)
#include <stdio.h>
#include <stdlib.h>

typedef struct ponto
{
    int x;
    int y;
} Ponto;

int compara(Ponto *a, Ponto *b)
{
    //Se forem iguais
    if (a->x == b->x && a->y == b->y){
        return 0;
    }
    //se o x do A for maior que o x do B
    if (a->x > b->x){
        return -1;
    }
    //se o x do B for maior que o x do A
    if (b->x > a->x){
        return 1;
    }
    //se os x's forem iguais
    if (a->x == b->x)
    {
        //verifica o Y maior
        //y do A maior que o do B
        if (a->y > b->y){
            return -1;
        }
        //y do B maior que o do A
        if (b->y > a->y){
            return 1;
        }
        //2° verificação se os y's forem iguais
        if(b->y == a->y){
            return 0;
        }

    }
        //retorno padrão que a função pede por ser INT
       return 10;
    }

// Devolve -1 se a > b
// Devolve 0 se a == b
// Devolve 1 se b > a
//                  array       0       tam-1
int encontra_max(Ponto *v, int esq, int dir)
{
    int maior = esq;
    for (int i = esq+1; i < dir+1; i++)
    {                               //a       //b
            int resp = compara(&(v[maior]), &(v[i]));
            //a>
            //printf("%d" , resp);
            if (resp == -1)
            {
                maior = maior;
                //printf("%d" , maior);
            }
            //a = b
            if (resp == 0)
            {
                maior = maior;
                //printf("%d" , maior);
            }
            //b >
            if (resp == 1)
            {
                maior = i;
                //printf("%d" , maior);
            }
    }
    return maior;
}

// Ordena os pontos, obrigatoriamente deve usar a função
// encontra_max
void selection_sort(Ponto *v, int tamanho)
{
    if(tamanho == 0){
            return;
    }
  int indice = encontra_max(v, 0, tamanho-1);

  Ponto aux;

  aux.x = v[tamanho-1].x;
  aux.y = v[tamanho-1].y;
  v[tamanho-1].x= v[indice].x;
  v[tamanho-1].y= v[indice].y;
  v[indice].x= aux.x;
  v[indice].y= aux.y;

  selection_sort(v , tamanho-1);


}

int main(int argc, char *argv[])
{
  int tamanho;
  scanf("%d", &tamanho);
  Ponto *v = (Ponto *)malloc(sizeof(Ponto) * tamanho);

  srand(tamanho);
  for (int i = 0; i < tamanho; i++)
  {
    v[i].x = rand() % tamanho;
    v[i].y = rand() % tamanho;
  }

  int indice_maior = encontra_max(v, 0, tamanho - 1);

  printf("O maior é (%d, %d) ", v[indice_maior].x, v[indice_maior].y);
  printf("\n");

  selection_sort(v, tamanho);

  for (int i = 0; i < tamanho; i++)
  {
    printf("(%d, %d) ", v[i].x, v[i].y);
  }
  printf("\n");
}
