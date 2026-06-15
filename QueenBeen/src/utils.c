#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/utils.h"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    printf("\nPressione ENTER para continuar...");
    limparBuffer();
    getchar();
}

int lerInteiro(const char* msg, int min, int max) {
    int valor, res;
    do {
        printf("%s", msg);
        res = scanf("%d", &valor);
        limparBuffer();
        if (res != 1 || valor < min || valor > max) {
            printf("Entrada invalida! Digite um numero entre %d e %d.\n", min, max);
        } else {
            return valor;
        }
    } while (1);
}

float lerFloat(const char* msg, float min) {
    float valor;
    int res;
    do {
        printf("%s", msg); //mensagem recebido
        res = scanf("%f", &valor);
        limparBuffer();
        if (res != 1 || valor < min) {
            printf("Entrada invalida! Digite um numero >= %.0f.\n", min);
        } else {
            return valor;
        }
    } while (1);
}

void lerString(const char* msg, char* destino, int tamanho) {
    printf("%s", msg);
    fgets(destino, tamanho, stdin);
    
    // Remove o caractere de nova linha (\n) do final
    int len = strlen(destino); //calcular o tamanho da string
    if (len > 0 && destino[len-1] == '\n') {
        destino[len-1] = '\0'; //substitui pot final de string
    }
}