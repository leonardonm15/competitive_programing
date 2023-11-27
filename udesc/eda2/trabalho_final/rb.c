#include <stdlib.h>
#include "rb.h"
int comp = 0;

int randll() {
    return (int) rand() * (int) 1e9 + rand();
}

int max(int a, int b) {
    return a > b ? a : b;
}

void trocar_valores(No* a, No* b) {
    int aux = a->valor;
    a->valor = b->valor;
    b->valor = aux;
    return;
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


void deleteByVal(Arvore* a, int n) {
    if (a->raiz == NULL)
        return;

    No *v = localizar(a, n);
    if (v->valor != n) {
        printf("No node found to delete with value: %lld\n", v->valor);
        return;
    }
    remove_nodo(a, v);
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
            deleteByVal(a, k);
            /* remove_nodo(a, a->raiz, k); */
            arr[k]++;
        }
        else {
            i--;
            continue;
        }
    }
    return comp;
}

bool isOnLeft(No* a) {a->esquerda == NULL? false : true;}

// returns pointer to sibling
No* sibling(No* a) {
    // sibling null if no parent
    if (a->pai == NULL)
        return NULL;

    if (isOnLeft(a))
        return a->pai->direita;

    return a->pai->esquerda;
}

void remove_nodo(Arvore* arvore, No *v) {
    /* printf("recursão\n"); */
    No *u = BSTreplace(v); // True when u and v are both black
    bool uvBlack = ((u == NULL || u->cor == Preto) && (v->cor == Preto));
    No *parent = v->pai;
    comp++;
    if (u == NULL) {
        comp++;
        if (v == arvore->raiz) { // v is root, making root null
            arvore->raiz = NULL;
        } else {
            comp++;
            if (uvBlack) {
                // u and v both black
                // v is leaf, fix double black at v
                balancear(arvore, v);
            } else {
                // u or v is red
                comp++;
                printf("caiu aqui red\n");
                if (sibling(v) != NULL)
                    // sibling is not null, make it red"
                    sibling(v)->cor = Vermelho;
            }

            // delete v from the tree
            comp++;
            if (isOnLeft(v)) {
                parent->esquerda = NULL;
            } else {
                parent->direita = NULL;
            }
        }
        free(v);
        return;
    }

    comp++;
    if (v->esquerda == NULL || v->direita == NULL) {
        printf("caiu aqui v tem 1 filho\n");
        // v has 1 child
        comp++;
        if (v->valor == arvore->raiz->valor) {
            // v is root, assign the value of u to v, and delete u
            v->valor= u->valor;
            v->esquerda = v->direita = NULL;
            free(u);
        } else {
            // Detach v from tree and move u up
            comp++;
            if (isOnLeft(v)) {
                parent->esquerda = u;
            } else {
                parent->direita = u;
            }
            free(v);
            u->pai = parent;
            comp++;
            if (uvBlack) {
                // u and v both black, fix double black at u
                balancear(arvore, u);
            } else {
                // u or v red, cor u black
                u->cor = Preto;
            }
        }
        return;
    }

    // v has 2 children, swap values with successor and recurse
    trocar_valores(u, v); 
    remove_nodo(arvore, u);
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

No* BSTreplace(No* x) {
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
    comp++;
    if (!vazia(arvore)) {
        No* no = arvore->raiz;

        while (no != arvore->nulo) {
            comp++;
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
    printf("consegui entrar no balanceamento\n");
    printf("quero balancear o nodo de valor %lld\n", no->valor);
    while (no->pai->cor == Vermelho) {
        printf("nodo é vermelho\n");
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

signed main() {
    srand(time(NULL));

    /* int res1 = multinsert(10); */
    /* printf("resultado -> %lld \n", res1); */
    /* int res2 = multinsert(100); */
    /* printf("resultado -> %lld \n", res2); */
    /* int res3 = multinsert(1000); */
    /* printf("resultado -> %lld \n", res3); */
    /* int res4 = multinsert(10000); */
    /* printf("resultado -> %lld \n", res4); */
    /* int res5 = multinsert(100000); */
    /* printf("resultado -> %lld \n", res5); */

    int res1 = multidelete(1);
    printf("resultado -> %lld \n", res1);
}
