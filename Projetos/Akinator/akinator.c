#include<stdio.h>
#include<stdlib.h>

#define DEBUG 0

typedef struct sno{
char * string;
struct sno * esq;
struct sno * dir;
}no;

no* criar_no(char* str){
    no* novo = (no*) malloc(sizeof(no));
    novo->string = str;
    novo->dir = NULL;
    novo->esq = NULL;
return novo;
}

no* criar_arvore(char ** perguntas, int nr_perg){
    if(nr_perg == 0) return NULL;
    no* arvore = criar_no(perguntas[0]);
    arvore->esq = criar_arvore(&perguntas[1] , nr_perg -1);
    arvore->dir = criar_arvore(&perguntas[1] , nr_perg -1);
return arvore;
}

void insere_personagem(no * arvore , char * nome_personagem, int* respostas, int nr_perguntas){
no* atual = arvore;
    for(int i = 0; i< nr_perguntas -1 ; i++){
        if(respostas[i] == 1) atual = atual->esq;
        else atual = atual->dir;
    }
    if(respostas[nr_perguntas -1] == 1) atual->esq = criar_no(nome_personagem);
    else atual->dir = criar_no(nome_personagem);
return;
}


void le_ate(FILE * f, char c, char * str){
   char aux;
   int i = 0;
   fscanf(f, "%c", &aux);
   while(aux != c){
     str[i++] = aux;
     fscanf(f, "%c", &aux);
   }
   str[i] = '\0';
   return;
}

int main(int argc, char * argv[]){
  int num_personagens;
  int num_perguntas;
  char aux[1024]; // usado para ler lixo
  int auxi;  //usado para ler lixo
  char ** perguntas; //arranjo para guardar as perguntas
  char ** nome_personagens; //arranjo para guardar o nome dos personagens
  int ** respostas; //arranjo para guardar as respostas reposta[p][i] Ã© a resposta do personagem p para a pergunta i
  
  FILE * file_perguntas = fopen("perguntas.csv", "r");
  if(file_perguntas == NULL){
    printf("Erro ao abrir arquivo\n");
    return -1;
  }
  
  //Lendo o numero de personagens e o numero de perguntas
  fscanf(file_perguntas, "%d", &num_personagens);
  fscanf(file_perguntas, "%d", &num_perguntas);

  //alocando memorias
  perguntas = (char**) malloc(sizeof(char *)*num_perguntas);
  for(int i = 0; i < num_perguntas; i++){
    perguntas[i] = (char*) malloc(sizeof(char) * 1024); //nenhuma pergunta vai poder ter mais que 1024 caracteres.
  }
  
  respostas = (int **) malloc(sizeof(int *)*num_personagens);
  nome_personagens = (char**) malloc(sizeof(char *)*num_personagens);
  for(int p = 0; p < num_personagens; p++){
    respostas[p] = (int *) malloc(sizeof(int)*num_perguntas);
    nome_personagens[p] = (char *) malloc(sizeof(char) * 128); //cada nome nÃ£o pode passar de 128
  }
  
  //lendo o arquivo 
  le_ate(file_perguntas, ',', aux); //le a primeira virgula
  if(DEBUG) printf("aux = %s\n", aux);
  le_ate(file_perguntas, ',', aux); //le o "Quantos iguais"
  if(DEBUG) printf("aux = %s\n", aux);
  
  //lendo as perguntas
  for(int i = 0; i < num_perguntas; i++){
    le_ate(file_perguntas, ',', perguntas[i]);
  }
  
  if(DEBUG){
    for(int i = 0; i < num_perguntas; i++){
      printf("Pergunta %d: %s\n", i+1, perguntas[i]);
    }
  }
  le_ate(file_perguntas, '\n', aux); //ignora tudo atÃ© a quebra de linha
  
  //lendo os personagens e suas respostas
  for(int p = 0; p < num_personagens; p++){
    le_ate(file_perguntas, ',', nome_personagens[p]); //ignora tudo atÃ© a quebra de linha
    fscanf(file_perguntas, "%d,", &auxi); //le o numero de repetiÃ§Ãµes
    for(int i = 0; i < num_perguntas; i++){
      fscanf(file_perguntas, "%d,", &(respostas[p][i]));
    }
    //le o resto da linha, exceto o ultimo pois
    //o ultimo personagem talvez nÃ£o tenha uma quebra de linha
    if(p != num_personagens-1) le_ate(file_perguntas, '\n', aux); 
  }
  fclose(file_perguntas);
  
  if(DEBUG){
    for(int p = 0; p < num_personagens; p++){
      printf("%s: ", nome_personagens[p]); 
      for(int i = 0; i < num_perguntas; i++){
        printf("%d ", respostas[p][i]); 
      }
      printf("\n");
    }
  }
  
  
  
  //COMECANDO A CRIACAO DA ARVORE
    no * arvore = criar_arvore(perguntas , num_perguntas);
    
    for(int i = 0 ; i< num_personagens; i++){
    insere_personagem(arvore, nome_personagens[i], respostas[i], num_perguntas);
}

    int op= 2;
    no* atual = arvore;
    while(op != -1){
        if(atual == NULL) atual = arvore;
        printf("%s\n",atual->string);        
        scanf("%d", &op);
        if(op == 1) atual = atual->esq;
        if(op == 0) atual = atual->dir;
        if(op == -1) break;
    }  
  
    
  
  //LIBERANDO MEMORIA lembre de liberar a arvore tambem;  
  for(int i = 0; i < num_perguntas; i++) free(perguntas[i]);
  free(perguntas);
  for(int p = 0; p < num_personagens; p++){
    free(respostas[p]);
    free(nome_personagens[p]);
  }
  free(nome_personagens);
  free(respostas);
}
