#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

void init_list(LinkList *L);
void list_head_insert(LinkList L, int x);
void list_tail_insert(LinkList L, int x);
void print_list(LinkList L);

int main(void) {
    LinkList L, M;
    int x;

    scanf("%d", &x);

    init_list(&L);
    while(x != 9999){
        list_head_insert(L, x);
        scanf("%d", &x);
    }
    scanf("\n");
    print_list(L);

    scanf("%d", &x);
    init_list(&M);
    while(x != 9999){
        list_tail_insert(M, x);
        scanf("%d", &x);
    }
    print_list(M);

    return 0;
}

void init_list(LinkList *L) {  //二级指针的目的是避免分配的空间不出子函数
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
}

void list_head_insert(LinkList L, int x) {
    LinkList q;
    q = (LinkList)malloc(sizeof(LNode));


    q->data = x;
    q->next = L->next;
    L->next = q;  //数据移入q，上个节点的next移入下个节点，并且将上个节点的指向修改
}

void list_tail_insert(LinkList L, int x) {
    LinkList p, q;
    p = (LinkList)malloc(sizeof(LNode));
    q = (LinkList)malloc(sizeof(LNode));

    p = L;
    while(p->next != NULL){
        p = p->next;  //如果没到底，找到底为止
    }
    q->data = x;
    q->next = NULL;
    p->next = q;
}

void print_list(LinkList L) {
    L=L->next;

    while(L!=NULL) {
        printf("%d",L->data);
        L=L->next;
        if(L!=NULL){
            printf(" ");
        }
    }
    printf("\n");

}