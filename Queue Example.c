#include <stdio.h>
#define MAX_SIZE 100
int queue[MAX_SIZE];
int front = -1;
int rear = -1;


int isEmpty() {
    return front == -1 && rear == -1;
}

int isFull() {
    return rear == MAX_SIZE - 1;
}

void enqueue(int value) {
  
    if (isEmpty()) {
        front = 0;
    }

  
    if (isFull()) {
        printf("Queue is full. Cannot insert %d.\n", value);
        return;
    }

    
    rear++;
    queue[rear] = value;

    printf("Inserted %d into the queue.\n", value);
}


void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int numInsertions, value;

    printf("Enter how many times you want to insert data into the queue: ");
    scanf("%d", &numInsertions);

    for (int i = 0; i < numInsertions; i++) {
        printf("Enter a value to insert into the queue: ");
        scanf("%d", &value);
        enqueue(value);
    }

    displayQueue();

    return 0;
}
