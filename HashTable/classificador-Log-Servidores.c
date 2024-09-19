#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_HASH 10

typedef struct{
    int id;
    int timestamp;
    int IP;
    int statusRequisicao;
    char tipoRequisicao[10];
} Log;

// Estrutura da Tabela Hash
typedef struct {
    Log *tabela[TAMANHO_HASH];  // Array de ponteiros para armazenar transações
} TabelaHash;

// Função Hash: Retorna o índice baseado no ID da transação
int funcao_hash(int id) {
    return id % TAMANHO_HASH;  // Usa módulo para determinar a posição na tabela
}

// Função para inserir uma transação na tabela hash
void inserir(TabelaHash *tabela, Log *logA) {
    int indice = funcao_hash(logA -> id); 
    tabela->tabela[indice] = logA;  // Insere a transação na tabela
}

// Função para buscar uma transação na tabela hash pelo ID
Log *buscar(TabelaHash *tabela, int id) {
    int indice = funcao_hash(id);  // Calcula o índice para busca
    return tabela->tabela[indice];  // Retorna a transação encontrada
}

void remover(TabelaHash *tabela, Log *logA){
    int indice = funcao_hash(logA -> id);
    
    tabela -> tabela[indice] = NULL;
}

// Função principal para demonstrar o uso da tabela hash com transações financeiras
int main() {
    // Inicializa a tabela hash
    TabelaHash tabela = {NULL};

    // Criação de algumas transações
    
    Log log1 = {0, 1400, 172165163, 404, "GET"};
    Log log5 = {1, 1403, 172165254, 404, "GET"};
    Log log7 = {2, 1410, 192168561, 404, "GET"};
    Log log9 = {3, 1700, 172165257, 507, "POST"};

    // Insere as transações na tabela hash
    inserir(&tabela, &log1);
    inserir(&tabela, &log5);
    inserir(&tabela, &log7);
    inserir(&tabela, &log9);

    // Busca por uma transação específica
    Log *buscarLog = buscar(&tabela, 2);
    if (buscarLog != NULL) {
        printf("Log encontrado: ID: %d, timestamp: %d, IP: %d, Status da Requisição: %d, Tipo da Requisição: %s\n",
               buscarLog -> id, buscarLog -> timestamp, buscarLog -> IP, buscarLog -> statusRequisicao, buscarLog -> tipoRequisicao);
    } else {
        printf("Log não encontrado.\n");
    }
    
    remover(&tabela, &log7);
    
    Log *buscarLogA = buscar(&tabela, 2);
    if (buscarLogA != NULL) {
        printf("Log encontrado: ID: %d, timestamp: %d, IP: %d, Status da Requisição: %d, Tipo da Requisição: %s\n",
               buscarLog -> id, buscarLogA -> timestamp, buscarLogA -> IP, buscarLogA -> statusRequisicao, buscarLogA -> tipoRequisicao);
    } else {
        printf("Log não encontrado.\n");
    }
    
    return 0;
}
