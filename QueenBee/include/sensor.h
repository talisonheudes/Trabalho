#ifndef SENSOR_H
#define SENSOR_H

#include "abelha.h"

#define MAX_SENSORES 100

typedef struct {
    int id;
    char tipo[50];
    float valor;
    int abelhaId;
} Sensor;

extern Sensor sensores[MAX_SENSORES];
extern int qtdS;

//funções do sensor
void cadastrarSensor();
void listarSensores();
void buscarSensor();
void removerSensor();
void alterarSensor();
void menuSensores();

#endif 