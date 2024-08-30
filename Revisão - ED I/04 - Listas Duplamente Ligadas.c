#include <stdio.h>
#include <stdlib.h>

//Estrutura do Nó
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

//Função para inserir elementos
void insertFront() {
    int Auxiliar;
    
    printf("Digite o valor a ser inserido: ");
    scanf("%d", &Auxiliar);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = Auxiliar;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

//Função para remover elementos
void deleteNode(Node* node) {
    if (node == head)
        head = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    if (node->prev != NULL)
        node->prev->next = node->next;
    free(node);
}

//Função para imprimir a lista
void printList() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Função para procurar algum valor. *não mexer*
void searchNode(int value){
    Node* temp = head;
    int encontrou = 0;

    while(temp != NULL){
        if(value == temp -> data){
            printf("Valor encontrado. Vizinhos:\n");
            
            if(temp -> prev != NULL){
                printf("%d ", temp -> prev -> data);
            }
            
            if(temp -> next != NULL){
                printf("%d ", temp -> next -> data);
            }
            
            encontrou = 1;
            break;
        }
        
        temp = temp -> next;
    }
    
    if(encontrou == 0){
        printf("Valor não encontrado.\n");
    }
}

int main() {
    insertFront();
    insertFront();
    printList();
    searchNode(10);
    return 0;
}
