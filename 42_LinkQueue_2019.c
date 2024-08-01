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
    QueuePtr ptr = (QueuePtr)malloc(sizeof(QNode));

    if (ptr == NULL) {
        perror("Memory allocation failed!");
        exit(1);
    }

    Q->front = ptr;
    Q->rear = ptr;
}

bool is_full(LinkQueue Q) {
    if (Q.front == Q.rear->next) {
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
        new->data = num;
        Q->rear->next = new;
        new->next = Q->front;
        return true;
    }

    Q->rear = Q->rear->next;
    Q->rear->data = num;
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