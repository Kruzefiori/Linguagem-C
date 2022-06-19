#include <stdio.h>
#include <stdlib.h>
//no caso desse exercicio seria possivel utilizar a lib stdbool para fazer a função calcula

int* alloca_vetor(int tam){
    int *aux;//aux é um ponteiro para a primeira posição allocada para o vetor
    aux = (int*) malloc(tam * sizeof(int)); // alloca o vetor dinamicamente
return aux; // retorna o primeiro endereço a ser usado pelo vetor
}

int calcula(int* objetos, int quant_objetos, int peso_alvo, int peso_atual, int* resultado){
//recebe o vetor dos pesos e a quantidade de objetos como parametro, o peso total e o atual, para criar o vetor resultado com 0 e 1
if(peso_atual == peso_alvo) return 1;//se o peso atual for igual ao peso alvo ele retorna 1 (verdadeiro), com o vetor resultado construido corretamente

if (quant_objetos == 0) return 0; // se a quantidade de objetos restantes for 0, ele retorna falso pois não é possivel montar o peso com os escolhidos , volta no stack da recursividade

if(peso_atual > peso_alvo) return 0; // se o peso atual passar do peso alvo ele volta falso

resultado[quant_objetos - 1] = 1;// coloca 1 no vetor resultado na ultima posição, mais fácil começar do final pois não precisaria passar um indice a mais nos parametros pra começar da posição 0
//sempre que a recursividade é usada nesse caso, envia-se parametros menores para analisar todas as opções até achar a correta, como estou trabalhando com vetor resultado para indicar a resposta
//toda chamada altera a resposta pois o vetor é similar a usar ponteiros e mudar por referência.
if(calcula(objetos, quant_objetos -1, peso_alvo, peso_atual + objetos[quant_objetos -1 ], resultado) ){
return 1;//verifica se o calculo está certo e chama a função, se ele retornar 1 (verdadeiro) significa que o vetor resultado já foi construido corretamente
}

resultado[quant_objetos - 1] = 0;//caso o if acima retorne falso, ele volta pra 0 o vetor resultado na posição indicada
if(calcula(objetos, quant_objetos -1, peso_alvo, peso_atual , resultado) ){
return 1;//e faz o calculo novamente, caso retorne verdadeiro, o resultado estará correto.
}
//ultimo return nunca é usado mas a função por ser inteiro pede um retorno inteiro no final.

return 0;
}

void imprime_vet(int* V, int tam){//função simples para imprimir o vetor resultado
   for(int i=0 ; i< tam ;i++){
           printf("%d " , V[i]);
    }
    printf("\n"); // quebra de linha no final
}


void liberaV(int* V){
    free(V);//libera a memória allocada.
}



int main(){


    int peso;
    scanf("%d", &peso); // lê o valor do peso que o usuário quer receber a resposta.

    int NumObjs;
    scanf("%d", &NumObjs); // lê a quantidade de objetos que tem

    int* VetorPesos = alloca_vetor(NumObjs);//inicializa o vetor
    int* V_result = alloca_vetor(NumObjs);//inicializa o vetor

    for (int x = 0 ; x < NumObjs ; x++){
        V_result[x]=0;//zera o vetor resultado para evitar possiveis erros de lixo de memória
    }


    for(int i=0 ; i< NumObjs ; i++){
           scanf("%d" , &VetorPesos[i]);
    }//lê todos os pesos que o usuário colocar

    calcula(VetorPesos, NumObjs , peso , 0 ,V_result);//chamada da função calcula

    imprime_vet(V_result, NumObjs);//chamada da função imprime para imprimir o vetor resposta.

    liberaV(VetorPesos);
    liberaV(V_result);

    return 0;
    }
