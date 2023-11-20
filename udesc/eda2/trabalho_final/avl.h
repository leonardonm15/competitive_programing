#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    struct no* pai;
    struct no* esquerda;
    struct no* direita;
    int valor;
} No;

typedef struct arvore {
    struct no* raiz;
} Arvore;

Arvore* criar();

No* rse(Arvore* arvore, No* no);

No* rsd(Arvore* arvore, No* no);

No* rde(Arvore* arvore, No* no);

No* rdd(Arvore* arvore, No* no);

int vazia(Arvore* arvore);

int max(int a, int b);

No* criarNo(int valor);

void balanceamento(Arvore* a, No* no);

No* adicionar(Arvore* arvore, int valor);

No* localizar(No* no, int valor);

No* menor_nodo(No* nodo);

No* remove_nodo(Arvore* arvore , No* raiz, int valor);

void percorrer(No* no, void (*callback)(int));

void visitar(int valor);

int altura(No* no);

int fb(No* no);


