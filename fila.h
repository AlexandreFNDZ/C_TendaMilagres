#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

// Autor: Alexandre Fernandes RA25080 - 2CTi 2019

typedef struct fila Fila;
Fila* cria (void);
int insere (Fila* f);
int retira (Fila* f);
int vazia (Fila* f);
void libera (Fila* f);
void imprime (Fila* f);
int conta (Fila* f);
void imprimeSenha (int senhaChamada, char bencao);

#endif // FILA_H_INCLUDED
