#include <stdio.h>

int cost;

void hanoi(int n, char a, char b, char c)
{
    //a as "from", b as "by", c as "to"
    if (n==1) {
        //printf("%dstack %c ---> %c\n", 1, a, c);
        cost++;
    }
    else if (n<1) {
        return;
    }
    else {
        hanoi(n-1, a, c, b);
        //printf("%dstack %c ---> %c\n", n, a, c);
        hanoi(n-1, b, a, c);
        cost+=n;
    }
}

int main(void)
{
    int times;

    FILE *fp1 = fopen("input_hw1.txt", "r");
    FILE *fp2 = fopen("output.txt", "w");

    if (fp1==NULL) printf("Fail to open file 1...");
    if (fp2==NULL) printf("Fail to open file 2...");

    fseek(fp1, 0, SEEK_SET);
    fscanf(fp1, "%d", &times);

    for (int i=0; i<times; i++) {
        int numStack;
        cost = 0;

        fseek(fp1, 2, SEEK_CUR);
        fscanf(fp1, "%d", &numStack);
        //printf("%d\n", numStack); //정상 작동

        hanoi(numStack, 'a', 'b', 'c');
        fprintf(fp2, "%d\n", cost);
        //printf("%d\n", cost); //정상 작동
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}

//수학적 방법
//T1 = 1
//T2 = 2*T1 + 1
//T3 = 2*(2*T1 + 1) + 1
//Tn = 2^n - 1