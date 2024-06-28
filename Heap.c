#include <stdio.h>

int heap[100]; //max-heap
int last_idx = -1;

//insert node
void reheapUp(int current_idx) {
    if (current_idx == 0) return;
    int parent_idx = (current_idx -1)/2;
    if (heap[current_idx] > heap[parent_idx]) {
        int tmp = heap[current_idx];
        heap[current_idx] = heap[parent_idx];
        heap[parent_idx] = tmp;
        reheapUp(parent_idx);
    }
}
void ins(int val) {
    heap[++last_idx]  = val;
    reheapUp(last_idx);
}

//delete node
void reheapDown(int current_idx) {
    int left_idx = (current_idx * 2 + 1);
    int right_idx = (current_idx * 2 + 2);
    if (left_idx > last_idx) return;
    int largest_idx = left_idx;
    if (right_idx <= last_idx && heap[left_idx] < heap[right_idx]) largest_idx = right_idx;
    if (heap[largest_idx] > heap[current_idx]) {
        int tmp = heap[largest_idx];
        heap[largest_idx] = heap[current_idx];
        heap[current_idx] = tmp;
        reheapDown(largest_idx);
    }
}
int del() {
    int ret = heap[0];
    heap[0] = heap[last_idx--];
    reheapDown(0); //0 = root node index
    return ret;
}

int main(void)
{
    ins(8);
    ins(19);
    ins(23);
    ins(34);
    ins(45);
    ins(56);
    ins(78);

    for (int i=0; i<7; i++) {
        printf("%d--->", del());
    }

    return 0;
}