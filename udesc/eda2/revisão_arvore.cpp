#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    struct no* pai;
    struct no* esquerda;
    struct no* direita;
    float valor;
} No;

typedef struct arvore {
    struct no* raiz;
} Arvore;

Arvore* cria() {
    Arvore* arvore = malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

int vazia(Arvore* arvore) {
    return (arvore->raiz == NULL);
}

No* adiciona(Arvore* arvore, No* pai, float valor) {
    No* no = malloc(sizeof(No));
    no->pai = pai;
    no->esquerda = NULL;
    no->direita = NULL;
    no->valor = valor;

    if (pai == NULL) {
        arvore->raiz = no;
    }
    return no;
}

void remove_no(Arvore* arvore, No* no) {
    if (no->esquerda != NULL)
        remove_no(arvore, no->esquerda);

    if (no->direita != NULL)
        remove_no(arvore, no->direita);

    if (no->pai == NULL) {
        arvore->raiz = NULL;
    } else {
        if (no->pai->esquerda == no)
            no->pai->esquerda = NULL;
        else
            no->pai->direita = NULL;
    }
    free(no);
}

void percorrer(No* no) {
    if (no != NULL) {
        printf("%f ", no->valor);
        percorrer(no->esquerda);
        percorrer(no->direita);
    }
}

int main() {
    Arvore* minha_arvore = cria();

    // Leitura dos valores da árvore a partir da entrada padrão
    int n;
    printf("Quantos elementos na arvore: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        float valor;
        printf("Insira o valor do elemento %d: ", i + 1);
        scanf("%f", &valor);
        adiciona(minha_arvore, NULL, valor);
    }

    printf("Percurso da arvore: ");
    percorrer(minha_arvore->raiz);
    printf("\n");

    // Libera a memória alocada pela árvore
    if (!vazia(minha_arvore)) {
        remove_no(minha_arvore, minha_arvore->raiz);
    }
    free(minha_arvore);

    return 0;
}
