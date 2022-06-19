//estruturas da pilha com seus nós
typedef struct No{
struct No* next;//endereço pro prox No
void* dado; //dado do tipo (void*) generico
}No;

typedef No *P_no; //endereço pro No

typedef struct Pilha{
int topo;//tamanho da pilha na sua base
P_no ini;

}Pilha;

typedef Pilha *P_pilha; //endereço pra pilha

//declaração das funções 
P_pilha criar_pilha();

void push (P_pilha , void* );

void* pop(P_pilha);

int tamanho_pilha(P_pilha);

void destroi_pilha(P_pilha);