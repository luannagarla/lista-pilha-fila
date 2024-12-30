// LISTA LIGADA PARA DUPLAMENTE LIGADA

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct aux
{
    REGISTRO reg;
    struct aux *ant, *prox; // Atendendo ao critério "Apontar para seu anterior e também para seu sucessor"
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct
{
    PONT inicio;
} LISTA;

void inicializarLista(LISTA *l)
{
    l->inicio = NULL; // Atendendo ao critério "Se o elemento a ser inserido for o primeiro da lista, o campo ant dele deverá ser NULL"
}

// Função para atender ao críterio "Esta ser ́a uma inserção sem repetição, ou seja, se um elemento com a mesma chave já existir, retornar false"
bool existeChave(LISTA *l, TIPOCHAVE ch)
{
    // percorre a lista procurando duplicidades de ch
    PONT atual = l->inicio;
    while (atual != NULL)
    {
        if (atual->reg.chave == ch)
            return true;
        atual = atual->prox;
    }
    return false;
}

bool inserirInicio(LISTA *l, TIPOCHAVE ch)
{
    if (existeChave(l, ch))
        return false;

    PONT novo = (PONT)malloc(sizeof(ELEMENTO));

    novo->reg.chave = ch;
    novo->prox = l->inicio;
    novo->ant = NULL;

    if (l->inicio != NULL)
    {
        l->inicio->ant = novo; // Atribui novo "ant" se não for o primeiro item
    }

    l->inicio = novo;
    return true;
}

bool excluirElemento(LISTA *l, TIPOCHAVE ch)
{
    PONT atual = l->inicio;

    // While para achar elem usando o ch
    while (atual != NULL && atual->reg.chave != ch)
    {
        atual = atual->prox;
    }
    if (atual == NULL)
        return false; // caso não encontre

    // ajusta o ant e o prox para exluir o elem
    if (atual->ant != NULL)
    {
        atual->ant->prox = atual->prox;
    }
    else
    {
        l->inicio = atual->prox;
    }

    if (atual->prox != NULL)
    {
        atual->prox->ant = atual->ant;
    }

    return true;
}

// percorre exibindo a lista
void exibirLista(LISTA *l)
{
    PONT atual = l->inicio;
    printf("---------Lista---------\n");
    while (atual != NULL)
    {
        printf("%d ", atual->reg.chave);
        atual = atual->prox;
    }
    printf("\n");
}

int main()
{
    LISTA lista;
    inicializarLista(&lista);

    //teste inserir
    int v1 = 10;
    if (!inserirInicio(&lista, v1))
        printf("\nChave duplicada: %d !", v1);

    //teste duplicada
    int v2 = 10;
    if (!inserirInicio(&lista, v2))
        printf("\nChave duplicada: %d !", v2);

    int v3 = 20;
    if (!inserirInicio(&lista, v3))
        printf("\nChave duplicada: %d !", v3);

    printf("\nAntes da exclusão: \n");
    exibirLista(&lista);

    //teste exclusão
    int elem = 20;
    if (!excluirElemento(&lista, elem))
        printf("\nElemento não encontrado para exclusão: %d!\n", elem);

    //teste de elemento não encontrado
    int elem2 = 20;
    if (!excluirElemento(&lista, elem2))
        printf("\nElemento não encontrado para exclusão: %d!\n", elem2);

    printf("\nApós a exclusão: \n");
    exibirLista(&lista);

    return 0;
}