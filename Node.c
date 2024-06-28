#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    char data;
    struct _node *link;
} Node;

typedef struct _head {
    int count;
    Node *top;
} Head;

Head *createStack() {
    Head *head = malloc(sizeof(Head));
    head->count = 0;
    head->top = NULL;
    return head;
}

void push(Head *_head, char _c) {
    Node *node = malloc(sizeof(Node));
    node->data = _c;
    node->link = _head->top;

    _head->top = node;
    (_head->count)++;

    printf("%c\n", node->data);
}

char pop(Head *_head) {
    Node *node = _head->top;
    _head->top = node->link;

    //헤드 뒤의 노드를 죽이기 위해 새로운 노드 포인터가 헤드 뒤의 기존 노드로 해주고 팝 과정 실시

    printf("%c\n", node->data);
    (_head->count)--;
    return node->data;
}

void top(Head *_head)
{
    if (_head->top == NULL) {
        printf("\nEmpty stack\n\n");
    }
    else {
        Node *node = malloc(sizeof(Node));
        node = _head->top;

        printf("\nSuccess to data out : %c\n\n", node->data);
    }
}

void destack(Head *_head)
{
    int num = _head->count;

    for (num; num>0; num--) {
        Node *node = malloc(sizeof(Node));
        node = _head->top;
        _head->top = node->link;

        free(node);
        printf("\nSuccess to free stack\n");
    }
}

int main(void)
{
    Head *head = createStack();

    printf("---push test---\n");
    push(head, 'a');
    push(head, 'b');
    push(head, 'c');
    top(head);

    printf("---pop test---\n");
    pop(head);
    pop(head);
    pop(head);
    top(head);

    printf("---destroy test---\n");
    push(head, 'a');
    push(head, 'b');
    push(head, 'c');
    destack(head);
    top(head);

    return 0;
}