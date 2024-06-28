#include <stdio.h>

typedef struct _node {
    char name;
    struct _node *left, *right;
} Node;

Node *q[100];
int front = -1;
int rear = -1;

void enq(Node *newNode) {
    if (front == -1) {
        front++;
    }
    q[++rear] = newNode;
}
Node *deq() {
    Node *r = q[front++];
    if (front > rear) {
        front = rear = -1;
    }
    return r;
}

void BFT(Node *node) {
    Node *current;
    current = node;
    while (current != NULL) {
        printf("%c --> ", current->name);
        if (current->left != NULL) {
            enq(current->left);
        }
        if (current->right != NULL) {
            enq(current->right);
        }
        if (front != -1) {
            current = deq();
        }
        else current = NULL;
    }
}

int main(void)
{
    Node A, B, C, D, E, F;
    A.name = 'a';
    A.left = &B;
    A.right = &E;
    B.name = 'b';
    E.name = 'e';

    B.left = &C;
    B.right = &D;
    E.right = &F;
    C.name = 'c';
    D.name = 'd';
    F.name = 'f';

    C.left = C.right = NULL;
    D.left = D.right = NULL;
    F.left = F.right = NULL;
    E.left = NULL;
    BFT(&A);

    return 0;
}