#ifndef ABELHA_H //impede inclusão duplicada
#define ABELHA_H //define a constante abelha
//Batman e Robin na proteção de inclusão duplicada

#include "utils.h"

#define MAX_ABELHAS 50

typedef struct {
    int id;
    char nomePopular[50];
    char nomeCientifico[50];
    char regiao[50];
    float producaoMel;
    char especie[100];
} Abelha;

extern Abelha abelhas[MAX_ABELHAS]; //avisa ao compilador que a variavel foi criada em outro lugar
extern int qtdA;

//funções da abelha
void cadastrarAbelha();
void listarAbelhas();
void buscarAbelha();
void removerAbelha();
void menuAbelhas();
void alterarAbelha();

#endif