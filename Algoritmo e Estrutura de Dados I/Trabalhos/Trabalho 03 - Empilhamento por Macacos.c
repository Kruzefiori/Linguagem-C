#include <stdio.h>
#include <stdlib.h>

//SUGESTAO DE ESTRUTURA PARA GUARDAR UM BLOCO
//PODE MUDAR SE QUISER
//estrutura bloco
typedef struct bloco{
  int id;
  int altura;
  struct bloco* prox;
} bloco;

typedef struct bloco * p_Bloco;


//SUGESTAO DE ESTRUTURA PARA GUARDAR UM MACACO
//PODE MUDAR SE QUISER

//estrutura macaco
typedef struct Macaco{
  int altura;
  struct bloco* lista_blocos;
} Macaco;

typedef struct Macaco * p_Macaco;

//inicializa macaco - recebe numero de macacos como parametro
p_Macaco inicializa_macacos(int N_macacos){

    //auxiliar do tipo p_macaco
    p_Macaco aux;

    //aloca dinamicamente
    aux = malloc(N_macacos * sizeof(Macaco));

    //define como 0 a altura e a lista_blocos pra resetar a memória
    for(int i=0; i<N_macacos; i++){
        aux[i].altura=0;
        aux[i].lista_blocos= NULL;
    }
//retorna aux do tipo p_macaco
return aux;
}

//SUGESTAO DE FUNCOES PARA IMPRESSAO
//PODE MUDAR SE QUISER
void imprime_blocos(p_Bloco lista){
  if(lista == NULL) return;
  imprime_blocos(lista->prox);
  printf(" %d %d", lista->id, lista->altura);
}

void imprime_macacos(p_Macaco M, int num_macacos){
  for(int i = 0; i < num_macacos; i++){
    printf("M[%d] altura = %d:", i, M[i].altura);
    imprime_blocos(M[i].lista_blocos);
    printf("\n");
  }
}

//Push - enfileirar o bloco recebido
p_Bloco Push(int ID, int Altura, p_Bloco L){

    //aloca dinamicamente o bloco novo
    p_Bloco novo = (p_Bloco) malloc(sizeof(bloco));

    //coloca sua altura . id e o endereço do prox bloco
    novo->altura = Altura;
    novo->id = ID;
    novo->prox = L;

    // retorna o "novo" do tipo p_bloco
return novo;
}

p_Macaco bota_no_menor(p_Macaco M, int NumeroMacaco, int ID, int Altura){
   //variaveis auxiliares, percorrer e saber onde está o macaco mais baixo
    int j=0, Positmacaquinho=0;

    //define o menor macaco no posit macaquinho
    for(j=0 ; j<NumeroMacaco; j++){
        if(M[j].altura < M[Positmacaquinho].altura){
            Positmacaquinho = j;
        }
    }

    //aumenta a altura recebido no macaco na posição do menor macaquinho
    M[Positmacaquinho].altura = M[Positmacaquinho].altura + Altura;

    //chama o push pra colocar a nova altura, id e o endereço do prox
   M[Positmacaquinho].lista_blocos = Push( ID, Altura, M[Positmacaquinho].lista_blocos);
//retorna M do tipo p_macaco
return M;
}

//funcao pra quebrar(free) bloco por bloco antes de dar free no macaco inteiro
void quebra_barraco(p_Bloco Tijolo){
    if(Tijolo == NULL)//se o tijolo for NULL não faz nada
    quebra_barraco(Tijolo->prox);//recursão pra ir pro próximo tijolo
    free(Tijolo);//quebra o ultimo bloco voltando um por um através da recursividade
}

void libera_macacos (p_Macaco Mamaco, int num_macacos){

    for (int x=0; x<num_macacos; x++){
        quebra_barraco(Mamaco[x].lista_blocos);//quebra todos os blocos chamando a função quebra_barraco
    }
    free(Mamaco);//pra só depois dar free no macaco.
}


//******************************
//VOCE NAO PODE MODIFICAR A MAIN
//******************************
int main(int argc, char * argv[]){

  p_Macaco M;
  int num_macacos;
  int id_bloco;
  int altura_bloco;

  //le o numero de macacos
  scanf("%d", &num_macacos);

  M = inicializa_macacos(num_macacos);

  //le o primeiro bloco
  scanf("%d %d", &id_bloco, &altura_bloco);
  while(id_bloco != -1){
    bota_no_menor(M, num_macacos, id_bloco, altura_bloco);
    //le o proximo bloco
    scanf("%d %d", &id_bloco, &altura_bloco);
  }

  imprime_macacos(M, num_macacos);

  //Lembre que cada macaca tem uma lista que precisa ser liberada
  libera_macacos(M, num_macacos);
  return 0;
}




