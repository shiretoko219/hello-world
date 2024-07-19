#include <stdlib.h>

#define LIST_SIZE 100

typedef struct {
    int integer[LIST_SIZE];
    int len;
}SqList, *ptr_SqList;


SqList* InitList(void);
int DestroyList(SqList* list);
int ListInsert(SqList *list, int value, int pos);
int ListDelete(SqList *list, int pos);
int GetItem(SqList *list, int pos);