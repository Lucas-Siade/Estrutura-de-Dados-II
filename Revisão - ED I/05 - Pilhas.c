#include <stdio.h>
#include <stdlib.h>

int tamanho = 1;
int *pilha;
int topo = -1;

//Função para verificar se a Pilha está vazia
int pilhaVazia(){
    if(topo == -1){
        return 1;
    } else {
        return 0;
    }
}

//Função para adicionar um elemento
void push(int elemento) {
    if (topo < tamanho - 1) {
        pilha[++topo] = elemento;
    } else {
        tamanho += 1;
        pilha = realloc(pilha, tamanho * sizeof(int));
        push(elemento);
    }
}
//Função para remover e retornar o elemento que está no topo da Pilha
int pop() {
    if(pilhaVazia()){
        printf("Pilha vazia!\n");
        return -1;  
    } else {
        return pilha[topo--];
    }
}

//Função para retornar o elemento que está no topo da Pilha
int top() {
    if(pilhaVazia()){
        printf("Pilha vazia!\n");
        return -1;  
    } else {
        return pilha[topo];
    }
}

//Função para imprimir os valores da Pilha
void imprimir() {
    printf("Conteúdo da pilha:\n");
    for (int i = topo; i >= 0; i--) {
        printf("%d ", pilha[i]);
    }
    printf("\n");
}

int main() {
    pilha = (int *)malloc(tamanho * sizeof(int));  
    
    push(10);
    push(20);
    push(30);
    imprimir();
    
    printf("Elemento no topo: %d\n", top());
    printf("Elemento removido: %d\n", pop());
    
    imprimir();
    return 0;
}
