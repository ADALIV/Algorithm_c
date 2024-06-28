#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int val;
    struct _node *link;
} Node;

typedef struct _head {
    int num;
    Node *link;
} Head;

void showLL(Head *head) {
    Node *node = malloc(sizeof(Node));
    Node *temp = malloc(sizeof(Node));

    if (head->link == NULL) printf("No list\n");
    else {
        node = head->link;
        for (int i=1; i<=head->num; i++) {
            printf("%d list, number is %d\n", i, node->val);
            if (node->link == NULL) break;
            temp = node;
            node = temp->link;
        }
    }
}

void insert(Head *head) {
    showLL(head);
    int where;
    int insnum;
    printf("Where do you want to insert? >> ");
    scanf("%d", &where);
    printf("Input num >> ");
    scanf("%d", &insnum);

    Node *node = malloc(sizeof(Node));
    Node *temp = malloc(sizeof(Node));
    Node *insnode = malloc(sizeof(Node));
    //No list
    if (where == 1) {
        node = head->link;
        insnode->link = node;
        head->link = insnode;
        insnode->val = insnum;
        head->num++;
    }
    //One node
    else if (where == 2) {
        node = head->link;
        temp = node;
        node = temp->link;
        insnode->link = node;
        temp->link = insnode;
        insnode->val = insnum;
        head->num++;
    }
    //End of the list
    else if (where > head->num) {
        node = head->link;
        for (int i=1; i<where; i++) {
            if (node->link == NULL) {
                break;
            }
            temp = node;
            node = temp->link;
        }
        node->link = insnode;
        insnode->val = insnum;
        head->num++;
    }
    //Middle of the list
    else {
        node = head->link;
        for (int i=1; i<where; i++) {
            temp = node;
            node = temp->link;
        }
        insnode->link = node;
        temp->link = insnode;
        insnode->val = insnum;
        head->num++;
    }
}

void delete(Head *head) {
    showLL(head);
    int where;
    printf("Where do you want to delete? >> ");
    scanf("%d", &where);

    Node *node = malloc(sizeof(Node));
    Node *temp = malloc(sizeof(Node));
    Node *delnode = malloc(sizeof(Node));
    node = head->link;
    //First list
    if (where == 1) {
        head->link = node->link;
        if (node->link == NULL) {
            head->link = NULL;
        }
        head->num--;
        free(node);
    }
    //Other list
    else {
        for (int i=1; i<where; i++) {
        temp = node;
        node = temp->link;
        }
        delnode = node;
        temp->link = delnode->link;
        free(delnode);
        free(node);
        head->num--;
    }
}

int main(void)
{
    Head *head = malloc(sizeof(Head));
    head->num = 0;
    head->link = NULL;

    while (1) {
        int num;
        printf("1 >> insert  /  2 >> delete\n");
        printf("Choose number : ");
        scanf("%d", &num);
        if (num < 0) break;
        else if (num == 1) {
            insert(head);
        }
        else if (num == 2) {
            delete(head);
        }
        else printf("Wrong input\n");
    }
    return 0;
}