#include <stdio.h>
#include <stdlib.h>

int htt = 1;

typedef struct node {
    int data;
    struct node *link;
} Node;

typedef struct head {
    int num;
    Node *link;
} Head;

void nodeNum(Node *location) {
    if ((location->data) != NULL) {
        Node *renode = malloc(sizeof(Node));
        renode->link = location->link;
        htt++;
        nodeNum(renode->link);
    }
    else if((location->data) == NULL) {
        printf("\nHead to tail : %d\n\n", htt);
    }
    else
        printf("Broken system\n");
}

void createNode(Head *rehead, int data) {
    Node *renode = malloc(sizeof(Node));
    renode->link = rehead->link;
    rehead->link = renode;
    renode->data = data;
    rehead->num++;
    printf("Create node : %d, %d\n", renode->data, rehead->num);
}

void deleteNode(Head *rehead) {
    Node *renode = malloc(sizeof(Node));
    renode = rehead->link;
    rehead->link = renode->link;
    printf("Delete node : %d\n", renode->data);
    free(renode);
}

int main(void)
{
    Head *rehead = malloc(sizeof(Head));
    rehead->num = 0;
    createNode(rehead, 0);
    createNode(rehead, 1);
    createNode(rehead, 2);
    createNode(rehead, 3);
    createNode(rehead, 4);

    nodeNum(rehead->link);

    deleteNode(rehead);
    deleteNode(rehead);
    deleteNode(rehead);
    deleteNode(rehead);
    deleteNode(rehead);

    return 0;
}