#include <stdio.h>
#include <stdlib.h>

void liberaConjunto(int *X){
free(X);
}

//Implemente as funcoes necessarias
int* iniciaVetor(int Nx){
    int *aux;//auxiliar para alocar um espaço na memoria // * pois apresenta um apontador para endereço
    //(int*) força a função a me retornar um ponteiro de int
    aux = (int*) malloc(Nx * sizeof(int));//o auxiliar é igual ao espaço do vetor colocado pelo usuário vezes o tamanho da variável
    return aux;//retorna o primeiro espaço que o usuario vai usar no vetor alocado
}



//uniao(A, nA, B, nB, &nC)
int* uniao(int *va ,int na ,int* vb ,int nb ,int* U){
    int i,j;//variaveis auxiliares
    int cont=0;//auxiliar para saber onde o vetor R para depois de passar o vetor A
    int* vetorR = (int*) malloc((na+nb) * sizeof(int));//aloca espaço para o vetor R
    int auxo;//auxiliar para ordenar

    for(i=0; i<na; i++){
            vetorR[i]=va[i];//passa o vetor A para o resposta
    }
    cont=i;
    for(j=0; j<nb; j++){
      int repet=0;//estabelece uma variável para colocar uma condição para passar ou não do vetor B para o Resposta
        for(int k=0; k<i ; k++){
          if(vb[j]==vetorR[k]){
              repet++;//se for igual aumenta 1 na variável
          }
        }
        if(repet==0){
          vetorR[cont]=vb[j];//passa o vetor B para o Resposta somente se não for igual ao vetor 1
          cont++;//vai pro prox endereço do vetor resposta
        }
    }

    for(i=0; i<cont; i++){
        for(j=i; j<cont; j++){
            if(vetorR[i]>vetorR[j]){
                    auxo=vetorR[i];
                    vetorR[i]=vetorR[j];
                    vetorR[j]=auxo;//ordena o vetor com o auxilio de uma variavel
            }
        }
    }

    int* vetoru =(int*) malloc (cont * sizeof(int));//aloca o vetor do tamanho correto
    *U= cont;//passa pro endereço de nC (&nC) o valor correto do tamanho

    for(i=0;i<cont;i++){
      vetoru[i]=vetorR[i];//passa para o vetor U .
    }
    liberaConjunto(vetorR);//libera o vetor R
return  vetoru;
}


//imprime conjunto
void imprimeConjunto(int* vetor, int Tam){
    int i;

    for(i=0;i<Tam;i++){
        printf("%d ",vetor[i]);//percorre o vetor para imprimir ele inteiro de acordo com o tamanho estabelecido
    }
    printf("\n");
}
//interseccao
int* interseccao(int *va ,int na ,int* vb ,int nb ,int*  I){
    int i,j , conta=0, contb=0, contc=0 , auxo;
    int* vetorRi = (int*) malloc((na+nb) * sizeof(int));//aloca o vetor Ri do tamanho estabelecido

    for(i=0; i<na; i++){
        for(j=0; j < na ;j++ ){
            if( (va[j] == va[i]) && (i!=j)){
                    va[i]= ' ';
                    conta++;//Se o vetor A tiver algum igual ele elimina ele
            }
        }
    }

    for(i=0; i<na; i++){
        for(j=i; j<na; j++){
            if(va[i]>va[j]){
                    auxo=va[i];
                    va[i]=va[j];
                    va[j]=auxo;//ordena o vetor A
            }
        }
    }

    for(i=0; i<nb; i++){
        for(j=0; j < nb ;j++ ){
            if( (vb[j] == vb[i]) && (i!=j)){
                    vb[i]= ' ' ;
                    contb++;//elimina os igual do vetor B
            }
        }
    }

    for(i=0; i<nb; i++){
        for(j=i; j<nb; j++){
            if(vb[i]>vb[j]){
                    auxo=vb[i];
                    vb[i]=vb[j];
                    vb[j]=auxo;//ordena o vetor B
            }
        }
    }

for(i=0; i<na-conta; i++){//percorre o vetor até a posição Nb menos a quantidade de vezes que o vetor A repetiu
    for(j=0; j<nb-contb; j++){//percorre o vetor até a posição Nb menos a quantidade de vezes que o vetor B repetiu
        if(va[i]==vb[j]){//se o vetor A na posição i for igual ao B na J
            vetorRi[contc]=va[i];//ele passa para Ri .
            contc++;//percorre +1 no vetor quando ele receber um vator
        }
    }
}
int* vetorx= malloc(contc * sizeof(int)); //aloca um novo vetor do tamanho certo

 for(i=0;i<contc;i++){
      vetorx[i] = vetorRi[i];//passa o vetor Ri para o vetor que será retornado
    }
liberaConjunto(vetorRi);//libera o vetor

*I= contc;//passa por referencia o valor correto do tamanho do vetor
//imprimeConjunto(vetorRi,I);// Chamada da função pra verificar se está calculando a intersecção corretamente
return vetorx;
}
//Libera a memória alocada na função Malloc


//NAO ALTERE A MAIN
int main(int argc, char * argv[]){
  int* A;
  int* B;
  int* C;
  int* D;
  int nA, nB, nC, nD, aux;

  //inicializando e lendo o conjunto A
  scanf("%d", &nA);
  A = iniciaVetor(nA);
  for(int i = 0; i < nA; i++){
    scanf("%d", &aux);
    A[i] = aux;
  }

  //inicializando e lendo o conjunto B
  scanf("%d", &nB);
  B = iniciaVetor(nB);
  for(int i = 0; i < nB; i++){
   scanf("%d", &aux);
    B[i] = aux;
  }

  //calcula e imprime a uniao e a interseccao
  C = uniao(A, nA, B, nB, &nC);
  imprimeConjunto(C, nC);

  D = interseccao(A, nA, B, nB, &nD);
  imprimeConjunto(D, nD);

  //libera a memoria dos 4 vetores
  liberaConjunto(A);
  liberaConjunto(B);
  liberaConjunto(C);
  liberaConjunto(D);

  return 0;
}
