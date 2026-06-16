#include <stdio.h>
#include <string.h>
#include <ctype.h>   // Para a funcao toupper()
#include "../include/relatorio.h"

void mediaProducaoMel() {
    limparTela();
    printf("\033[33m========== MEDIA DE PRODUCAO ==========\033[0m\n\n");
    
    if (qtdA == 0) {
        printf("Nao ha abelhas cadastradas!\n");
        pausar();
        return;
    }
    
    float soma = 0;
    for (int i = 0; i < qtdA; i++) soma += abelhas[i].producaoMel;
    float media = soma / qtdA;
    
    printf("Media geral de producao de mel: %.6f kg/mes\n", media);
    pausar();
}

void mediaValorSensores() {
    limparTela();
    printf("\033[33m========== MEDIA DOS SENSORES ==========\033[0m\n\n");
    
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
    printf("\033[33m========== ABELHAS POR REGIAO ==========\033[33m\n\n");
    
    if (qtdA == 0) {
        printf("\033[31mNao ha abelhas cadastradas!\033[0m\n");
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
    printf("\033[33m========== BEEVISION - IDENTIFICADOR DE ESPECIES ==========\n\n");
    
    if (qtdA == 0) {
        printf("Nao ha abelhas cadastradas no sistema!\n");
        printf("Por favor, cadastre abelhas primeiro.\n");
        pausar();
        return;
    }
    
    char cor;
    float tamanho;
    int ferrao;
    int opcao;
    
    printf("MODO DE IDENTIFICACAO:\n");
    printf("1 - Identificacao rapida (cor, tamanho, ferrao)\n");
    printf("2 - Identificacao detalhada (mais caracteristicas)\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    
    if (opcao == 2) {
        int comportamento, flor_preferida, epoca_ano;
        
        printf("\nCARACTERISTICAS AVANCADAS:\n");
        printf("Comportamento (1 - Agressiva, 2 - Defensiva, 3 - Docil): ");
        scanf("%d", &comportamento);
        
        printf("Prefere flores (1 - Silvestres, 2 - Cultivadas, 3 - Ambas): ");
        scanf("%d", &flor_preferida);
        
        printf("Epoca do ano mais ativa (1 - Primavera, 2 - Verao, 3 - Outono, 4 - Inverno): ");
        scanf("%d", &epoca_ano);
    }
    
    printf("\nINSIRA AS CARACTERISTICAS DA ABELHA\n");
    printf("----------------------------------------\n");
    
    // Validacao da cor
    do {
        printf("Cor da abelha (A = Amarela, P = Preta, M = Marrom, V = Verde): ");
        scanf(" %c", &cor);
        cor = toupper(cor);
        
        if (cor != 'A' && cor != 'P' && cor != 'M' && cor != 'V') {
            printf("\033[31mErro: Cor invalida! Use A, P, M ou V.\033[0m\n");
        }
    } while (cor != 'A' && cor != 'P' && cor != 'M' && cor != 'V');
    
    // Validacao do tamanho (nao pode ser negativo)
    do {
        printf("Tamanho da abelha (mm): ");
        scanf("%f", &tamanho);
        
        if (tamanho < 0) {
            printf("\033[31mErro: O tamanho nao pode ser negativo!\033[0m\n");
        } else if (tamanho < 2 && tamanho > 0) {
            printf("\033[33mAtencao: Tamanho muito pequeno para uma abelha!\033[0m\n");
        }
    } while (tamanho < 0);
    
    // Validacao do ferrao
    do {
        printf("Possui ferrao? (1 = Sim, 0 = Nao): ");
        scanf("%d", &ferrao);
        
        if (ferrao != 0 && ferrao != 1) {
            printf("\033[31mErro: Digite apenas 1 (Sim) ou 0 (Nao)!\033[0m\n");
        }
    } while (ferrao != 0 && ferrao != 1);
    
    printf("\nANALISANDO CARACTERISTICAS...\n");
    printf("----------------------------------------\n\n");
    
    // Sistema de identificacao mais preciso
    int identificado = 0;
    
    // Apis mellifera (Abelha europeia)
    if ((cor == 'A' || cor == 'M') && tamanho >= 10 && tamanho <= 15 && ferrao == 1) {
        printf("\033[32mEspecie identificada: Apis mellifera (Abelha europeia)\033[0m\n");
        printf("Caracteristicas:\n");
        printf("- Cor: Amarela ou Marrom\n");
        printf("- Tamanho: %.1f mm (faixa ideal: 10-15 mm)\n", tamanho);
        printf("- Possui ferrao: Sim\n");
        printf("- Produtora de mel comercial\n");
        printf("- Vive em colonias organizadas\n");
        identificado = 1;
    }
    // Tetragonisca angustula (Jatai)
    else if ((cor == 'P' || cor == 'M') && tamanho < 8 && ferrao == 0) {
        printf("\033[32mEspecie identificada: Jatai (Tetragonisca angustula)\033[0m\n");
        printf("Caracteristicas:\n");
        printf("- Cor: Preta ou Marrom\n");
        printf("- Tamanho: %.1f mm (pequena, < 8 mm)\n", tamanho);
        printf("- Possui ferrao: Nao\n");
        printf("- Abelha sem ferrao, docil\n");
        printf("- Mel de alta qualidade\n");
        identificado = 1;
    }
    // Scaptotrigona postica (Mandaguari)
    else if (ferrao == 1 && tamanho >= 7 && tamanho <= 10 && (cor == 'P' || cor == 'M')) {
        printf("\033[32mEspecie identificada: Mandaguari (Scaptotrigona postica)\033[0m\n");
        printf("Caracteristicas:\n");
        printf("- Cor: Preta ou Marrom\n");
        printf("- Tamanho: %.1f mm (medio)\n", tamanho);
        printf("- Possui ferrao: Sim\n");
        printf("- Abelha defensiva\n");
        printf("- Producao moderada de mel\n");
        identificado = 1;
    }
    // Melipona quadrifasciata (Mandaçaia)
    else if (cor == 'P' && tamanho >= 10 && tamanho <= 12 && ferrao == 0) {
        printf("\033[32mEspecie identificada: Mandacaia (Melipona quadrifasciata)\033[0m\n");
        printf("Caracteristicas:\n");
        printf("- Cor: Preta com faixas amarelas\n");
        printf("- Tamanho: %.1f mm (grande para sem ferrao)\n", tamanho);
        printf("- Possui ferrao: Nao\n");
        printf("- Abelha nativa brasileira\n");
        printf("- Mel muito valorizado\n");
        identificado = 1;
    }
    // Bombus spp. (Mamangava)
    else if ((cor == 'A' || cor == 'M') && tamanho > 15 && tamanho <= 25 && ferrao == 1) {
        printf("\033[32mEspecie identificada: Mamangava (Bombus spp.)\033[0m\n");
        printf("Caracteristicas:\n");
        printf("- Cor: Amarela e preta\n");
        printf("- Tamanho: %.1f mm (grande, > 15 mm)\n", tamanho);
        printf("- Possui ferrao: Sim\n");
        printf("- Abelha robusta e peluda\n");
        printf("- Importante polinizadora\n");
        identificado = 1;
    }
    // Trigona spinipes (Arapua)
    else if (cor == 'P' && tamanho < 6 && ferrao == 0) {
        printf("\033[32mEspecie identificada: Arapua (Trigona spinipes)\033[0m\n");
        printf("Caracteristicas:\n");
        printf("- Cor: Preta\n");
        printf("- Tamanho: %.1f mm (muito pequena)\n", tamanho);
        printf("- Possui ferrao: Nao\n");
        printf("- Abelha agressiva mesmo sem ferrao\n");
        printf("- Construtoras de ninhos de barro\n");
        identificado = 1;
    }
    // Centris (Abelha de bronze)
    else if ((cor == 'M' || cor == 'V') && tamanho >= 12 && tamanho <= 18 && ferrao == 1) {
        printf("\033[32mEspecie identificada: Centris (Abelha de bronze)\033[0m\n");
        printf("Caracteristicas:\n");
        printf("- Cor: Marrom ou Verde metalica\n");
        printf("- Tamanho: %.1f mm\n", tamanho);
        printf("- Possui ferrao: Sim\n");
        printf("- Abelha solitaria\n");
        printf("- Importante polinizadora de flores nativas\n");
        identificado = 1;
    }
    // Xylocopa (Mamangava de chao)
    else if ((cor == 'P' || cor == 'M') && tamanho > 20 && tamanho <= 30 && ferrao == 1) {
        printf("\033[32mEspecie identificada: Mamangava de chao (Xylocopa spp.)\033[0m\n");
        printf("Caracteristicas:\n");
        printf("- Cor: Preta ou Marrom escuro\n");
        printf("- Tamanho: %.1f mm (muito grande)\n", tamanho);
        printf("- Possui ferrao: Sim\n");
        printf("- Abelha grande e robusta\n");
        printf("- Nidifica em madeira\n");
        identificado = 1;
    }
    
    // Se nao identificou com as regras especificas, tenta identificacao generica
    if (!identificado) {
        printf("\033[33mIdentificacao parcial:\033[0m\n");
        
        if (ferrao == 1) {
            printf("- Grupo: Abelhas com ferrao (Apini, Bombini, etc.)\n");
            if (tamanho < 8) {
                printf("- Possivel especie: Abelha anao com ferrao (rara)\n");
            } else if (tamanho >= 8 && tamanho <= 15) {
                printf("- Possivel especie: Apis mellifera ou proxima\n");
            } else if (tamanho > 15) {
                printf("- Possivel especie: Mamangava (Bombus ou Xylocopa)\n");
            }
        } else {
            printf("- Grupo: Abelhas sem ferrao (Meliponini)\n");
            if (tamanho < 6) {
                printf("- Possivel especie: Arapua ou Jatai (muito pequenas)\n");
            } else if (tamanho >= 6 && tamanho <= 10) {
                printf("- Possivel especie: Manduri, Jatai ou Mirim\n");
            } else if (tamanho > 10) {
                printf("- Possivel especie: Mandacaia (Melipona)\n");
            }
        }
        
        printf("\n\033[31mEspecie exata nao identificada!\033[0m\n");
        printf("Sugestao: Cadastre esta abelha no sistema para futuras referencias.\n");
    }
    
    printf("\n----------------------------------------\n");
    printf("Resumo da analise:\n");
    printf("- Cor: ");
    switch(cor) {
        case 'A': printf("Amarela\n"); break;
        case 'P': printf("Preta\n"); break;
        case 'M': printf("Marrom\n"); break;
        case 'V': printf("Verde\n"); break;
    }
    printf("- Tamanho: %.1f mm\n", tamanho);
    printf("- Ferrao: %s\n", (ferrao == 1) ? "Sim" : "Nao");
    
    printf("\n==========================================\n");
    pausar();
}
void menuRelatorios() {
    int op;
    do {
        limparTela();
        printf("\033[33m========== RELATORIOS ==========\033[0m\n");
        printf("1 - Media geral de producao de mel\n");
        printf("2 - Media de valores dos sensores\n");
        printf("3 - Quantidade de abelhas por regiao\n");
        printf("4 - Identificador de especie (BeeVision)\n");
        printf("0 - Voltar ao menu principal\n");
        printf("\033[33m===============================\033[0m\n");
        
        op = lerInteiro("\033[33mOpcao:\033[0m ", 0, 4);
        
        switch (op) {
            case 1: mediaProducaoMel(); break;
            case 2: mediaValorSensores(); break;
            case 3: quantidadePorRegiao(); break;
            case 4: identificador(); break;
        }
    } while (op != 0);
}