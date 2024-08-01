#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct QNode {
    int data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

void init_queue(LinkQueue *Q);
bool is_full(LinkQueue Q);
bool is_empty(LinkQueue Q);
bool Enqueue(LinkQueue *Q, int num);
QueuePtr Dequeue(LinkQueue *Q);
void print_queue(LinkQueue Q);

int main(void) {
    LinkQueue Q;
    /*
    test code here
    */
    return 0;
}

void init_queue(LinkQueue *Q) {
    Q->front = (QueuePtr)malloc(sizeof(QNode));

    if (Q->front == NULL) {
        perror("Memory allocation failed!");
        exit(1);
    }

    Q->rear = Q->front;
    Q->rear->next = Q->front;
}

bool is_full(LinkQueue Q) {
    if (Q.rear->next == Q.front) {
        return true;
    }
    return false;
}

bool is_empty(LinkQueue Q) {
    if (Q.front == Q.rear) {
        return true;
    }
    return false;
}

bool Enqueue(LinkQueue *Q, int num) {
    if (is_full(*Q)) {
        QueuePtr new = (QueuePtr)malloc(sizeof(QNode));
        if (new == NULL) {
            return false;
        }
        Q->rear->data = num;
        Q->rear->next = new;
        new->next = Q->front;
        Q->rear = new;
        return true;
    }

    Q->rear->data = num;
    Q->rear = Q->rear->next;
    return true;
}

QueuePtr Dequeue(LinkQueue *Q) {
    QueuePtr temp;

    if (is_empty(*Q)) {
        printf("This queue is empty now! NULL Pointer will be returned.");
        return NULL;
    }
    temp = Q->front;
    Q->front = Q->front->next;
    return temp;
}

void print_queue(LinkQueue Q) {
    QueuePtr mark = Q.front;
    printf("%d ", mark->data);
    mark = mark->next;
    while (mark != Q.front) {
        printf("%d ", mark->data);
        mark = mark->next;
    }
    printf("\n");
}
