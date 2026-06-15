#include <stdio.h>
#include <string.h>
#include "../include/sensor.h"

Sensor sensores[MAX_SENSORES];
int qtdS = 0;

void cadastrarSensor() {
    limparTela();
    printf("========== CADASTRAR SENSOR ==========\n\n");
    
    if (qtdA == 0) {
        printf("Nao ha abelhas cadastradas! Cadastre uma abelha primeiro.\n");
        pausar();
        return;
    }
    

    if (qtdS >= MAX_SENSORES) {
        printf("Limite de sensores atingido!\n");
        pausar();
        return;
    }
    
    Sensor novo;
    novo.id = qtdS;
    lerString("Tipo do sensor (temperatura/umidade/luminosidade): ", novo.tipo, 50);
    novo.valor = lerFloat("Valor do sensor: ", 0);
    novo.abelhaId = lerInteiro("ID da abelha associada: ", 0, qtdA - 1);
    
    sensores[qtdS++] = novo; //nova também é uma variável da estrutura Abelha
    printf("\nSensor cadastrado com sucesso!\n");
    pausar();
}

void listarSensores() {
    limparTela();
    printf("========== LISTAR SENSORES ==========\n\n");
    
    if (qtdS == 0) {
        printf("Nao ha sensores cadastrados!\n");
        pausar();
        return;
    }
    
    for (int i = 0; i < qtdS; i++) {
        printf("------ Sensor %d ------\n", i + 1);
        printf("ID: %d\n", sensores[i].id);
        printf("Tipo: %s\n", sensores[i].tipo);
        printf("Valor: %.2f\n", sensores[i].valor);
        printf("Abelha ID: %d\n", sensores[i].abelhaId);
        printf("\n");
    }
    pausar();
}

void alterarSensor() {
    limparTela();
    printf("========== ALTERAR SENSOR ==========\n\n");
    
    if (qtdS == 0) {
        printf("Nao ha sensores cadastrados!\n");
        pausar();
        return;
    }

    for (int i = 0; i < qtdS; i++) {
        printf("ID: %d - %s\n", sensores[i].id, sensores[i].tipo);
    }
    
    int id = lerInteiro("\nID do sensor: ", 0, qtdS - 1);
    
    for (int i = 0; i < qtdS; i++) {
        if (sensores[i].id == id) {
            lerString("Novo tipo: ", sensores[i].tipo, 50);
            sensores[i].valor = lerFloat("Novo valor: ", 0);
            sensores[i].abelhaId = lerInteiro("Novo ID da abelha: ", 0, qtdA - 1);
            printf("\nSensor alterado!\n");
            break;
        }
    }
    
    pausar();
}

void buscarSensor() {
    limparTela();
    printf("========== BUSCAR SENSOR ==========\n\n");
    
    if (qtdS == 0) {
        printf("Nao ha sensores cadastrados!\n");
        pausar();
        return;
    }
    
    int idAbelha = lerInteiro("Digite o ID da abelha: ", 0, qtdA - 1);
    
    int encontrou = 0;
    for (int i = 0; i < qtdS; i++) {
        if (sensores[i].abelhaId == idAbelha) {
            printf("\nSensor encontrado:\n");
            printf("ID: %d\n", sensores[i].id);
            printf("Tipo: %s\n", sensores[i].tipo);
            printf("Valor: %.2f\n", sensores[i].valor);
            encontrou = 1;
        }
    }
    if (encontrou == 0) printf("\nNenhum sensor encontrado para esta abelha!\n");
    
    pausar();
}

void removerSensor() {
    limparTela();
    printf("========== REMOVER SENSOR ==========\n\n");
    
    if (qtdS == 0) {
        printf("Nao ha sensores cadastrados!\n");
        pausar();
        return;
    }
    
    int id = lerInteiro("Digite o ID do sensor: ", 0, qtdS - 1);
    
    for (int i = 0; i < qtdS; i++) {
        if (sensores[i].id == id) {
            for (int j = i; j < qtdS - 1; j++) {
                sensores[j] = sensores[j + 1];
                sensores[j].id = j;
            }
            qtdS--;
            printf("\nSensor removido com sucesso!\n");
            pausar();
            return;
        }
    }
    printf("\nSensor nao encontrado!\n");
    pausar();
}

void menuSensores() {
    int op;
    do {
        limparTela();
        printf("========== GERENCIAR SENSORES ==========\n");
        printf("1 - Cadastrar sensor\n");
        printf("2 - Listar sensores\n");
        printf("3 - Buscar sensor por abelha\n");
        printf("4 - alterar sensor\n");
        printf("5 - Remover sensor\n");
        printf("0 - Voltar ao menu principal\n");
        printf("=======================================\n");
        
        op = lerInteiro("Opcao: ", 0, 5);
        
        switch (op) {
            case 1: cadastrarSensor(); break;
            case 2: listarSensores(); break;
            case 3: buscarSensor(); break;
            case 4: alterarSensor(); break;
            case 5: removerSensor(); break;
        }
    } while (op != 0);
}