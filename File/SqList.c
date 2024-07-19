#include "SqList.h"

#include <stdio.h>

SqList* InitList(void) {
    SqList *list;
    list = (SqList *)malloc(sizeof(SqList));  //给顺序表分配一块地址空间
    list->len = 0;

    return list;  //返回第一个地址，供使用
}

int DestroyList(SqList* list) { //销毁指定顺序表
    if (list == NULL) {
        return -1;
    }
    free(list);
    list = NULL;
    return 0;
}

int ListInsert(SqList *list, int value, int pos) {
    //入参三个，list哪个表；value插入值；pos欲插入位置
    if (list == NULL) {
        return -1;
    }
    if (pos < 1 || pos > list->len+1) { //检查位置合法性
        return -1;
    }

    if (list->len+1 > LIST_SIZE) {
        return -1;
    }

    for (int i = list->len; i >= pos; i--) {
        list->integer[i] = list->integer[i-1];
    }
    list->integer[pos-1] = value;
    list->len++;
    return 0;
}

int ListDelete(SqList *list, int pos) { //入参两个，list哪个表；pos欲删除位置

    if (list == NULL) {
        return -1;
    }

    if (pos < 1 || pos > list->len) { //检查下标是否合法
        return -1;
    }

    for (int i = pos; i <= list->len; i++) {
        list->integer[i-1]  = list->integer[i];
    }
    list->len--;
    return 0;
}

int GetItem(SqList *list, int pos) {
    int num;

    if(pos < 1||pos > list->len) { //检查下标是否合法
        return -1;
    }

    num = *(list->integer+pos-1);
    return num;
}


