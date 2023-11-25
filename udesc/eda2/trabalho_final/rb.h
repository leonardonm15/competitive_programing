#include <stdlib.h>
#include <stdio.h>
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

void balancear(Arvore*, No*);
Arvore* criar();
int vazia(Arvore* arvore);
No* criarNo(Arvore* arvore, No* pai, int valor);
No* adicionarNo(Arvore* arvore, No* no, int valor);
No* adicionar(Arvore* arvore, int valor);
No* localizar(Arvore* arvore, int valor);
void percorrerProfundidadeInOrder(Arvore* arvore, No* no, void (*callback)(int));
void percorrerProfundidadePreOrder(Arvore* arvore, No* no, void (*callback)(int));
void percorrerProfundidadePosOrder(Arvore* arvore, No* no, void (callback)(int));
void visitar(int valor);
void balancear(Arvore* arvore, No* no);
void rotacionarEsquerda(Arvore* arvore, No* no);
void rotacionarDireita(Arvore* arvore, No* no);
