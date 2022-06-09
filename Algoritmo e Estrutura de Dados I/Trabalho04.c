#include <stdio.h>
#include <stdlib.h>


int* alloca_vetor(int tam){
    int *aux;
    aux = (int*) malloc(tam * sizeof(int));
return aux;
}

int verifica(int* objetos, int quant_objetos, int peso_total, int peso_atual, int* resultado){

if(peso_atual == peso_total) return 1;

if (quant_objetos == 0) return 0;

if(peso_atual > peso_total) return 0;

resultado[quant_objetos - 1] = 1;

if(verifica(objetos, quant_objetos -1, peso_total, peso_atual + objetos[quant_objetos -1 ], resultado) ){
return 1;
}

resultado[quant_objetos - 1] = 0;
if(verifica(objetos, quant_objetos -1, peso_total, peso_atual , resultado) ){
return 1;
}

return 0;
}

void imprime_vet(int* V, int tam){
   for(int i=0 ; i< tam ;i++){
           printf("%d " , V[i]);
    }
}


void liberaV(int* V){
    free(V);
}



int main(){


    int peso;
    scanf("%d", &peso); // lê o valor do peso que o usuário quer receber a resposta.

    int NumObjs;
    scanf("%d", &NumObjs); // lê a quantidade de obejetos que tem

    int* VetorPesos = alloca_vetor(NumObjs);
    int* V_result = alloca_vetor(NumObjs);

    for (int x = 0 ; x < NumObjs ; x++){
        V_result[x]=0;
    }


    for(int i=0 ; i< NumObjs ; i++){
           scanf("%d" , &VetorPesos[i]);
    }

    verifica(VetorPesos, NumObjs , peso , 0 ,V_result);

    imprime_vet(V_result, NumObjs);

    return 0;
    }
