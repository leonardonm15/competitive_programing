#include <stdlib.h>
#include <stdio.h>
#include "rb.h"
#include <stdbool.h>

int comp = 0;

int randll() {
    return (int) rand() * (int) 1e9 + rand();
}

int max(int a, int b) {
    return a > b ? a : b;
}

Arvore* criar() {
    Arvore *arvore = malloc(sizeof(Arvore));
    arvore->nulo = NULL;
    arvore->raiz = NULL;

    arvore->nulo = criarNo(arvore, NULL, 0);
    arvore->nulo->cor = Preto;

    return arvore;
}

int vazia(Arvore* arvore) {
    return arvore->raiz == NULL;
}

No* criarNo(Arvore* arvore, No* pai, int valor) {
    No* no = malloc(sizeof(No));

    no->pai = pai;    
    no->valor = valor;
    no->direita = arvore->nulo;
    no->esquerda = arvore->nulo;

    return no;
}

int multinsert(int termo) {
    Arvore* a = criar();
    comp = 0;
    for (int i = 1; i <= termo; i++) {
        int k = randll();
        adicionar(a, k);
    }
    return comp;
}


int multidelete(int termo) {
    Arvore* a = criar();
    int arr[100000];
    for (int i = 1; i <= 10000; i++){
        arr[i - 1] = 0;
        adicionar(a, i);
    }

    comp = 0;
    for (int i=0; i < termo; i++) {
        int k = abs(rand() % 10001);
        if (!arr[k]) {
            // remove_nodo(a, a->raiz, k);
            arr[k]++;
        }
        else {
            i--;
            continue;
        }
    }
    return comp;
}

void remove_nodo(No *v) {
    No *u = BSTreplace(v);
 
    // True when u and v are both black
    bool uvBlack = ((u == NULL || u->cor == Preto) && (v->cor == Preto));
    No *parent = v->pai;
 
    if (u == NULL) {
      // u is NULL therefore v is leaf
      if (v == root) {
        // v is root, making root null
        root = NULL;
      } else {
        if (uvBlack) {
          // u and v both black
          // v is leaf, fix double black at v
          fixDoubleBlack(v);
        } else {
          // u or v is red
          if (v->sibling() != NULL)
            // sibling is not null, make it red"
            v->sibling()->cor = Vermelho;
        }
 
        // delete v from the tree
        if (v->isOnLeft()) {
          parent->esquerda = NULL;
        } else {
          parent->direita = NULL;
        }
      }
      delete v;
      return;
    }
 
    if (v->esquerda == NULL or v->direita == NULL) {
      // v has 1 child
      if (v == root) {
        // v is root, assign the value of u to v, and delete u
        v->val = u->val;
        v->esquerda = v->direita = NULL;
        delete u;
      } else {
        // Detach v from tree and move u up
        if (v->isOnLeft()) {
          parent->esquerda = u;
        } else {
          parent->direita = u;
        }
        delete v;
        u->parent = parent;
        if (uvBlack) {
          // u and v both black, fix double black at u
          fixDoubleBlack(u);
        } else {
          // u or v red, cor u black
          u->cor = Preto;
        }
      }
      return;
    }
 
    // v has 2 children, swap values with successor and recurse
    swapValues(u, v);
    deleteNo(u);
}


No* adicionarNo(Arvore* arvore, No* no, int valor) {
    comp++;
    if (valor > no->valor) {
        comp++;
        if (no->direita == arvore->nulo) {
            no->direita = criarNo(arvore, no, valor);     
            no->direita->cor = Vermelho;       

            return no->direita;
        } else {
            return adicionarNo(arvore, no->direita, valor);
        }
    } else {
        comp++;
        if (no->esquerda == arvore->nulo) {
            no->esquerda = criarNo(arvore, no, valor);
            no->esquerda->cor = Vermelho;

            return no->esquerda;
        } else {
            return adicionarNo(arvore, no->esquerda, valor);
        }
    }
}

No* adicionar(Arvore* arvore, int valor) {
    comp++;
    if (vazia(arvore)) {
        arvore->raiz = criarNo(arvore, arvore->nulo, valor);
        arvore->raiz->cor = Preto;

        return arvore->raiz;
    } else {
        No* no = adicionarNo(arvore, arvore->raiz, valor);
        balancear(arvore, no);

        return no;
    }
}

No *successor(No *x) {
    No *temp = x;

    while (temp->esquerda != NULL)
        temp = temp->esquerda;

    return temp;
}

No* BSTreplace(No *x) {
    // when node have 2 children
    if (x->esquerda != NULL && x->esquerda != NULL)
        return successor(x->direita);

    // when leaf
    if (x->esquerda == NULL && x->direita == NULL)
        return NULL;

    // when single child
    if (x->esquerda != NULL)
        return x->esquerda;
    else
        return x->direita;
}

No* localizar(Arvore* arvore, int valor) {
    if (!vazia(arvore)) {
        No* no = arvore->raiz;

        while (no != arvore->nulo) {
            if (no->valor == valor) {
                return no;
            } else {
                no = valor < no->valor ? no->esquerda : no->direita;
            }
        }
    }

    return NULL;
}

void visitar(int valor){
    printf("%lld ", valor);
}

void balancear(Arvore* arvore, No* no) {
    while (no->pai->cor == Vermelho) {
        if (no->pai == no->pai->pai->esquerda) {
            No *tio = no->pai->pai->direita;

            if (tio->cor == Vermelho) {
                tio->cor = Preto; //Caso 1
                no->pai->cor = Preto; 

                no->pai->pai->cor = Vermelho; //Caso 1
                no = no->pai->pai; //Caso 1
            } else {
                if (no == no->pai->direita) {
                    no = no->pai; //Caso 2
                    rotacionarEsquerda(arvore, no); //Caso 2
                } else {
                    no->pai->cor = Preto; 
                    no->pai->pai->cor = Vermelho; //Caso 3
                    rotacionarDireita(arvore, no->pai->pai); //Caso 3
                }
            }
        } else {
            No *tio = no->pai->pai->esquerda;

            if (tio->cor == Vermelho) {
                tio->cor = Preto; //Caso 1
                no->pai->cor = Preto; 

                no->pai->pai->cor = Vermelho; //Caso 1
                no = no->pai->pai; //Caso 1
            } else {
                if (no == no->pai->esquerda) {
                    no = no->pai; //Caso 2
                    rotacionarDireita(arvore, no); //Caso 2
                } else {
                    no->pai->cor = Preto; 
                    no->pai->pai->cor = Vermelho; //Caso 3
                    rotacionarEsquerda(arvore, no->pai->pai); //Caso 3
                }
            }
        }
    }
    arvore->raiz->cor = Preto; //Conserta possível quebra regra 2
}

void rotacionarEsquerda(Arvore* arvore, No* no) {
    No* direita = no->direita;
    no->direita = direita->esquerda; 

    if (direita->esquerda != arvore->nulo) {
        direita->esquerda->pai = no;
    }

    direita->pai = no->pai;

    if (no->pai == arvore->nulo) {
        arvore->raiz = direita;
    } else if (no == no->pai->esquerda) {
        no->pai->esquerda = direita;
    } else {
        no->pai->direita = direita;
    }

    direita->esquerda = no;
    no->pai = direita;
}

void rotacionarDireita(Arvore* arvore, No* no) {
    No* esquerda = no->esquerda;
    no->esquerda = esquerda->direita;

    if (esquerda->direita != arvore->nulo) {
        esquerda->direita->pai = no;
    }

    esquerda->pai = no->pai;

    if (no->pai == arvore->nulo) {
        arvore->raiz = esquerda;
    } else if (no == no->pai->esquerda) {
        no->pai->esquerda = esquerda;
    } else {
        no->pai->direita = esquerda;
    }

    esquerda->direita = no;
    no->pai = esquerda;
}

int main() {
    srand(time(NULL));

    int res1 = multinsert(10);
    printf("resultado -> %lld \n", res1);
    int res2 = multinsert(100);
    printf("resultado -> %lld \n", res2);
    int res3 = multinsert(1000);
    printf("resultado -> %lld \n", res3);
    int res4 = multinsert(10000);
    printf("resultado -> %lld \n", res4);
    /* int res5 = multinsert(100000); */
    /* printf("resultado -> %lld \n", res5); */


}
