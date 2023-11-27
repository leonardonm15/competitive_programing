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
int multinsert(int termo);
int multidelete(int termo);
int vazia(Arvore* arvore);

bool isOnLeft(No* a);

void remove_nodo(Arvore* arvore, No *v);
void trocar_valores(No* a, No* b);
void balancear(Arvore* arvore, No* no);
void rotacionarEsquerda(Arvore* arvore, No* no);
void rotacionarDireita(Arvore* arvore, No* no);
void deleteByVal(Arvore* a, int n);

No* criarNo(Arvore* arvore, No* pai, int valor);
No* sibling(No* a);
No* adicionarNo(Arvore* arvore, No* no, int valor);
No* adicionar(Arvore* arvore, int valor);
No *successor(No *x);
No* BSTreplace(No* x);
No* localizar(Arvore* arvore, int valor);
Arvore* criar();
