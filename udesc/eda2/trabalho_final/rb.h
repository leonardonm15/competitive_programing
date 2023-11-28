#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define int long long

enum coloracao { Vermelho, Preto };
typedef enum coloracao Cor;

typedef struct no {
    struct no* pai;
    struct no* esquerda;
    struct no* direita;
    Cor cor;
    int valor;
} No;

typedef struct arvore {
    struct no* raiz;
    struct no* nulo; 
} Arvore;

int randll();

int max(int a, int b);

void trocar_valores(No* a, No* b);

Arvore* criar();

int vazia(Arvore* arvore);

No* criarNo(Arvore* arvore, No* pai, int valor);

int multinsert(int termo);

void deleteByVal(Arvore* a, int n);

int multidelete(int termo);

// returns pointer to sibling

void remove_nodo(Arvore* arvore, No *v);

No* adicionarNo(Arvore* arvore, No* no, int valor);

No* adicionar(Arvore* arvore, int valor);
// parte nova

No* deletar(Arvore* arvore, int valor);

No* deletarNo(Arvore* arvore, No* no, int valor);

No* minimo(Arvore* arvore, No* no);

void balancearRemocao(Arvore* arvore, No* no);

No *successor(No *x);

No* BSTreplace(No* x);

No* localizar(Arvore* arvore, int valor);

void visitar(int valor);

void balancear(Arvore* arvore, No* no);

void rotacionarEsquerda(Arvore* arvore, No* no);

void rotacionarDireita(Arvore* arvore, No* no);

