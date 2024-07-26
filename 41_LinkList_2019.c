#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

void init_list(LinkList *L);
void list_tail_insert(LinkList L, int x);
void print_list(LinkList L);
void find_middle(LinkList L, LinkList M);
LinkList reverse(LinkList L);
LinkList merge(LinkList L, LinkList M);

int main(void) {
    LinkList L, M;
    int x;

    scanf("%d", &x);

    init_list(&L);
    init_list(&M);
    while(x != 9999){
        list_tail_insert(L, x);
        scanf("%d", &x);
    }
    printf("\n");
    print_list(L);
    find_middle(L,M);
    print_list(L);
    print_list(M);
    print_list( reverse(M));
    print_list(merge(L, M));



    return 0;
}

void init_list(LinkList *L) {  //二级指针的目的是避免分配的空间不出子函数
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
}

void list_tail_insert(LinkList L, int x) {
    LinkList q;

    q = (LinkList)malloc(sizeof(LNode));
    while(L->next != NULL){
        L = L->next;  //如果没到底，找到底为止
    }
    q->data = x;
    q->next = NULL;
    L->next = q;
}

void print_list(LinkList L) {
    L = L->next;

    while(L!=NULL) {
        printf("%d",L->data);
        L=L->next;
        if(L!=NULL){
            printf(" ");
        }
    }
    printf("\n");

}

void find_middle(LinkList L, LinkList M) {
    LinkList ppre, pcur;

    ppre = L->next;
    pcur = L->next;

    while (pcur != NULL) {
        pcur = pcur->next;  //pcur先走一步看看
        if (pcur == NULL) {  //如果到的是null，停，让ppre停在第一个链表的最后一个元素上
            break;  //好方便我对第一个链表L做null
        }
        if (pcur->next != NULL) {  //如果不是null，继续走pcur，然后移动ppre
            pcur = pcur->next;
            ppre = ppre->next;
        }else {  //如果pcur直接跳到null上，那一定是偶数个，且ppre停在第一个链表的最后一个元素上
            break;  //直接出循环
        }
    }

    M->next = ppre->next;  //把M头节点引导ppre->next上
    ppre->next = NULL;  //截断两个链表
}

LinkList reverse(LinkList L) {
    LinkList r, s, t;

    if (L == NULL) {
        return NULL;
    }
    if (L->next->next == NULL) {
        return NULL;
    }

    r = L->next;  //放置起始位置
    s = L->next->next;
    t = L->next->next->next;
    r->next = NULL;  //为结尾作准备

    while (t != NULL) {  //让s中的next指向t，然后指针均向后移1位
        s->next = r;
        r = s;
        s = t;
        t = t->next;
    }
    //此时t为null，s在倒数第一个节点，r在倒数第二个节点
    s->next = r; //让最后没完成的，倒数第一个节点指向倒数第二个，完成链表
    L->next = s;  //让头节点指向倒数第一个节点，使反转链表能够正常进入

    return L;
}

LinkList merge(LinkList L, LinkList M) {
    LinkList p, q, pcur;

    if (L == NULL||M == NULL) {
        return NULL;
    }
    p = L->next->next;
    q = M->next;
    pcur = L->next;  //部署初始位置

    while (p != NULL && q != NULL) {
        pcur->next = q;
        q = q->next;
        pcur = pcur->next;
        pcur->next = p;
        p = p->next;
        pcur = pcur->next;  //让pcur作为操作中心，p和q始终为各自链表的下一个
    }
    if (p == NULL) {  //判断两种多的情况
        pcur->next = q;
    }else {
        pcur->next = p;
    }

    free(M);  //释放M头节点
    M = NULL;
    return L;
}
