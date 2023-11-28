#include <stdlib.h>
#include "rb.h"
int comp = 0;
int rec = 0;

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

int multidelete(int termo) {
    Arvore* a = criar();
    int arr[100000];
    for (int i = 1; i <= 10000; i++){
        arr[i - 1] = 0;
        adicionar(a, i);
    }
    comp = 0;
    for (int i=0; i < termo; i++) {
        int dm = comp;
        int k = abs(rand() % 10001);
        if (k == 0) k++;
        if (!arr[k]) {
            deletar(a, k);
            /* remove_nodo(a, a->raiz, k); */
            arr[k]++;
        }
        else {
            /* printf("i -> %lld\n", i); */
            i--;
            comp -= (comp - dm);
            continue;
        }
    }
    return comp;
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
        balancearRemocao(arvore, no);
        return no;
    }
}
// parte nova

No* deletar(Arvore* arvore, int valor) {
    comp++;
    if (!vazia(arvore)) {
        arvore->raiz = deletarNo(arvore, arvore->raiz, valor);
        rec = 0;
        arvore->raiz->cor = Preto;
    }
}

No* deletarNo(Arvore* arvore, No* no, int valor) {
    rec++;
    /* printf("recursão infinita ? - %lld\n", rec); */
    comp++;
    if (no == arvore->nulo) {
        printf("1\n");
        return no;
    }

    comp++;
    if (valor < no->valor) {
        printf("2\n");
        no->esquerda = deletarNo(arvore, no->esquerda, valor);
    } else if (valor > no->valor) {
        printf("3\n");
        comp++;
        no->direita = deletarNo(arvore, no->direita, valor);
    } else {
        comp++;
        if (no->esquerda == arvore->nulo || no->direita == arvore->nulo) {
            printf("5\n");
            No* filho = (no->esquerda == arvore->nulo) ? no->direita : no->esquerda;
            comp++;
            if (no->cor == Preto && filho->cor == Preto) {
                printf("6\n");
                balancear(arvore, no);
            }

            free(no);
            /* printf("vai printar o fiho\n"); */
            /* printf("vai retornar o filho %lld\n", filho->valor); */
            return filho;
        }
        printf("4\n");
        comp++;
        No* sucessor = minimo(arvore, no->direita);
        no->valor = sucessor->valor;
        no->direita = deletarNo(arvore, no->direita, sucessor->valor);
    }

    return no;
}

No* minimo(Arvore* arvore, No* no) {
    while (no->esquerda != arvore->nulo) {
        no = no->esquerda;
    }
    return no;
}

void balancearRemocao(Arvore* arvore, No* no) {
    while (no != arvore->raiz && no->cor == Preto) {
        if (no == no->pai->esquerda) {
            No* irmao = no->pai->direita;

            if (irmao->cor == Vermelho) {
                irmao->cor = Preto;
                no->pai->cor = Vermelho;
                rotacionarEsquerda(arvore, no->pai);
                irmao = no->pai->direita;
            }

            if (irmao->esquerda->cor == Preto && irmao->direita->cor == Preto) {
                irmao->cor = Vermelho;
                no = no->pai;
            } else {
                if (irmao->direita->cor == Preto) {
                    irmao->esquerda->cor = Preto;
                    irmao->cor = Vermelho;
                    rotacionarDireita(arvore, irmao);
                    irmao = no->pai->direita;
                }

                irmao->cor = no->pai->cor;
                no->pai->cor = Preto;
                irmao->direita->cor = Preto;
                rotacionarEsquerda(arvore, no->pai);
                no = arvore->raiz;
            }
        } else {
            No* irmao = no->pai->esquerda;

            if (irmao->cor == Vermelho) {
                irmao->cor = Preto;
                no->pai->cor = Vermelho;
                rotacionarDireita(arvore, no->pai);
                irmao = no->pai->esquerda;
            }

            if (irmao->direita->cor == Preto && irmao->esquerda->cor == Preto) {
                irmao->cor = Vermelho;
                no = no->pai;
            } else {
                if (irmao->esquerda->cor == Preto) {
                    irmao->direita->cor = Preto;
                    irmao->cor = Vermelho;
                    rotacionarEsquerda(arvore, irmao);
                    irmao = no->pai->esquerda;
                }

                irmao->cor = no->pai->cor;
                no->pai->cor = Preto;
                irmao->esquerda->cor = Preto;
                rotacionarDireita(arvore, no->pai);
                no = arvore->raiz;
            }
        }
    }
    no->cor = Preto;
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
    /* printf("consegui entrar no balanceamento\n"); */
    /* printf("quero balancear o nodo de valor %lld\n", no->valor); */
    while (no->pai->cor == Vermelho) {
        /* printf("nodo é vermelho\n"); */
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
    /* { */
    /*     int res1 = multidelete(1); */
    /*     printf("resultado -> %lld \n", res1); */
    /* } */
    /* { */
    /*     int res1 = multidelete(10); */
    /*     printf("resultado -> %lld \n", res1); */
    /* } */
    {
        /* int res1 = multidelete(1000); */
        /* printf("resultado -> %lld \n", res1); */
    }
    /* int res1 = multidelete(2000); */
    int res1 = multidelete(100);
    printf("resultado -> %lld \n", res1);
}
