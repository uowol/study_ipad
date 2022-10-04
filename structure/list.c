nclude <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
typedef int element;

typedef struct
{
    element elem[SIZE];
    int size;
}ListType;


void init(ListType *L)
{
    L->size = 0;
}


int isEmpty(ListType *L)
{
    return L->size == 0;  
}

int isFull(ListType *L)
{
    return L->size == SIZE;
}

void insertLast(ListType *L, element e)
{
    if(isFull(L))
    {        
        printf("FULL.\n");
    }
    else
    {
        L->elem[L->size] = e;
        L->size++;
    }
}

void insert(ListType *L, int pos, element e){
    if(isFull(L)){        
        printf("FULL.\n");
    }else if(pos<0 || pos>L->size){
        printf("Invalid Pos.\n");
    }else{
        for(int i=(L->size-1); i>=pos; i--){
            L->elem[i+1] = L->elem[i];  // 꽉차면?
        }
        L->elem[pos] = e;
        L->size++;
    }
}

element delete(ListType *L, int pos){
    if(isEmpty(L)){
        printf("EMPTY.\n");
        return -1;
    }else if(pos<0 || pos>=L->size){
        printf("Invalid Pos.\n");
        return -1;
    }else{
        element e = L->elem[pos];
        for(int i=pos; i<(L->size -1); i++){
            L->elem[i] = L->elem[i+1];
        }
        L->size--;
        return e;
    }
}

void print(ListType *L)
{
    for(int i=0; i<L->size; i++){
        printf("[%d] ", L->elem[i]);
    }
    printf("\n");
}


int getCount(ListType *L)
{
    return L->size+1;
}

int main()
{
    ListType L;
    init(&L);
    
    insertLast(&L, 10); print(&L);
    insertLast(&L, 20); print(&L);
    insertLast(&L, 30); print(&L);

    insert(&L, 1, 40); print(&L);
    insert(&L, 0, 50); print(&L);
    insert(&L, 4, 60); print(&L);
    
    delete(&L, 1); print(&L);
    delete(&L, 3); print(&L);
    delete(&L, 4); print(&L);
    return 0;
}



