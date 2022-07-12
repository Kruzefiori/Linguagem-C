#include <stdio.h>
#include <stdlib.h>

//PROCURE A PALAVRA "TODO" (de TO DO) PARA VER O QUE PRECISA MUDAR
//NAO ALTERE OS PONTOS SORTEADOS PARA OS BARCOS E TIROS
//Procure mexer o minimo possivel na main.
//basicamente voce precisa implementar as funcoes
//"adiciona_ponto" e "busca_ponto"
typedef struct oceano{
  
}


int main(int argc, char * argv[]){
  int dimensao;
  int num_pontos;
  int num_tiros;
  
  //TODO: GUARDAR OS OCEANOS DE A E B, MUDE PARA A ESTRUTURA
  //DE DADOS QUE VOCE QUISER
  oceano pontosJA = NULL;
  oceano pontosJB = NULL;
  
  
  scanf("%d %d %d", &dimensao, &num_pontos, &num_tiros);
  printf("Campo %d x %d\nCada jogador coloca %d barcos\n\n", dimensao, dimensao, num_pontos);
  
  //Definindo uma semente para gerar os mesmos pontos
  srand(dimensao);

  //Jogador A gera pontos para colocar os barcos
  printf("Jogador A coloca barcos:\n");
  for(int i = 0; i < num_pontos; i++){
    int x, y;
    //sorteia um ponto que ja nao tenha um barco
    do{
      x = rand() % dimensao;
      y = rand() % dimensao;
    }while(busca_ponto(pontosJA, x, y) != 0); //TODO: Procura no oceano A se x, y ja tem barco
  
    if(i<5) printf("(%d, %d)\n", x, y);
    
    pontosJA = adiciona_ponto(pontosJA, x, y); //TODO: Adiciona x, y no oceano A
  }
  
  
  //Jogador 2 gera pontos, com a estrategia (duvidosa) de colocar os pontos 
  //em mais ou menos em ordem crescente.
  printf("...\n\nJogador B coloca barcos:\n");
  for(int i = 0; i < num_pontos; i++){
    int x, y;
    //sorteia um ponto que ja nao tenha um barco
    do{
      x = i % dimensao;
      y = rand() % dimensao;
    }while(busca_ponto(pontosJB, x, y) != 0); //TODO: Procura no oceano B se x, y ja tem barco
      
    if(i<5) printf("(%d, %d)\n", x, y);
    
    pontosJB = adiciona_ponto(pontosJB, x, y); //TODO: Adiciona x, y no oceano B
  }
  
  printf("...\n\nCada jogador vai dar %d tiros\n", num_tiros);
  
  
  //Jogador 1 ataca pontos (aleatorios)
  int acertosJA = 0;
  printf("\nJogador A atira:\n");
  for(int i = 0; i < num_tiros; i++){
    int x = rand() % dimensao;
    int y = rand() % dimensao;
    if(i<5) printf("(%d, %d)\n", x, y);
    
    //Jogador A ataca os pontos de B
    if(busca_ponto(pontosJB, x, y) == 1) acertosJA++; //TODO: Procura no oceano B se x, y tem barco
  }
  
  //Jogador B ataca pontos (aleatorios)
  int acertosJB = 0;
  printf("...\n\nJogador B atira:\n");
  for(int i = 0; i < num_tiros; i++){
    int x = rand() % dimensao;
    int y = rand() % dimensao;
    if(i<5) printf("(%d, %d)\n", x, y);

    //Jogador B ataca os pontos de A
    if(busca_ponto(pontosJA, x, y) == 1) acertosJB++;  //TODO: Procura no oceano A se x, y ja tem barco
  }
  
  printf("...\n\nResultado: Jogador A acertou %d e Jogador B %d\n", acertosJA, acertosJB);
  
  libera_oceano(pontosJA); libera_oceano(pontosJB); //TODO: Liberar memorias
  return 0;
}
