//Heap apenas
#include <stdio.h>
#include <stdlib.h>

typedef struct ponto
{
  int x;
  int y;
} Ponto;

// retorna -1 se o a for maior
// retorna 0 se a==b
// Retorna 1 se b> a
// Função compara exatamente igual ao código anteriro
int compara(Ponto *a, Ponto *b)
{
  int X_a = a->x;
  int X_b = b->x;
  int Y_a = a->y;
  int Y_b = b->y;
  if (X_a == X_b && Y_a == Y_b)
    return 0;
  if (X_a > X_b)
    return -1;
  if (X_b > X_a)
    return 1;
  if (X_a == X_b)
  {
    if (Y_a > Y_b)
      return -1;
    if (Y_b > Y_a)
      return 1;
  }
  return 10;
}
// função switch pra trocar os pontos e facilitar a compreensão dentro do corpo do código
void switch_aux(Ponto *a, Ponto *b)
{
  Ponto aux = *a;
  *a = *b;
  *b = aux;
}
// sobe Heap igual a função dada no arquivo mas_heap, porém adaptada para funcionar com pontos X e Y
void sobe_heap(Ponto *heap, int pos)
{
  if (pos == 0)
    return;                //
  int pai = (pos - 1) / 2; // seta um pivo
  // inversão?
  if (compara(&heap[pos], &heap[pai]) == -1)
  { // compara o maior para ver se é preciso haver a troca e subir no heap
    switch_aux((&heap[pos]), (&heap[pai]));
    sobe_heap(heap, pai);
  }
}
// desce Heap igual a função dada no arquivo mas_heap, porém adaptada para funcionar com pontos X e Y
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
  if (dir < n && compara(&heap[esq], &heap[dir]) == -1)
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
  return maior;
}
void insere(Ponto *heap, int n, Ponto *valor)
{
  heap[n] = *valor;//insere na ultima posicao
  sobe_heap(heap, n);//vai subindo e acertando o heap recursivamente
  return;
}

void constroi_heap(Ponto *v, int n){
    for(int i = n/2 ; i >= 0; i--){
      desce_heap(v, n, i);
    }
}

int main(int argc, char *argv[])
{
  int tamanho, tam_aux;//tamanho auxiliar
  Ponto aux; // para usar no FOR e receber os valores de inserção e remoção
  scanf("%d", &tamanho);
  // FAZER: CRIAR/ALOCAR MEMORIA PARA O HEAP
  Ponto *heap = (Ponto *)malloc(sizeof(Ponto) * tamanho); // Heap que armazena pontos
  constroi_heap(heap , tamanho);
  srand(tamanho);
  printf("Inserindo %d pontos\n", tamanho / 2);
  for (int i = 0; i < tamanho / 2; i++)
  {
    aux.x = rand() % tamanho;
    aux.y = rand() % tamanho;
    // FAZER: AQUI VOCE INSERE O PONTO (x, y) no heap
    insere(heap, i, &aux);
  }
  printf("Extraindo os %d maiores\n", tamanho / 4);
  for (int i = 0; i < tamanho / 4; i++)
  {
    // FAZER: Extrair e imprimir
    aux = extrair(heap, tamanho / 2 - i);//regra de heap para achar o maior
    printf("(%d, %d) ", aux.x, aux.y);
    tam_aux = tamanho / 2 - i;
  }
  printf("\n");
  printf("Inserindo %d pontos\n", 3 * tamanho / 4);
  for (int i = 0; i < 3 * tamanho / 4; i++)
  {
    aux.x = rand() % tamanho;
    aux.y = rand() % tamanho;
    // FAZER: AQUI VOCE INSERE O PONTO (x, y) no heap
    insere(heap, tam_aux++, &aux);
  }
  printf("Extraindo os %d maiores\n", tamanho / 2);
  for (int i = 0; i < tamanho / 2; i++)
  {
    // FAZER: Extrair e imprimir
    aux = extrair(heap, tam_aux--);//extrai o maior e vai imprimindo
    printf("(%d, %d) ", aux.x, aux.y);
  }
  printf("\n");
  // FAZER: Liberar memória
  free(heap);
  return 0;
}
