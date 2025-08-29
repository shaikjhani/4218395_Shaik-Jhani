#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

void push(int *stack, int *top, int val) { stack[++(*top)] = val; }
int pop(int *stack, int *top) { return stack[(*top)--]; }
int isEmpty(int top) { return top == -1; }

void enqueue(int x) { push(s1, &top1, x); }

void shiftStacks() {
    if (isEmpty(top2)) {
        while (!isEmpty(top1))
            push(s2, &top2, pop(s1, &top1));
    }
}

void dequeue() { shiftStacks(); if (!isEmpty(top2)) pop(s2, &top2); }
void printFront() { shiftStacks(); if (!isEmpty(top2)) printf("%d\n", s2[top2]); }

int main() {
    int q, type, x;
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &type);
        if (type == 1) { scanf("%d", &x); enqueue(x); }
        else if (type == 2) dequeue();
        else if (type == 3) printFront();
    }
    return 0;
}
