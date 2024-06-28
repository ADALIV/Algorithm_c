#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    int val;
    struct _node * left;
    struct _node * right;
} Node;

int num = 0;
int count = 0;
int cnt = 0;
Node *q[200];
int front = -1;
int rear = -1;

void enq(Node *newNode) {
    if (front == -1) {
        front++;
    }
    q[++rear] = newNode;
}
Node *deq() {
    Node *delNode = q[front++];
    if (front > rear) {
        front = rear = -1;
    }
    return delNode;
}

int * printNum(char line[]) {
    static int num_list[100];
    char * s;
    cnt = 0;
    for (s=strtok(line, " "); s; s=strtok(NULL, " "), cnt++) {
        if (sscanf(s, "%d", &num_list[cnt]) < 1) {
            break;
        }
    }
    return num_list;
}

void createTree(Node * root, int new) {
    if (root->val < new) {
        if (root->right == NULL) {
            Node * newNode = malloc(sizeof(Node));
            newNode->val = new;
            newNode->left = NULL;
            newNode->right = NULL;
            root->right = newNode;
            //printf("%d", newNode->val);
            return;
        }
        else return createTree(root->right, new);
    }
    else if (root->val > new) {
        if (root->left == NULL) {
            Node * newNode = malloc(sizeof(Node));
            newNode->val = new;
            newNode->left = NULL;
            newNode->right = NULL;
            root->left = newNode;
            //printf("%d", newNode->val);
            return;
        }
        else return createTree(root->left, new);
    }
    else {
        printf("Error");
        return;
    }
}

void BFScal(Node * root) {
    Node *current;
    current = root;
    while (current != NULL) {
        if (count < 1) break;
        num += current->val;
        //printf("%d ", num);
        count--;
        if (current->left != NULL) {
            enq(current->left);
        }
        if (current->right != NULL) {
            enq(current->right);
        }
        if (front != -1) {
            current = deq();
        }
        else current = NULL;
    }
    front = rear = -1;
    return;
}
void BFS(int num_list[]) {
    num = 0;
    //create tree
    Node * root = malloc(sizeof(Node));
    root->val = num_list[0];
    root->left = NULL;
    root->right = NULL;
    for (int i=1; i<cnt; i++) {
        createTree(root, num_list[i]);
    }
    //BFS
    BFScal(root);
}

void DFScal(Node * root) {
    if (count < 1) return;
    if (root != NULL) {
        num += root->val;
        //printf("%d ", num);
        count--;
        DFScal(root->left);
        DFScal(root->right);
    }
    else return;
}
void DFS(int num_list[]) {
    num = 0;
    //create tree
    Node * root = malloc(sizeof(Node));
    root->val = num_list[0];
    root->left = NULL;
    root->right = NULL;
    for (int i=1; i<cnt; i++) {
        createTree(root, num_list[i]);
    }
    //DFS
    DFScal(root);
}

int main(void)
{
    int cases;

    FILE *fp1 = fopen("hw3_input.txt", "rt");
    FILE *fp2 = fopen("output.txt", "wt");

    if (fp1==NULL) printf("Fail to open file 1...");
    if (fp2==NULL) printf("Fail to open file 2...");

    fseek(fp1, 0, SEEK_SET);
    fscanf(fp1, "%d", &cases);
    fseek(fp1, 2, SEEK_CUR);
    //printf("%d\n", cases);

    while(cases > 0) {
        char line_1[200];
        char line_2[200];
        int* num_list;
        fgets(line_1, sizeof(line_1), fp1);
        fgets(line_2, sizeof(line_2), fp1);

        char *ptr = strtok(line_1, " ");
        ptr = strtok(NULL, " ");
        count = atoi(ptr);
        //printf("%d\n", count);
        num_list = printNum(line_2);

        //for (int i=0; i<cnt; i++) {
        //    printf("%d\n", num_list[i]);
        //}

        if (strstr(line_1, "BFS") != NULL) {
            BFS(num_list);
        }
        else if (strstr(line_1, "DFS") != NULL) {
            DFS(num_list);
        }
        else {
            printf("Error");
            break;
        }
        fprintf(fp2, "%d", num);
        fputc('\n', fp2);
        cases--;
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}