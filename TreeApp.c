#include <stdio.h>

typedef struct _node {
    char name;
    struct _node *left;
    struct _node *right;
} Node;

void fix(Node *newNode) {
    if ((newNode->name>=97) && (newNode->name<=122)) {
        printf("%c", newNode->name);
        return;
    }
    else {
        printf("(");
        fix(newNode->left);
        printf("%c", newNode->name);
        fix(newNode->right);
        printf(")");
    }
}

int main(void)
{
    Node A, B, C, D, E, F, G;
    A.name = '+';
    A.left = &B;
    A.right = &E;
    B.name = '*';
    E.name = 'd';

    B.left = &C;
    B.right = &D;
    D.left = &F;
    D.right = &G;
    C.name = 'a';
    D.name = '+';
    F.name = 'b';
    G.name = 'c';

    C.left = C.right = NULL;
    E.left = E.right = NULL;
    F.left = F.right = NULL;
    G.left = G.right = NULL;
    fix(&A);
    return 0;
}