#include <stdio.h>
#include <stdlib.h>

//Estrutura do Nó
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//Estrutura da Fila
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

//Função para criar uma Fila
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Falha na alocação de memória para a fila.\n");
        return NULL;
    }
    q->front = q->rear = NULL;
    return q;
}

//Função para adicionar um novo Nó
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Falha na alocação de memória para o novo nó.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) { 
        q->front = q->rear = newNode;
    } else { 
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

//Função para remover um Nó
int dequeue(Queue* q) {
    if (q->front == NULL) { 
        printf("Fila está vazia.\n");
        return -1;
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

//Função para conferir se a Fila está vazia
int isEmpty(Queue* q) {
    return q->front == NULL;
}

//Função para imprimir os elementos da Fila
void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("A fila está vazia.\n");
        return;
    }
    Node* temp = q->front;
    printf("Elementos da fila: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Função para o contar o número de elementos da Fila
void countQueue(Queue* q){
    Node* temp = q -> front;
    int Contador = 0;
    
    while(temp != NULL){
        Contador += 1;
        temp = temp -> next;
    }
    
    printf("Número de elementos: %d\n", Contador);
}

//Função para limpar todos os elementos da Fila
void clear(Queue* q){
    Node* temp = q -> front;

    while(temp != NULL){
        if(isEmpty(q)){
            break;
        } else {
            dequeue(q);
        }
    }
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printQueue(q);

    printf("Desenfileirado: %d\n", dequeue(q));
    printQueue(q);
    printf("Desenfileirado: %d\n", dequeue(q));
    printQueue(q);
    printf("Desenfileirado: %d\n", dequeue(q));
    printQueue(q);
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    
    printQueue(q);
    
    countQueue(q);
    clear(q);
    
    printQueue(q);

    return 0;
}
