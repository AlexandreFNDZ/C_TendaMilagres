#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

// Autor: Alexandre Fernandes RA25080 - 2CTi 2019

typedef struct no {
    int senha;
    struct no* prox;
};
typedef struct no No;

typedef struct fila {
    No* ini;
    No* fim;
};

Fila* cria (void)
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

/* função auxiliar: insere no fim */
No* ins_fim (No* fim)
{
    No* p = (No*) malloc(sizeof(No));
    p->senha = 1;
    p->prox = NULL;
    if (fim != NULL) { /* verifica se lista não estava vazia */
        p->senha = fim->senha + 1;
        fim->prox = p;
    }
    return p;
}

/* função auxiliar: retira do início */
No* ret_ini (No* ini)
{
    No* p = ini->prox;
    free(ini);
    return p;
}

int insere (Fila* f)
{
    f->fim = ins_fim(f->fim);
    if (f->ini==NULL) {/* fila antes vazia? */
        f->ini = f->fim;
    }

    return f->fim->senha;
}

int retira (Fila* f)
{
    int v;
    if (vazia(f)) {
        printf("Fila vazia.\n");
        exit(1); /* aborta programa */
    }
    v = f->ini->senha;
    f->ini = ret_ini(f->ini);
    if (f->ini == NULL) /* fila ficou vazia? */
        f->fim = NULL;
    return v;
}

int vazia (Fila* f)
{
    return (f->ini==NULL);
}

void libera (Fila* f)
{
    No* q = f->ini;
    while (q!=NULL) {
        No* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
}

/* imprime: versão com lista */
void imprime (Fila* f)
{
    No* q;
    for (q=f->ini; q!=NULL; q=q->prox) {
        printf("%d\n",q->senha);
    }
}

int conta (Fila* f)
{
    int qtd = 0;
    No* q;
    for (q=f->ini; q!=NULL; q=q->prox) {
        qtd++;
    }

    return qtd;
}

void imprimeSenha (int senhaChamada, char bencao)
{
    system("cls");
    printf("Senha Chamada: %c%d\n\n", bencao, senhaChamada);
    printf("Favor dirigir-se ao local correspondente!\n\n\n");
    system("pause");
}

