#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Node {
    int key;             
    struct Node* next;    
    struct Node* prev;    
} Node;

typedef struct DEQUE {
    Node* head;  // Nó-cabeça do DEQUE
} DEQUE;


bool encontrarMax(DEQUE* d, int* max) {
    if (!d || !d->head || !d->head->next) { // Retornar false caso o DEQUE nao contenha nenhum elemento valido (apenas o nó-cabeça)
        return false;
    }

   
}

int main() {
    DEQUE deque;
    Node head;
    head.next = &head;
    head.prev = &head;
    deque.head = &head;

    Node* node1 = (Node*)malloc(sizeof(Node));
    Node* node2 = (Node*)malloc(sizeof(Node));
    Node* node3 = (Node*)malloc(sizeof(Node));

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

   

    free(node1);
    free(node2);
    free(node3);

    return 0;
}