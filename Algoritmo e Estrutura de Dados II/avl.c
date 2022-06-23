#include <stdio.h>
#include <stdlib.h>

typedef struct sno{
    int chave;
    int altura;
    struct sno * esq;
    struct sno * dir;
}no;

int altura(no* arvore){
    if (arvore == NULL) return -1;
    return arvore->altura;
}

int max (int a, int b){
if (a > b) return a;
return b;
}

int fator_balanceamento(no * arvore){
    return altura(arvore->esq) - altura(arvore->dir);
}

no* rotaciona_direita(no* arvore){
    no* temp = arvore->esq;
    arvore->esq = temp->dir;
    temp->dir = arvore;
    arvore->altura = max(altura(arvore->esq) , altura(arvore->dir)) +1;
    temp->altura = max(altura(temp->esq) , altura(temp->dir)) +1;
return temp;
}

no*  rotaciona_esquerda(no* arvore){
    no* temp = arvore->dir;
    arvore->dir = temp->esq;
    temp->esq = arvore;
    arvore->altura = max(altura(arvore->esq) , altura(arvore->dir)) +1;
    temp->altura = max(altura(temp->esq) , altura(temp->dir)) +1;
return temp;
}

no* rotaciona_esquerda_direita(no * arvore){
    arvore->esq = rotaciona_esquerda(arvore->esq);
    return rotaciona_direita(arvore);
}

no* rotaciona_direita_esquerda(no * arvore){
    arvore->dir = rotaciona_direita(arvore->dir);
    return rotaciona_direita(arvore);
}

no * criar_no(int ch){
    no * novo = (no*) malloc (sizeof(no));
    novo->chave = ch;
    novo->esq = NULL;    
    novo->dir = NULL;
    novo->altura = 0;
return novo;
}

no * insere(no * arvore, int ch){
    if(arvore == NULL) return criar_no(ch);
    if(ch > arvore->chave){
        arvore->dir = insere(arvore->dir, ch);
        if(fator_balanceamento(arvore) == -2){
            if(ch > arvore->dir->chave) arvore = rotaciona_esquerda(arvore);
            else arvore = rotaciona_direita_esquerda(arvore);
        }
    }
    else if (ch < arvore->chave){
        arvore->esq = insere(arvore->esq, ch);
        if(fator_balanceamento(arvore) == 2){
            if(ch < arvore->esq->chave) arvore = rotaciona_direita(arvore);
            else arvore = rotaciona_esquerda_direita(arvore);
        }
    }
    arvore->altura = max(altura(arvore->esq) , altura(arvore->dir)) +1;
return arvore;
}

void imprime(no* arvore){
    if(arvore == NULL) return;
    printf("(");
    imprime(arvore->esq);
    printf("; %d [%d];" , arvore->chave , arvore->altura);
    imprime(arvore->dir);
    printf(")");
}

int main(){

    no * ARVORE = NULL;

    ARVORE = insere(ARVORE, 10);
    ARVORE = insere(ARVORE, 7);
    ARVORE = insere(ARVORE, 8);
    ARVORE = insere(ARVORE, 20);
    ARVORE = insere(ARVORE, 90);
    ARVORE = insere(ARVORE, 2);
    ARVORE = insere(ARVORE, 3);
    ARVORE = insere(ARVORE, 55);
    ARVORE = insere(ARVORE, 6);
    imprime(ARVORE);
    printf("\n");

   //libera arvore
return 0;
}
