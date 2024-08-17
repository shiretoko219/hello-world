#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Elemtype int

typedef struct {
    Elemtype *elem;
    int len;
}SSTable;

void swap(int *a, int *b);
void bubble_sort(Elemtype *elem, int len);
int partition(Elemtype *elem, int lo, int hi);
void quick_sort(Elemtype *elem, int lo, int hi);
void insert_sort(Elemtype *arr, int len);
void print_table(SSTable T);
void destroy_table(SSTable *T);

int main(void) {
    SSTable T;
    int temp;
    Elemtype org_arr[10];

    T.elem = (Elemtype*)calloc(10,sizeof(Elemtype));
    T.len = 10;
    if (T.elem == NULL) {
        exit(1);
    }
    for (int i = 0; i < T.len; i++) {
        scanf("%3d", &T.elem[i]);
    }

    memcpy(org_arr, T.elem,T.len * sizeof(Elemtype));

    bubble_sort(T.elem,10);
    print_table(T);

    memcpy(T.elem,org_arr,T.len * sizeof(Elemtype));
    quick_sort(T.elem,0,9);
    print_table(T);

    memcpy(T.elem,org_arr,T.len * sizeof(Elemtype));
    insert_sort(T.elem,10);
    print_table(T);
    printf("\n");
    destroy_table(&T);
    return 0;
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(Elemtype *elem, int len) {
    int flag;  //本来是想和他讲的一样用bool，但是我感觉!flag看着顺眼

    for (int i = 0; i < len-1; i++) {
        flag = 0;
        for (int j = len-1; j > i; j--) {
            if (elem[j-1] > elem[j]) {
                swap(&elem[j-1],&elem[j]);
                flag++;
            }
        }
        if (!flag) {
            break;
        }
    }
}

int partition(Elemtype *elem, int lo, int hi) {
    Elemtype pi = elem[lo];

    while (lo < hi) {
        while (lo < hi && elem[hi] >= pi) {
            hi--;
        }
        elem[lo] = elem[hi];
        while (lo < hi && elem[lo] <= pi) {
            lo++;
        }
        elem[hi] = elem[lo];
    }
    elem[lo] =pi;
    return lo;
}

void quick_sort(Elemtype *elem, int lo, int hi) {
    if (lo < hi) {
        Elemtype pi = partition(elem, lo, hi);
        quick_sort(elem, lo, pi-1);
        quick_sort(elem, pi+1,hi);
    }
}

void insert_sort(Elemtype *arr, int len) {
    int insert_val, i, j;

    for (i = 1; i < len; i++) {
        insert_val = arr[i];
        for (j = i-1; j >= 0 && insert_val<arr[j]; j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = insert_val;
    }
}

void print_table(SSTable T) {
    for (int i = 0; i < T.len; i++) {
        printf("%3d", T.elem[i]);
    }
    printf("\n");
}

void destroy_table(SSTable *T) {
    free(T->elem);
    T->elem = NULL;
}
