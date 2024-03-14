#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}
 
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}
 
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1); 
    }
    return stack->arr[stack->top--];
}

void enqueue(struct Stack *stack1, struct Stack *stack2, int value) {
    while (!isEmpty(stack1)) {
        push(stack2, pop(stack1));
    }

    push(stack1, value);
 
    while (!isEmpty(stack2)) {
        push(stack1, pop(stack2));
    }
}
int dequeue(struct Stack *stack1) {
    if (isEmpty(stack1)) {
        printf("Queue underflow\n");
        exit(1);
    }
    return pop(stack1);
}
int main() {
    struct Stack stack1, stack2;
    initialize(&stack1);
    initialize(&stack2);

    enqueue(&stack1, &stack2, 5);
    enqueue(&stack1, &stack2, 2);
    enqueue(&stack1, &stack2, 3);

    printf("Dequeued element: %d\n", dequeue(&stack1));
    printf("Dequeued element: %d\n", dequeue(&stack1));
    return 0;
}
