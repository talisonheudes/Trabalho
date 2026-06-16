#include <stdio.h>
#include <string.h>
#include "../include/sensor.h"

Sensor sensores[MAX_SENSORES];
int qtdS = 0;

void cadastrarSensor() {
    limparTela();
    printf("\033[33m========== CADASTRAR SENSOR ==========\033[0m\n\n");
    
    if (qtdA == 0) {
        printf("Nao ha abelhas cadastradas! Cadastre uma abelha primeiro.\n");
        pausar();
        return;
    }
    
    if (qtdS >= MAX_SENSORES) {
        printf("\033[31mLimite de sensores atingido!\033[0m\n");
        pausar();
        return;
    }
    
    Sensor novo;
    novo.id = qtdS;
    
    // Opções de tipo de sensor
    int opcaoTipo;
    printf("Tipos de sensor:\n");
    printf("1 - Temperatura\n");
    printf("2 - Umidade\n");
    printf("3 - Luminosidade\n");
    printf("Escolha o tipo do sensor: ");
    scanf("%d", &opcaoTipo);
    getchar(); // Limpa o buffer
    
    switch(opcaoTipo) {
        case 1:
            strcpy(novo.tipo, "temperatura");
            break;
        case 2:
            strcpy(novo.tipo, "umidade");
            break;
        case 3:
            strcpy(novo.tipo, "luminosidade");
            break;
        default:
            printf("\033[31mOpcao invalida! Usando temperatura como padrao.\033[0m\n");
            strcpy(novo.tipo, "temperatura");
            break;
    }
    
    novo.valor = lerFloat("Valor do sensor: ", 0);
    novo.abelhaId = lerInteiro("ID da abelha associada: ", 0, qtdA - 1);
    
    sensores[qtdS++] = novo;
    printf("\n\033[32mSensor cadastrado com sucesso!\033[0m\n");
    pausar();
}

void listarSensores() {
    limparTela();
    printf("\033[33m========== LISTAR SENSORES ==========\033[0m\n\n");
    
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
    printf("\033[33m========== ALTERAR SENSOR ==========\033[0m\n\n");
    
    if (qtdS == 0) {
        printf("\033[31mNao ha sensores cadastrados!\033[0m\n");
        pausar();
        return;
    }

    // Lista sensores
    for (int i = 0; i < qtdS; i++) {
        printf("ID: %d - %s\n", sensores[i].id, sensores[i].tipo);
    }
    
    int id = lerInteiro("\nID do sensor para alterar: ", 0, qtdS - 1);
    
    for (int i = 0; i < qtdS; i++) {
        if (sensores[i].id == id) {
            // Menu para escolher o novo tipo
            int opcaoTipo;
            printf("\nNovo tipo do sensor:\n");
            printf("1 - Temperatura\n");
            printf("2 - Umidade\n");
            printf("3 - Luminosidade\n");
            printf("Escolha: ");
            scanf("%d", &opcaoTipo);
            getchar();
            
            switch(opcaoTipo) {
                case 1:
                    strcpy(sensores[i].tipo, "temperatura");
                    break;
                case 2:
                    strcpy(sensores[i].tipo, "umidade");
                    break;
                case 3:
                    strcpy(sensores[i].tipo, "luminosidade");
                    break;
                default:
                    printf("Opcao invalida! Tipo mantido.\n");
                    break;
            }
            
            sensores[i].valor = lerFloat("Novo valor: ", 0);
            sensores[i].abelhaId = lerInteiro("Novo ID da abelha: ", 0, qtdA - 1);
            
            printf("\n\033[32mSensor alterado com sucesso!\033[0m\n");
            break;
        }
    }
    pausar();
}

void buscarSensor() {
    limparTela();
    printf("\033[33m========== BUSCAR SENSOR ==========\033[0m\n\n");
    
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
            printf("ID associado: %d", sensores[i].abelhaId);
            encontrou = 1;
        }
    }
    if (encontrou == 0) printf("\nNenhum sensor encontrado para esta abelha!\n");
    
    pausar();
}

void removerSensor() {
    limparTela();
    printf("\033[33m========== REMOVER SENSOR ==========\033[0m\n\n");
    
    if (qtdS == 0) {
        printf("\033[31mNao ha sensores cadastrados!\033[0m\n");
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
            printf("\n\033[32mSensor removido com sucesso!\033[0m\n");
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
        printf("\033[33m========== GERENCIAR SENSORES ==========\033[0m\n");
        printf("1 - Cadastrar sensor\n");
        printf("2 - Listar sensores\n");
        printf("3 - Buscar sensor por abelha\n");
        printf("4 - alterar sensor\n");
        printf("5 - Remover sensor\n");
        printf("0 - Voltar ao menu principal\n");
        printf("\033[33m=======================================\033[0m\n");
        
        op = lerInteiro("\033[33mOpcao:\033[0m ", 0, 5);
        
        switch (op) {
            case 1: cadastrarSensor(); break;
            case 2: listarSensores(); break;
            case 3: buscarSensor(); break;
            case 4: alterarSensor(); break;
            case 5: removerSensor(); break;
        }
    } while (op != 0);
}