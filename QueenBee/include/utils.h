#ifndef UTILS_H
#define UTILS_H

void limparBuffer(); //limpar buffer do teclado
void limparTela();
void pausar();
int lerInteiro(const char* msg, int min, int max);
float lerFloat(const char* msg, float min);
void lerString(const char* msg, char* destino, int tamanho); //ler texto

#endif