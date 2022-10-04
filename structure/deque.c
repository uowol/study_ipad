#include <stdio.h>

#include <stdlib.h>

#include <time.h>


#define SIZE 10


typedef struct
{
    char data[SIZE];

    int front, rear;

}DequeType;


void init(DequeType *D)

{

    D->front = 0;
    D->rear = 0;
}


int isEmpty(DequeType *D)

{

    return D->rear == D->front;  

}


int isFull(DequeType *D)

{

    return D->front == (D -> rear + 1) % SIZE ;

}

void addFront(DequeType *D, char e)
{
    if(isFull(D))
    {        
        printf("FULL.\n");
        return ;
    }
    else
    {
        D->data[D->front] = e;
        D->front = (D -> front - 1 + SIZE) % SIZE;
    }

}

void addRear(DequeType *D, char e)

{
    if(isFull(D))

    {

        printf("Full.\n");

        return;

    }else{
        D->rear = (D -> rear + 1) % SIZE;
        D->data[D->rear] = e;
    }


}
char deleteNear(DequeType *D)
{
    if(isEmpty(D))
    {
        printf("Empty.\n");
        return 0;
    }
    char e = D->data[D->rear];

    D->rear = (D->rear -1 + SIZE) % SIZE;
    return e;
}

char deleteFront(DequeType *D)
{
    if(isEmpty(D))
    {
        printf("Empty.\n");
        return 0;
    }

    D->front = (D->front + 1) % SIZE;
    char e = D->data[D->front];
    return e;
}

char getFront(DequeType *D)
{
    if(isEmpty(D))
    {
        printf("Empty.\n");
        return 0;
    }
    return D->data[(D->front + 1) % SIZE];
}

void print(DequeType *D)
{
    printf("Front Pos : %d, Rear Pos : %d\n", D->front, D->rear);
    int i = D->front;
    while(i != D->rear)
    {
        i = (i + 1) % SIZE;
        printf("[%c] ", D->data[i]);
    }
    printf("\n");    
}


int getCount(DequeType *D)
{
    int count = D->rear - D->front;
    if(count < 0){
        count += SIZE;
    } 
    return count;
}

int main()
{
    DequeType D;
    init(&D);
    srand(time(NULL));

    for(int i = 0; i < 5; i++)
        addRear(&D, rand() % 26 + 65);
    print(&D); getchar();

    for(int i = 0; i < 4; i++)
        addFront(&D, rand() % 26 + 65);
    print(&D); getchar();

    for(int i = 0; i < 3; i++)
        printf("[%c] ", deleteFront(&D));
    printf("\n\n");
    print(&D); getchar();

    for(int i = 0; i < 2; i++)
        printf("[%c] ", deleteNear(&D));
    printf("\n\n");
    print(&D); getchar();

    for(int i = 0; i < 6; i++)
        addRear(&D, rand() % 26 + 65);
    print(&D); getchar();

    for(int i = 0; i < 3; i++)
        printf("[%c] ", deleteFront(&D));
    printf("\n\n");
    print(&D);

    printf("[%c] ", getFront(&D));
    print(&D); getchar();
    return 0;
}



