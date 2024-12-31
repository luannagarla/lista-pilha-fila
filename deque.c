#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Node
{
    int key;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct DEQUE
{
    Node *head;
} DEQUE;

bool encontrarMax(DEQUE *d, int *max)
{
    if (!d || !d->head || d->head->next == d->head)
    {
        // Atende ao críterio:Retornar false caso o DEQUE n ̃ao contenha nenhum elemento valido (apenas o no-cabeca).
        return false;
    }

    Node *current = d->head->next;
    int maior = -9999999999;

    // percorre o deque com a condicional atual != nó cabeça inicial
    while (current != d->head)
    {
        if (current->key > maior) // compara que o considerado maior anteriormente
        {
            maior = current->key;
        }
        current = current->next;
    }

    *max = maior; // Critério "Copiar o valor da maior chave dos elementos validos do DEQUE para a memoria apontada por max e retornar true."
    return true;
}

int main()
{
    // inicializção
    DEQUE deque;
    Node head;
    head.next = &head;
    head.prev = &head;
    deque.head = &head;

    Node *node1 = (Node *)malloc(sizeof(Node));
    Node *node2 = (Node *)malloc(sizeof(Node));
    Node *node3 = (Node *)malloc(sizeof(Node));

    node1->key = 10;
    node2->key = 20;
    node3->key = 15;

    node1->next = &head;
    node1->prev = head.prev;
    head.prev->next = node1;
    head.prev = node1;

    node2->next = &head;
    node2->prev = head.prev;
    head.prev->next = node2;
    head.prev = node2;

    node3->next = &head;
    node3->prev = head.prev;
    head.prev->next = node3;
    head.prev = node3;

    // chamada função da atividade
    int max;
    if (encontrarMax(&deque, &max))
    {
        printf("\nMaior chave: %d\n", max);
    }

    return 0;
}