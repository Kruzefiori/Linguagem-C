//Função HeapSort funcionando para a struct de 2 pontos (x , y)
#include<stdio.h>
#include<stdlib.h>

typedef struct ponto{
  int x;
  int y;
}Ponto;


int compara(Ponto *a, Ponto *b)
{//dei uma possivel melhorada no Compara, percebi que estava fazendo muitas
  //comparações e diminui o numéro delas.
  if (a->x == b->x && a->y == b->y) return 0;
  if(b->x > a->x || (b->x == a->x && b->y > a->y)) return 1;
  else return -1;
}
void switch_aux(Ponto *a, Ponto *b)
{//função auxiliar pra executar a troca de 2 pontos
  Ponto aux = *a;
  *a = *b;
  *b = aux;
}
void desce_heap(Ponto *heap, int n, int pos)
{
  int esq = 2 * pos + 1;
  int dir = 2 * pos + 2;
  int maior_filho;
  if (esq >= n)
  {
    return;
  }
  // compara com o filho esquerdo que é maior que o direito
  if (compara(&heap[esq], &heap[dir]) == -1)
    maior_filho = esq;
  else
    maior_filho = dir;
  // verifica o maior entre filho e pai e troca caso necessário
  if (compara(&heap[maior_filho], &heap[pos]) == -1)
  {
    switch_aux(&heap[pos], &heap[maior_filho]);
    desce_heap(heap, n, maior_filho);//ajusta recursivamente o heap
  }
}

Ponto extrair(Ponto *heap, int n)
{
  Ponto maior = heap[0];
  heap[0] = heap[n - 1];
  desce_heap(heap, n - 1, 0);//extrai ultimo e ajusta o heap de forma recursiva
  return maior;//retorna o ponto maior que é o da raiz
}

void constroi_heap(Ponto *v, int n){
    for(int i = n/2 ; i >= 0; i--){
      desce_heap(v, n, i);
    }
}
void selection_sort(Ponto *v, int tamanho)
{//Mudei o Selection estava funcionando por recursividade
  // mas no caso teste de 1 milhão ele dava Timeout por uma stack muito
  //grande de recursividade e adaptei pra funcionar com um for.
  for (int i = 0; i< tamanho ; i++){
    Ponto indice = extrair( v , tamanho - i );
    //ao inves do swicth tentei usar o insere pra manter o heap arrumado
    //mas daria um problema de recursividade também já que funciona com
    //recursividade
    switch_aux(&v[tamanho- 1 - i] , &indice);
  }
}

void HeapSort(Ponto *v, int tamanho){
  //constroi o Heap
  constroi_heap(v , tamanho);
  //chama o selection sort adaptado pra heap
  selection_sort(v , tamanho);
}

//************* NAO MODIFIQUE A MAIN ****************/
int main(int argc, char * argv[]){
  int tamanho;
  scanf("%d", &tamanho);
  Ponto * v = (Ponto *) malloc(sizeof(Ponto)*tamanho);

  srand(tamanho);
  for(int i = 0; i < tamanho; i++){
    v[i].x = rand()%tamanho;
    v[i].y = rand()%tamanho;
  }

  HeapSort(v, tamanho);

  //imprimido a cada 1% (mais ou menos)
  for(int i = 0; i < tamanho; i += (tamanho/100) + 1){
    printf("(%d, %d) ", v[i].x, v[i].y);
  }
  printf("\n");
}

