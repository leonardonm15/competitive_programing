#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "avl.h"

int comp = 0;

#define if comp++;if

Arvore* criar() {
    srand(time(NULL));
    Arvore *arvore = malloc(sizeof(Arvore));
    arvore->raiz = NULL;

    return arvore;
}

int randll() {
    return (int) rand() * (int) 1e9 + rand();
}

int max(int a, int b) {
    comp++;
    return a > b ? a : b;
}

int vazia(Arvore* arvore) {
    return arvore->raiz == NULL;
}

int multinsert(int termo) {
    Arvore* a = criar();
    comp++;
    for (int i = 1; i <= termo; i++) {
        comp++;
        int k = randll();
        adicionar(a, k);
    }
    return comp;
}

int multidelete(int termo) {
    Arvore* a = criar();
    int arr[10001];
    
    int it = 0;
    for (int i = 1; i <= 10000; i++){
        arr[i - 1] = 0;
        int k = abs(randll() % 10000);
        arr[it++] = k;
        adicionar(a, k);
    }
    comp = 0;
    comp++;
    for (int i=0; i < termo; i++) {
        comp++;
        int k = abs(rand() % 10001);
        if (k == 0) k++;
        if (arr[k]) remove_nodo(a, a->raiz, k);
        else continue;
        i--:
    }

    return comp;
}


No* rse(Arvore* arvore, No* no) {
    No* pai = no->pai;
    No* direita = no->direita;

    if (direita->esquerda != NULL) {
        direita->esquerda->pai = no;
    } 

    no->direita = direita->esquerda;
    no->pai = direita;

    direita->esquerda = no;
    direita->pai = pai;

    if (pai == NULL) {
        arvore->raiz = direita;
    } else {
        if (pai->esquerda == no) {
            pai->esquerda = direita;
        } else {
            pai->direita = direita;
        }
    }

    return direita;
}

No* rsd(Arvore* arvore, No* no) {
    No* pai = no->pai;
    No* esquerda = no->esquerda;

    if (esquerda->direita != NULL) {
        esquerda->direita->pai = no;
    } 

    no->esquerda = esquerda->direita;
    no->pai = esquerda;

    esquerda->direita = no;
    esquerda->pai = pai;

    if (pai == NULL) {
        arvore->raiz = esquerda;
    } else {
        if (pai->esquerda == no) {
            pai->esquerda = esquerda;
        } else {
            pai->direita = esquerda;
        }
    }

    return esquerda;
}

No* rde(Arvore* arvore, No* no) {
    no->direita = rsd(arvore, no->direita);
    return rse(arvore, no);
}

No* rdd(Arvore* arvore, No* no) {
    no->esquerda = rse(arvore, no->esquerda);
    return rsd(arvore, no);
}

No* criarNo(int valor) {
    No* no = malloc(sizeof(No));
    no->valor = valor;
    no->pai = NULL;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

No* adicionarNo(No* no, int valor) {
    if (valor > no->valor) {
        if (no->direita == NULL) {
            /* printf("Adicionando %d\n",valor); */
            No* novo = criarNo(valor);
            novo->pai = no;
            no->direita = novo;

            return novo;
        } else {
            return adicionarNo(no->direita, valor);
        }
    } else {
        if (no->esquerda == NULL) {
            /* printf("Adicionando %d\n",valor); */
            No* novo = criarNo(valor);
            novo->pai = no;
            no->esquerda = novo;

            return novo;
        } else {
            return adicionarNo(no->esquerda, valor);
        }
    }
}

void balanceamento(Arvore* a, No* no) {
    while (no != NULL) {
        comp++;
        int fator = fb(no);

        if (fator > 1) { 
            //arvore mais profunda a esquerda
            //rotacao a direita
            if (fb(no->esquerda) > 0) {
                /* printf("RSD(%d)\n", no->valor); */
                rsd(a, no);
            } else {
                /* printf("RDD(%d)\n", no->valor); */
                rdd(a, no);
            }
        } else if (fator < -1) {
            //rotacao a esquerda
            if (fb(no->direita) < 0) {
                /* printf("RSE(%d)\n", no->valor); */
                rse(a, no);
            } else {
                /* printf("RDE(%d)\n", no->valor); */
                rde(a, no);
            }
        }
        no = no->pai;
    }
}

No* adicionar(Arvore* arvore, int valor) {
    if (arvore->raiz == NULL) {
        /* printf("Adicionando %d\n",valor); */
        No* novo = criarNo(valor);
        arvore->raiz = novo;

        return novo;
    } else {
        No* no = adicionarNo(arvore->raiz, valor);
        balanceamento(arvore, no);
        return no;
    }
}


No* localizar(No* no, int valor) {
    if (no->valor == valor) {
        return no;
    } else {
        if (valor < no->valor) {
            if (no->esquerda != NULL) {
                return localizar(no->esquerda, valor);
            }
        } else {
            if (no->direita != NULL) {
                return localizar(no->direita, valor);
            }
        }
    }

    return NULL;
}

No* menor_nodo(No* nodo) {
    return nodo->esquerda == NULL ? nodo : menor_nodo(nodo->esquerda);
}


No* remove_nodo(Arvore* arvore , No* raiz, int valor) { 
    if (raiz == NULL) 
        return raiz; 

    if (valor < raiz->valor) raiz->esquerda = remove_nodo(arvore, raiz->esquerda, valor); 
    else if ( valor > raiz->valor ) raiz->direita = remove_nodo(arvore, raiz->direita, valor); 

    else { 
        if((raiz->esquerda == NULL) || (raiz->direita == NULL) ) { 
            No* noDeletar = raiz->esquerda ? 
                raiz->esquerda : 
                raiz->direita; 
            if (noDeletar == NULL) { 
                noDeletar = raiz; 
                raiz = NULL; 
            } 
            else {
                No* temp = raiz;
                raiz = noDeletar;
                noDeletar = temp;
            } 
            free(noDeletar); 
        } 
        else { 
            No* temp = menor_nodo(raiz->direita); 

            raiz->valor = temp->valor; 

            raiz->direita = remove_nodo(arvore, raiz->direita, temp->valor); 
        } 
    } 

    if (raiz == NULL) return raiz; 

    int f = fb(raiz); 

    if (f > 1 && fb(raiz->esquerda) >= 0) return rsd(arvore, raiz); 

    if (f > 1 && fb(raiz->esquerda) < 0) return rdd(arvore, raiz); 

    if (f < -1 && fb(raiz->direita) <= 0) return rse(arvore, raiz); 

    if (f < -1 && fb(raiz->direita) > 0) return rde(arvore, raiz);

    return raiz; 
} 

void percorrer(No* no, void (*callback)(int)) {
    if (no != NULL) {
        percorrer(no->esquerda,callback);
        callback(no->valor);
        percorrer(no->direita,callback);
    }
}

/* void visitar(int valor){ */
/*     printf("%d ", valor); */
/* } */

int altura(No* no){
    int esquerda = 0,direita = 0;

    if (no->esquerda != NULL) {
        esquerda = altura(no->esquerda) + 1;
    }

    if (no->direita != NULL) {
        direita = altura(no->direita) + 1;
    }

    return esquerda > direita ? esquerda : direita; //max(esquerda,direita)
}

int fb(No* no) {
    int esquerda = 0,direita = 0;

    if (no->esquerda != NULL) esquerda = altura(no->esquerda) + 1;

    if (no->direita != NULL) direita = altura(no->direita) + 1;

    return esquerda - direita;
}



signed main() {
    /* int res1 = multinsert(10); */
    /* printf("resultado -> %lld \n", res1); */
    /* int res2 = multinsert(100); */
    /* printf("resultado -> %lld \n", res2); */
    /* int res3 = multinsert(1000); */
    /* printf("resultado -> %lld \n", res3); */
    /* int res4 = multinsert(10000); */
    /* printf("resultado -> %lld \n", res4); */

    int res2 = multidelete(10);
    printf("resultado -> %lld \n", res2);
    res2 = multidelete(100);
    printf("resultado -> %lld \n", res2);
    res2 = multidelete(1000);
    printf("resultado -> %lld \n", res2);
    res2 = multidelete(10000);
    printf("resultado -> %lld \n", res2);

}
