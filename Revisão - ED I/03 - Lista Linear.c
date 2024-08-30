#include <stdio.h>
#define MAX_SIZE 10

int lista[MAX_SIZE];
int tamanho = 0;

void inserir(int elemento) {
    if (tamanho < MAX_SIZE) {
        lista[tamanho++] = elemento;
    } else {
        printf("Lista cheia!\n");
    }
}

void remover(int index) {
    if (index < 0 || index >= tamanho) {
        printf("Índice inválido!\n");
    } else {
        for (int i = index; i < tamanho - 1; i++) {
            lista[i] = lista[i + 1];
        }
        tamanho--;
    }
}

void imprimir() {
    printf("Elementos da lista:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

void buscar(int elemento){
    for(int i = 0; i < tamanho; i++){
        if(elemento == lista[i]){
            printf("Elemento encontrado na posição %d\n", i + 1);
            break;
        }
    }
}

void inverter(){
    for (int i = 0; i < (tamanho/2); i++) {
        int temp;
        
        temp = lista[i];
        lista[i] = lista[tamanho - i - 1];
        lista[tamanho - i - 1] = temp;
    }
}

int encontrarMaior(){
    int maior;
    
    for(int i = 0; i < tamanho; i++){
        if(maior < lista[i]){
            maior = lista[i];
        }
    }
    
    printf("O maior número da lista é %d\n", maior);

}

void encontrarMenor(){
    int menor;
    
    for(int i = 0; i < tamanho; i++){
        if(menor > lista[i]){
            menor = lista[i];
        }
    }
    
    printf("O menor número da lista é %d\n", menor);
}

void ordenarLista(){
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho - 1; j++){
            if(lista[j] > lista[j + 1]){
                int temp;
                
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

int main() {
    inserir(100);
    inserir(10);
    inserir(20);
    inserir(30);
    inserir(25);
    inserir(15);
    imprimir();
    remover(1);
    imprimir();
    buscar(10);
    inverter();
    imprimir();
    encontrarMaior();
    encontrarMenor();
    ordenarLista();
    imprimir();
    
    return 0;
}
