#include <stdio.h>
#include <string.h>
#include "../include/relatorio.h"

void mediaProducaoMel() {
    limparTela();
    printf("========== MEDIA DE PRODUCAO ==========\n\n");
    
    if (qtdA == 0) {
        printf("Nao ha abelhas cadastradas!\n");
        pausar();
        return;
    }
    
    float soma = 0;
    for (int i = 0; i < qtdA; i++) soma += abelhas[i].producaoMel;
    float media = soma / qtdA;
    
    printf("Media geral de producao de mel: %.2f kg/mes\n", media);
    pausar();
}

void mediaValorSensores() {
    limparTela();
    printf("========== MEDIA DOS SENSORES ==========\n\n");
    
    if (qtdS == 0) {
        printf("Nao ha sensores cadastrados!\n");
        pausar();
        return;
    }
    
    float soma = 0;
    for (int i = 0; i < qtdS; i++) soma += sensores[i].valor;
    float media = soma / qtdS;
    
    printf("Media de valores dos sensores: %.2f\n", media);
    pausar();
}

void quantidadePorRegiao() {
    limparTela();
    printf("========== ABELHAS POR REGIAO ==========\n\n");
    
    if (qtdA == 0) {
        printf("Nao ha abelhas cadastradas!\n");
        pausar();
        return;
    }
    
    for (int i = 0; i < qtdA; i++) {
        int cou = 1;
        int jaContado = 0;
        
        for (int k = 0; k < i; k++) {
            if (strcmp(abelhas[i].regiao, abelhas[k].regiao) == 0) {
                jaContado = 1;
                break;
            }
        }
        
        if (jaContado == 0) {
            for (int j = i + 1; j < qtdA; j++) {
                if (strcmp(abelhas[i].regiao, abelhas[j].regiao) == 0) cou++;
            }
            printf("%s: %d abelha(s)\n", abelhas[i].regiao, cou);
        }
    }
    pausar();
}

void identificador() {
    limparTela();
    printf("========== BEEVISION ==========\n\n");
    
    if (qtdA == 0) {
        printf("Nao ha abelhas cadastradas!\n");
        pausar();
        return;
    }
    
    char cor;
    float tamanho;
    int ferrao;

    printf("Cor da abelha (A = Amarela, P = Preta): ");
    scanf(" %c", &cor);

    printf("Tamanho da abelha (mm): ");
    scanf("%f", &tamanho);

    printf("Possui ferrao? (1 = Sim, 0 = Nao): ");
    scanf("%d", &ferrao);

    if ((cor == 'A' || cor == 'a') && tamanho > 10) {
        printf("Especie identificada: Apis mellifera (Abelha europeia)\n");
    }
    else if ((cor == 'P' || cor == 'p') && tamanho < 8) {
        printf("Especie identificada: Jatai (Tetragonisca angustula)\n");
    }
    else if (ferrao == 1) {
        printf("Especie identificada: Mandaguari (Scaptotrigona postica)\n");
    }
    else {
        printf("Especie desconhecida\n");
    }
    
    printf("\n==========================================\n");
    pausar();
}

void menuRelatorios() {
    int op;
    do {
        limparTela();
        printf("========== RELATORIOS ==========\n");
        printf("1 - Media geral de producao de mel\n");
        printf("2 - Media de valores dos sensores\n");
        printf("3 - Quantidade de abelhas por regiao\n");
        printf("4 - Identificador de especie (BeeVision)\n");
        printf("0 - Voltar ao menu principal\n");
        printf("===============================\n");
        
        op = lerInteiro("Opcao: ", 0, 4);
        
        switch (op) {
            case 1: mediaProducaoMel(); break;
            case 2: mediaValorSensores(); break;
            case 3: quantidadePorRegiao(); break;
            case 4: identificador(); break;
        }
    } while (op != 0);
}