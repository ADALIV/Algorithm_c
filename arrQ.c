#include <stdio.h>

int q[100];
int front = 0;
int rear = 0;

void enq(int n) {
    if (rear == 0) {
        q[front] = n;
        rear++;
    }
    else {
        q[rear] = n;
        rear++;
    }
}

int deq() {
    int num = q[front];
    front++;
    if (front >= rear) front=rear=-1;
    return num;
}

int main(void)
{
    enq(1);
    enq(2);
    enq(3);
    enq(4);

    printf("%d", deq());
    printf("%d", deq());
    printf("%d", deq());
    printf("%d", deq());

    return 0;
}