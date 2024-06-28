#include <stdio.h>

typedef struct _node {
    char name;
    struct _node *left, *right;
} Node;

Node *stack[100];
int top = -1;

void postOrder1(Node *root) {
    if (root == NULL) {
        return;
    }
    postOrder1(root->left);
    postOrder1(root->right);
    //(*root).left 가능
    printf("%c --> ", root->name);
}

void push(Node *n) {
    stack[++top] = n;
}
Node *pop() {
    Node *node = stack[top--];
    return node;
}
void preOrder2(Node *node) {
    if (node == NULL) return;
    push(node);
    while (top != -1) {
        node = pop();
        printf("%c --> ", node->name);
        if (node->right != NULL) {
            push(node->right);
        }
        if (node->left != NULL) {
            push(node->left);
        }
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

    postOrder1(&A);
    printf("\n");
    preOrder2(&A);
    return 0;
}