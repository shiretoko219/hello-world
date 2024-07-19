#include <stdio.h>
#include "SqList.h"

int main(void) {
    SqList* list;
    int tempValue;
    int tempPos;
    int status;

    list = InitList();
    status = ListInsert(list, 1, 1);
    status = ListInsert(list, 2, 2);
    status = ListInsert(list, 3, 3);

    scanf("%d\n%d", &tempValue, &tempPos);

    status = ListInsert(list, tempValue,2);
    for (int i = 0; i < list->len; i++) {
        printf("%2d",list->integer[i]);
    }
    printf("\n");

    status = ListDelete(list, tempPos);
    for (int i = 0; i < list->len; i++) {
        printf("%2d",list->integer[i]);
    }

    return 0;
}


