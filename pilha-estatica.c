// pilha estatica com print inverso 

#include <stdio.h>
#include <stdbool.h>

#define MAX 5
typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
    int topo;
    REGISTRO A[MAX];
} PILHA;

void inicializarPilha(PILHA *p)
{
    p->topo = -1;
}

bool inserirElementoPilha(PILHA *p, REGISTRO reg)
{
    if (p->topo < MAX - 1)
    {
        p->topo++;           // incrementa topo
        p->A[p->topo] = reg; // add
        return true;
    }
    return false; // pilha cheia
}

// Código retirado do class e adaptado
void inserir(PILHA *p, TIPOCHAVE ch)
{

    REGISTRO reg;
    reg.chave = ch;
    if (!inserirElementoPilha(p, reg))
        printf("Nao foi possivel inserir elemento %i.\n", ch);
}

// print comum
void exibirPilha(PILHA *p)
{
    printf("\nPilha do topo ate a base: \n");
    int i;

    for (i = p->topo; i >= 0; i--) // começa do topo e vai até 0
    { 
        printf("%i ", p->A[i].chave);
    }
    printf("\"\n");
}

void exibirPilhaInvertida(PILHA *p)
{
    printf("\nPilha da base ate o topo: \n");
    int i;

    for (i = 0; i <= p->topo; i++) // começa em 0 e vai até o topo
    { 
        printf("%i ", p->A[i].chave);
    }
    printf("\n");
}

int main()
{
    PILHA p;
    inicializarPilha(&p);

    inserir(&p, 10);
    inserir(&p, 20);
    inserir(&p, 30);
    inserir(&p, 40);
    inserir(&p, 50);
    inserir(&p, 60); // teste de pilha cheia                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   

    exibirPilha(&p);
    exibirPilhaInvertida(&p);

    return 0;
}