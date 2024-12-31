#include <stdbool.h>
#include <limits.h>

typedef struct Node {
    int key;              
    struct Node* next;    
    struct Node* prev;    
} Node;

typedef struct DEQUE {
    Node* head; 
} DEQUE;

bool encontrarMax(DEQUE* d, int* max) {
    
}
