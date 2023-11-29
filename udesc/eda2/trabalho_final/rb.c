// Implementing Red-Black Tree in C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define int long long

int comp = 0;

enum nodeColor {
    RED,
    BLACK
};

struct rbNode {
    int data, color;
    struct rbNode *link[2];
};

struct rbNode *root = NULL;

// Create a red-black tree
struct rbNode *createNode(int data) {
    struct rbNode *newnode;
    newnode = (struct rbNode *)malloc(sizeof(struct rbNode));
    newnode->data = data;
    newnode->color = RED;
    newnode->link[0] = newnode->link[1] = NULL;
    return newnode;
}

int randll() {
    return (int) rand() * (int) 1e9 + rand();
}

// Insert an node
void insertion(int data) {
    struct rbNode *stack[20000], *ptr, *newnode, *xPtr, *yPtr;
    int dir[20000], ht = 0, index;
    ptr = root;

    comp++;
    if (!root) {
        root = createNode(data);
        return;
    }

    stack[ht] = root;
    dir[ht++] = 0;
    while (ptr != NULL) {
        comp++;
        if (ptr->data == data) {
            printf("Duplicates Not Allowed!!\n");
            return;
        }
        index = (data - ptr->data) > 0 ? 1 : 0;
        stack[ht] = ptr;
        ptr = ptr->link[index];
        dir[ht++] = index;
    }
    stack[ht - 1]->link[index] = newnode = createNode(data);
    while ((ht >= 3) && (stack[ht - 1]->color == RED)) {
        comp++;
        comp++;
        if (dir[ht - 2] == 0) {
            yPtr = stack[ht - 2]->link[1];
            comp++;
            if (yPtr != NULL && yPtr->color == RED) {
                stack[ht - 2]->color = RED;
                stack[ht - 1]->color = yPtr->color = BLACK;
                ht = ht - 2;
            } else {
                comp++;
                if (dir[ht - 1] == 0) {
                    yPtr = stack[ht - 1];
                } else {
                    xPtr = stack[ht - 1];
                    yPtr = xPtr->link[1];
                    xPtr->link[1] = yPtr->link[0];
                    yPtr->link[0] = xPtr;
                    stack[ht - 2]->link[0] = yPtr;
                }
                xPtr = stack[ht - 2];
                xPtr->color = RED;
                yPtr->color = BLACK;
                xPtr->link[0] = yPtr->link[1];
                yPtr->link[1] = xPtr;
                comp++;
                if (xPtr == root) {
                    root = yPtr;
                } else {
                    stack[ht - 3]->link[dir[ht - 3]] = yPtr;
                }
                break;
            }
        } else {
            yPtr = stack[ht - 2]->link[0];
            comp++;
            if ((yPtr != NULL) && (yPtr->color == RED)) {
                stack[ht - 2]->color = RED;
                stack[ht - 1]->color = yPtr->color = BLACK;
                ht = ht - 2;
            } else {
                comp++;
                if (dir[ht - 1] == 1) {
                    yPtr = stack[ht - 1];
                } else {
                    xPtr = stack[ht - 1];
                    yPtr = xPtr->link[0];
                    xPtr->link[0] = yPtr->link[1];
                    yPtr->link[1] = xPtr;
                    stack[ht - 2]->link[1] = yPtr;
                }
                xPtr = stack[ht - 2];
                yPtr->color = BLACK;
                xPtr->color = RED;
                xPtr->link[1] = yPtr->link[0];
                yPtr->link[0] = xPtr;
                comp++;
                if (xPtr == root) {
                    root = yPtr;
                } else {
                    stack[ht - 3]->link[dir[ht - 3]] = yPtr;
                }
                break;
            }
        }
    }
    root->color = BLACK;
}
// Delete a node
void deletion(int data) {
    struct rbNode *stack[20000], *ptr, *xPtr, *yPtr;
    struct rbNode *pPtr, *qPtr, *rPtr;
    int dir[20000], ht = 0, diff, i;
    enum nodeColor color;

    comp++;
    if (!root) {
        printf("Tree not available\n");
        return;
    }

    ptr = root;
    while (ptr != NULL) {
        comp++;
        comp++;
        if ((data - ptr->data) == 0)
            break;
        diff = (data - ptr->data) > 0 ? 1 : 0;
        stack[ht] = ptr;
        dir[ht++] = diff;
        ptr = ptr->link[diff];
    }

    comp++;
    if (ptr->link[1] == NULL) {
        comp++;
        comp++;
        if ((ptr == root) && (ptr->link[0] == NULL)) {
            free(ptr);
            root = NULL;
        } else if (ptr == root) {
            root = ptr->link[0];
            free(ptr);
        } else {
            stack[ht - 1]->link[dir[ht - 1]] = ptr->link[0];
        }
    } else {
        xPtr = ptr->link[1];
        comp++;
        if (xPtr->link[0] == NULL) {
            xPtr->link[0] = ptr->link[0];
            color = xPtr->color;
            xPtr->color = ptr->color;
            ptr->color = color;

            comp++;
            if (ptr == root) {
                root = xPtr;
            } else {
                stack[ht - 1]->link[dir[ht - 1]] = xPtr;
            }

            dir[ht] = 1;
            stack[ht++] = xPtr;
        } else {
            i = ht++;
            while (1) {
                dir[ht] = 0;
                stack[ht++] = xPtr;
                yPtr = xPtr->link[0];
                if (!yPtr->link[0])
                    break;
                xPtr = yPtr;
            }

            dir[i] = 1;
            stack[i] = yPtr;
            comp++;
            if (i > 0)
                stack[i - 1]->link[dir[i - 1]] = yPtr;

            yPtr->link[0] = ptr->link[0];

            xPtr->link[0] = yPtr->link[1];
            yPtr->link[1] = ptr->link[1];

            comp++;
            if (ptr == root) {
                root = yPtr;
            }

            color = yPtr->color;
            yPtr->color = ptr->color;
            ptr->color = color;
        }
    }

    if (ht < 1)
        return;

    if (ptr->color == BLACK) {
        while (1) {
            pPtr = stack[ht - 1]->link[dir[ht - 1]];
            if (pPtr && pPtr->color == RED) {
                pPtr->color = BLACK;
                break;
            }

            if (ht < 2)
                break;

            if (dir[ht - 2] == 0) {
                rPtr = stack[ht - 1]->link[1];

                if (!rPtr)
                    break;

                if (rPtr->color == RED) {
                    stack[ht - 1]->color = RED;
                    rPtr->color = BLACK;
                    stack[ht - 1]->link[1] = rPtr->link[0];
                    rPtr->link[0] = stack[ht - 1];

                    if (stack[ht - 1] == root) {
                        root = rPtr;
                    } else {
                        stack[ht - 2]->link[dir[ht - 2]] = rPtr;
                    }
                    dir[ht] = 0;
                    stack[ht] = stack[ht - 1];
                    stack[ht - 1] = rPtr;
                    ht++;

                    rPtr = stack[ht - 1]->link[1];
                }

                if ((!rPtr->link[0] || rPtr->link[0]->color == BLACK) &&
                        (!rPtr->link[1] || rPtr->link[1]->color == BLACK)) {
                    rPtr->color = RED;
                } else {
                    if (!rPtr->link[1] || rPtr->link[1]->color == BLACK) {
                        qPtr = rPtr->link[0];
                        rPtr->color = RED;
                        qPtr->color = BLACK;
                        rPtr->link[0] = qPtr->link[1];
                        qPtr->link[1] = rPtr;
                        rPtr = stack[ht - 1]->link[1] = qPtr;
                    }
                    rPtr->color = stack[ht - 1]->color;
                    stack[ht - 1]->color = BLACK;
                    rPtr->link[1]->color = BLACK;
                    stack[ht - 1]->link[1] = rPtr->link[0];
                    rPtr->link[0] = stack[ht - 1];
                    if (stack[ht - 1] == root) {
                        root = rPtr;
                    } else {
                        stack[ht - 2]->link[dir[ht - 2]] = rPtr;
                    }
                    break;
                }
            } else {
                rPtr = stack[ht - 1]->link[0];
                if (!rPtr)
                    break;

                if (rPtr->color == RED) {
                    stack[ht - 1]->color = RED;
                    rPtr->color = BLACK;
                    stack[ht - 1]->link[0] = rPtr->link[1];
                    rPtr->link[1] = stack[ht - 1];

                    if (stack[ht - 1] == root) {
                        root = rPtr;
                    } else {
                        stack[ht - 2]->link[dir[ht - 2]] = rPtr;
                    }
                    dir[ht] = 1;
                    stack[ht] = stack[ht - 1];
                    stack[ht - 1] = rPtr;
                    ht++;

                    rPtr = stack[ht - 1]->link[0];
                }
                if ((!rPtr->link[0] || rPtr->link[0]->color == BLACK) &&
                        (!rPtr->link[1] || rPtr->link[1]->color == BLACK)) {
                    rPtr->color = RED;
                } else {
                    if (!rPtr->link[0] || rPtr->link[0]->color == BLACK) {
                        qPtr = rPtr->link[1];
                        rPtr->color = RED;
                        qPtr->color = BLACK;
                        rPtr->link[1] = qPtr->link[0];
                        qPtr->link[0] = rPtr;
                        rPtr = stack[ht - 1]->link[0] = qPtr;
                    }
                    rPtr->color = stack[ht - 1]->color;
                    stack[ht - 1]->color = BLACK;
                    rPtr->link[0]->color = BLACK;
                    stack[ht - 1]->link[0] = rPtr->link[1];
                    rPtr->link[1] = stack[ht - 1];
                    if (stack[ht - 1] == root) {
                        root = rPtr;
                    } else {
                        stack[ht - 2]->link[dir[ht - 2]] = rPtr;
                    }
                    break;
                }
            }
            ht--;
        }
    }
}

// Print the inorder traversal of the tree
void inorderTraversal(struct rbNode *node) {
    if (node) {
        inorderTraversal(node->link[0]);
        printf("%lld  ", node->data);
        inorderTraversal(node->link[1]);
    }
    return;
}

int multidelete(int termo) {
    int arr[10001];
    for (int i=0; i < 10400; i++) {
        arr[i] = 0;
        insertion(i);
    }
    comp = 0;
    for (int i=0; i < termo; i++) {
        int k = abs(randll() % 10001);
        if (!arr[k]) {
            printf("k -> %lld\n", k);
            deletion(k);
            arr[k]++;
        } else {
            i--;
            continue;
        }
    }
    return comp;
}

int multinsert(int termo) {
    comp = 0;
    for (int i = 1; i <= termo; i++) {
        int k = randll();
        insertion(k);
    }
    return comp;
}

// Driver code
int main() {
    srand(time(NULL));
    int ch, data;
    /* int k = multinsert(10000); */
    /* printf("k -> %lld\n", k); */
    int k = multidelete(9);
    printf("k -> %lld\n", k);
    return 0;
    while (1) {
        printf("1. Insertion\t2. Deletion\n");
        printf("3. Traverse\t4. Exit");
        printf("\nEnter your choice:");
        scanf("%lld", &ch);
        switch (ch) {
            case 1:
                printf("Enter the element to insert:");
                scanf("%lld", &data);
                insertion(data);
                break;
            case 2:
                printf("Enter the element to delete:");
                scanf("%lld", &data);
                deletion(data);
                break;
            case 3:
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Not available\n");
                break;
        }
        printf("\n");
    }
    return 0;
}
