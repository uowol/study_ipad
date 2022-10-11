nclude <stdio.h>
#include <stdlib.h>


typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode; // 뒤에 Type이 나오는게 최종

// ListNode *head = NULL; : 이 경우 이중포인터를 쓰게 되는 경우가 발생할수도

typedef struct {
    ListNode *tail;
} ListType;

void init(ListType *L) {
    L->tail = NULL;
}

int isEmpty(ListType *L) {
    return (L->tail == NULL);
}

void insertFirst(ListType *L, element e){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = e;

    // 빈 리스트일 때
    if(L->tail == NULL){
        L->tail = node;
        node->link = L->tail;   // 처음이자 마지막 노드
    }

    // 그렇지 않을 때
    else{
        node->link = L->tail->link;
        L->tail->link = node;
    }
}

void insertLast(ListType *L, element e) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = e;
    node->link = (L->tail)->link;

    if(L->tail == NULL){
        L->tail = node;
        node->link = L->tail;
    }
    else{
        L->tail->link = node;
        L->tail = node;
    }
}

void print(ListType *L) {
    ListNode *p = L->tail;
    if(p==NULL) return;
    
    do{
        printf("[%d] ", p->link->data);
        p = p->link;
    } while(p != L->tail);
    
}

int main() {
    ListType L; 
    init(&L);

    insertLast(&L, 10); print(&L);
    insertLast(&L, 20); print(&L);
    insertLast(&L, 30); print(&L);

    insertLast(&L, 40); print(&L);
    insertLast(&L, 50); print(&L);
    insertLast(&L, 60); print(&L);


    return 0;
}


























