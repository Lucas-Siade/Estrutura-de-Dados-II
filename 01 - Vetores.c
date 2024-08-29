#include <stdio.h>

int main() {
    int size;

    //Inserir tamanho do Vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &size);

    int vetor[size];
    int i, temp;

    //Inserir valores do Vetor
    for(i = 0; i < size; i++){
        vetor[i] = i;
    }

    //Inversão do Vetor
    for (i = 0; i < (size/2); i++) {
        temp = vetor[i];
        vetor[i] = vetor[size - i - 1];
        vetor[size - i - 1] = temp;
    }

    printf("Vetor invertido:\n");
    
    //Impressão do Vetor
    for (i = 0; i < size; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
