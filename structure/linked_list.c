#include <stdio.h>
#include <stdlib.h>


typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode; // 뒤에 Type이 나오는게 최종

// ListNode *head = NULL; : 이 경우 이중포인터를 쓰게 되는 경우가 발생할수도

typedef struct {
    ListNode *head;
    ListNode *tail;
    int n;
} ListType;


void init(ListType *L) {
    L->head = NULL;
}

int isEmpty(ListType *L) {
    if(L->head == NULL) return 1;
    return 0;
}

void insertFirst(ListType *L, element e) {
    // node라는 이름의 변수는 새롭게 추가될 친구
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = e;
    node->link = L->head;

    L->head = node;
}

void insertLast(ListType *L, element e) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = e;
    node->link = NULL;

    ListNode *p = L->head; for(; p->link!=NULL; p=p->link);
    p->link = node;
}

void insert(ListType *L, int pos, element e) {
    if (pos == 1){
        insertFirst(L, e);
        return;
    }
    
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    ListNode *p = L->head; 
    
    for(int i=1; i<pos-1; i++) p = p->link;

    node->data = e;
    node->link = p->link;

    p->link = node;
}

void print(ListType *L) {
    if(isEmpty(L)){
        printf("Empty!\n");
        return;
    }

    // p, q, r이라는 이름의 변수는 무엇인가를 가리키는 친구

    ListNode *p = L->head;
    for(;p != NULL; p = p->link)
        printf("[%d] => ", p->data);
    printf("NULL\n");
}

element deleteFirst(ListType *L){
    ListNode *p = L->head;
    element e = p->data;
    L->head = p->link;
    free(p);
    
    return e;
}

element delete(ListType *L, int pos){
    ListNode *p = L->head;
    ListNode *prev;
    element e;
    
    if(pos == 1){
        e = deleteFirst(L);
    }else{
        for(int i=0; i<pos -1; i++){
            prev = p;
            p = p->link;
        }
        e = p->data;
        prev->link = p->link;
        free(p);
    }
    
    return e;
}

void partition(ListType *L, ListType *L1, ListType *L2, int pos){
    ListNode *p = L->head;

    L1->head = p;
    for(int i=1; i<pos; i++){
        p = p->link;
    }

    L2->head = p->link;

    p->link = NULL;
}

ListType* concat(ListType *L1, ListType *L2){
    ListNode *p = L1->head;
    ListNode *q = L2->head;
    if(p == NULL){
        p = q;
    } else{
        for(; p->link != NULL; p=p->link);
        p->link = q;
    }
}

int main() {
    ListType L;
    init(&L);
    
    insertFirst(&L, 10); print(&L);
    insertFirst(&L, 20); print(&L);
    insertFirst(&L, 30); print(&L);

    insertLast(&L, 40); print(&L);
    insertLast(&L, 50); print(&L);

    insert(&L, 1, 60); print(&L);
    insert(&L, 4, 70); print(&L);
    
    printf("[%d] is deleted. \n", deleteFirst(&L));
    print(&L);
    printf("[%d] is deleted. \n", delete(&L, 3));
    print(&L);
    
    ListType L1, L2;
    init(&L1); init(&L2);
    int pos;
    
    printf("Enter partition pos : ");
    scanf("%d", &pos);
    
    partition(&L, &L1, &L2, pos);
    
    print(&L1);
    print(&L2);
    
    printf("After concat. \n");

    concat(&L1, &L2);
    
    print(&L1);

    return 0;
}

























