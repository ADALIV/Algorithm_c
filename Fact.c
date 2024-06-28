#include <stdio.h>

int fact(int num)
{
    if (num==0) {
        return 1;
    }
    else
        return num*fact(num-1);
}

int main(void)
{
    int num;
    int factnum;
    printf("Input num : ");
    scanf("%d", &num);

    factnum = fact(num);
    printf("%d", factnum);
    return 0;
}