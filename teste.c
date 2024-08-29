#include <stdio.h>
#include <string.h>

#define MAX_TAMANHO 101 // Tamanho máximo da linha + 1 para o '\0'
#define MAX_PILHA 100   // Tamanho máximo da pilha (ajuste conforme necessário)

char pilha[MAX_PILHA];
int topoPilha = -1;

// Função para verificar se a pilha está vazia
int estaVazia() {
    return topoPilha == -1;
}

// Função para empilhar um caractere na pilha
void empilhar(char caractere) {
    if (topoPilha == MAX_PILHA - 1) {
        printf("Erro: Pilha cheia.\n");
        exit(1); 
    }
    pilha[++topoPilha] = caractere;
}

// Função para desempilhar um caractere da pilha
char desempilhar() {
    if (estaVazia()) {
        printf("Erro: Pilha vazia.\n");
        exit(1); 
    }
    return pilha[topoPilha--];
}

// Função para obter o caractere do topo da pilha sem removê-lo
char topo() {
    if (estaVazia()) {
        printf("Erro: Pilha vazia.\n");
        exit(1);
    }
    return pilha[topoPilha];
}

int main() {
    char linha[MAX_TAMANHO];
    int numeroLinha = 1;

    while (fgets(linha, MAX_TAMANHO, stdin) != NULL) {
        if (strcmp(linha, "***END***\n") == 0) {
            break; 
        }

        for (int i = 0; linha[i] != '\0'; i++) {
            if (linha[i] == '(' || linha[i] == '{') {
                empilhar(linha[i]);
            } else if (linha[i] == ')' || linha[i] == '}') {
                if (estaVazia()) {
                    printf("%d\n", numeroLinha); 
                    return 0;
                } else {
                    char caractereAbertura = topo();
                    desempilhar();
                    if ((linha[i] == ')' && caractereAbertura != '(') || 
                        (linha[i] == '}' && caractereAbertura != '{')) {
                        printf("%d\n", numeroLinha);
                        return 0;
                    }
                }
            }
        }
        numeroLinha++;
    }

    if (estaVazia()) {
        printf("OK\n");
    } else {
        printf("%d\n", numeroLinha - 1); 
    }

    return 0;
}
