#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * infix(int len, char line[]) {
    char operators[len];
    static char post[200];
    int op = 0;
    int po = 0;
    //location of operators and post

    for (int i=0; i<len; i++) {
        switch (line[i]) {
        case ('+'):
        //'*', '/' - in operators, then pop all
            while (1) {
                if ((operators[op-1] == '*') || (operators[op-1] == '/')) {
                    post[po] = operators[op-1];
                    po++;
                    op--;
                } else {
                    operators[op] = line[i];
                    op++;
                    break;
                }
            }
            break;
        case ('-'):
        //'*', '/' - in operators, then pop all
            while (1) {
                if ((operators[op-1] == '*') || (operators[op-1] == '/')) {
                    post[po] = operators[op-1];
                    po++;
                    op--;
                } else {
                    operators[op] = line[i];
                    op++;
                    break;
                }
            }
            break;
        case ('*'):
        //push
            operators[op] = line[i];
            op++;
            break;
        case ('/'):
        //push
            operators[op] = line[i];
            op++;
            break;
        case ('('):
        //push
            operators[op] = line[i];
            op++;
            break;
        case (')'):
        //pop to post
            for (int i=op-1; i>=0; i--) {
                if ((operators[i] != '(') && (operators[i] != ')')) {
                    post[po] = operators[i];
                    po++;
                }
                if (operators[i] == '(') {
                    op = i;
                    break;
                }
            }
            break;
        default:
        //operands
            post[po] = line[i];
            po++;
        }
    }
    
    for (int i=op-1; i>=0; i--) {
        if ((operators[i] != '(') && (operators[i] != ')')) {
            post[po] = operators[i];
            po++;
        }
    }
    return post;
}

int main(void)
{
    int times;
    char *postfix;
    char line[200];
    int operands;

    FILE *fp1 = fopen("input_hw2.txt", "rt");
    FILE *fp2 = fopen("output.txt", "wt");

    if (fp1==NULL) printf("Fail to open file 1...");
    if (fp2==NULL) printf("Fail to open file 2...");

    fseek(fp1, 0, SEEK_SET);
    fscanf(fp1, "%d", &times);
    fseek(fp1, 2, SEEK_CUR);

    while (times>0) {

        fscanf(fp1, "%d", &operands);
        fseek(fp1, 2, SEEK_CUR);
        fgets(line, sizeof(line), fp1);
        //printf("%d\n", times);
        //printf("%d\n", operands);
        //printf("%s\n", line);
        //No error

        postfix = infix(strlen(line), line);
        for (int i=0; i<operands*2-1; i++) {
            fputc(postfix[i], fp2);
        }
        free(postfix);
        fputc('\n', fp2);
        times = times-2;
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}