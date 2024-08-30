#include <stdio.h>
#include <stdlib.h>

int main() {
    int **matriz;
    int i, j;
    
    int soma = 0;
    int tamanho;
    
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &tamanho);
    
    matriz = (int **)malloc(tamanho * sizeof(int *));
    
    for (i = 0; i < tamanho; i++){
        matriz[i] = (int *)malloc(tamanho * sizeof(int));
    }
    
    printf("Insira os elementos da matriz:\n");
    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho; j++) {
            scanf("%d", &matriz[i][j]);
            
            if (i == j) {
                soma += matriz[i][j];
            }
        }
    }

    printf("Soma dos elementos da diagonal principal: %d\n", soma);
    return 0;
}
