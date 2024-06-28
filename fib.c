#include <stdio.h>

int fib(int num)
{
    if (num==0) return 0;
    if (num==1) return 1;
    return (fib(num-1)+fib(num-2));
}

int main(void)
{
    int num;
    printf("Input num : ");
    scanf("%d", &num);

    int value;
    value = fib(num);

    printf("%d", value);
    return 0;
}