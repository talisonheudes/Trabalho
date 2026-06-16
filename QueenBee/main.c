#include <stdio.h>
#include "include/relatorio.h"

extern Abelha abelhas[MAX_ABELHAS];
extern Sensor sensores[MAX_SENSORES];
extern int qtdA, qtdS;

int main() {
    int boi;
  
    do {
        limparTela();
        printf("\033[33m========== QUEEN BEE ==========\033[0m\n");
        printf("1 - Gerenciar abelhas\n");
        printf("2 - Gerenciar sensores\n");
        printf("3 - Relatorios\n");
        printf("\033[31m0 - Sair\033[0m\n");
        printf("\033[33m================================\033[0m\n");
        boi = lerInteiro("\033[33mOpcao:\033[0m ", 0, 3);
        
        switch (boi) {
            case 1: menuAbelhas(); break;
            case 2: menuSensores(); break;
            case 3: menuRelatorios(); break;
            case 0: 
                limparTela();
                printf("\nEncerrando o programa...\n\n");
                break;
        }
    } while (boi != 0);
    
    return 0;
}