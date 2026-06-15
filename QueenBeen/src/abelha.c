#include <stdio.h>
#include <string.h>
#include "../include/abelha.h"

Abelha abelhas[MAX_ABELHAS];
int qtdA = 0;

void cadastrarAbelha() {
    limparTela();
    printf("========== CADASTRAR ABELHA ==========\n\n");
    
    if (qtdA >= MAX_ABELHAS) {
        printf("Limite de abelhas atingido!\n");
        pausar();
        return;
    }
    
    Abelha nova;
    nova.id = qtdA;
    lerString("Nome popular: ", nova.nomePopular, 50);
    lerString("Nome cientifico: ", nova.nomeCientifico, 50);
    lerString("Regiao de origem: ", nova.regiao, 50);
    nova.producaoMel = lerFloat("Producao de mel (kg/mes): ", 0);
    
    
    abelhas[qtdA++] = nova; //nova também é uma variável da estrutura Abelha
    printf("\nAbelha cadastrada com sucesso!\n");
    pausar();
}

void listarAbelhas() {
    limparTela();
    printf("========== LISTAR ABELHAS ==========\n\n");

    if (qtdA == 0) {
        printf("Nao ha abelhas cadastradas!\n");
        pausar();
        return;
    }
    
    for (int i = 0; i < qtdA; i++) {
        printf("-------- Abelha %d --------\n", i + 1);
        printf("ID: %d\n", abelhas[i].id);
        printf("Nome popular: %s\n", abelhas[i].nomePopular);
        printf("Nome cientifico: %s\n", abelhas[i].nomeCientifico);
        printf("Regiao: %s\n", abelhas[i].regiao);
        printf("Producao de mel: %.6f kg/mes\n", abelhas[i].producaoMel);
        printf("\n");
    }
    pausar();
}

void alterarAbelha() {
    limparTela();
    printf("========== ALTERAR DADOS DA ABELHA ==========\n\n");
    
    if (qtdA == 0) {
        printf("Nao ha abelhas cadastradas!\n");
        pausar();
        return;
    }
    
    printf("\n");
    int id = lerInteiro("Digite o ID da abelha que deseja alterar: ", 0, qtdA - 1);

    int encontrou = 0;
    for (int i = 0; i < qtdA; i++) {
        if (abelhas[i].id == id) {
            encontrou = 1;
            limparTela();
            
            printf(" Dados atuais: \n");
            printf("  Nome popular      : %s\n", abelhas[i].nomePopular);
            printf("  Nome cientifico   : %s\n", abelhas[i].nomeCientifico);
            printf("  Regiao            : %s\n", abelhas[i].regiao);
            printf("  Producao de mel   : %.6f kg/mes\n", abelhas[i].producaoMel);
            printf("==============================\n");

            printf("Digite os novos dados: \n");
            lerString("  Novo nome popular     : ", abelhas[i].nomePopular, 50);
            lerString("  Novo nome cientifico  : ", abelhas[i].nomeCientifico, 50);
            lerString("  Nova regiao           : ", abelhas[i].regiao, 50);
            abelhas[i].producaoMel = lerFloat("  Nova producao de mel  : ", 0);
            limparTela();
            printf("Abelha alterada com sucesso!\n");
            break;
        }
    }

    if (encontrou == 0) {
        printf("não encontrada!");
    }
    pausar();
}

void buscarAbelha() {
    limparTela();
    printf("========== BUSCAR ABELHA ==========\n\n");
    
    if (qtdA == 0) {
        printf("Nao ha abelhas cadatradas!\n");
        pausar();
        return;
    }
    
    char nome[50];
    lerString("Digite o nome popular: ", nome, 50);
    
    int encontrou = 0;
    for (int i = 0; i < qtdA; i++) {
        if (strcmp(abelhas[i].nomePopular, nome) == 0) {
            printf("\nAbelha encontrada!\n");
            printf("ID: %d\n", abelhas[i].id);
            printf("Nome popular: %s\n", abelhas[i].nomePopular);
            printf("Nome cientifico: %s\n", abelhas[i].nomeCientifico);
            printf("Regiao: %s\n", abelhas[i].regiao);
            printf("Producao: %.6f kg/mes\n", abelhas[i].producaoMel);
            encontrou = 1;
        }
    }
    if (encontrou == 0) printf("\nAbelha nao encontrada!\n");
    
    pausar();
}

void removerAbelha() {
    limparTela();
    printf("========== REMOVER ABELHA ==========\n\n");
    
    if (qtdA == 0) {
        printf("Nao ha abelhas cadastradas!\n");
        pausar();
        return;
    }
    
    int id = lerInteiro("Digite o ID da abelha: ", 0, qtdA - 1);
    
    for (int i = 0; i < qtdA; i++) {
        if (abelhas[i].id == id) {
            for (int j = i; j < qtdA - 1; j++) {
                abelhas[j] = abelhas[j + 1];
                abelhas[j].id = j;
            }
            qtdA--;
            printf("\nAbelha removida com sucesso!\n");
            pausar();
            return;
        }
    }

    printf("\nAbelha nao encontrada!\n");
    pausar();
}

void menuAbelhas() {
    int op;
    do {
        limparTela();
        printf("========== GERENCIAR ABELHAS ==========\n");
        printf("1 - Cadastrar abelha\n");
        printf("2 - Listar abelhas\n");
        printf("3 - Buscar abelha\n");
        printf("4 - Alterar dados\n");
        printf("5 - Remover abelha\n");
        printf("0 - Voltar ao menu principal\n");
        printf("======================================\n");
        
        op = lerInteiro("Opcao: ", 0, 5);
        
        switch (op) {
            case 1: cadastrarAbelha(); break;
            case 2: listarAbelhas(); break;
            case 3: buscarAbelha(); break;
            case 4: alterarAbelha(); break;
            case 5: removerAbelha(); break;
        }
    } while (op != 0);
}