#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *link;
} Node;

typedef struct head {
    Node *front;
    int num;
    Node *rear;
} Head;

void Enqueue(Head *head, int value) {
    Node *node = malloc(sizeof(Node));
    Node *temp = malloc(sizeof(Node));
    node->value = value;
    if (head->front == NULL) {
        head->front = node;
        head->rear = node;
    }
    temp = head->rear;
    temp->link = node;
    head->rear = node;
    head->num++;
    printf("Saved value : %d, %d\n", node->value, head->num);
}

void Dequeue(Head *head) {
    Node *node = malloc(sizeof(Node));
    node = head->front;
    head->front = node->link;
    head->num--;
    printf("Deleted value : %d, %d\n", node->value, head->num);
    free(node);
}

int main(void)
{
    Head *head = malloc(sizeof(Head));
    head->num = 0;
    head->front = NULL;
    head->rear = NULL;

    Enqueue(head, 1);
    Enqueue(head, 2);
    Enqueue(head, 3);
    Enqueue(head, 4);

    Dequeue(head);
    Dequeue(head);
    Dequeue(head);
    Dequeue(head);

    return 0;
}