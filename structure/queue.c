#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

typedef struct
{
    char data[SIZE];
    int front, rear;
}QueueType;

void init(QueueType *Q)
{
    Q->front = Q->rear = -1;
}

int isEmpty(QueueType *Q)
{
    return Q->rear == Q->front;   
}

int isFull(QueueType *Q)
{
    return Q->rear == SIZE - 1;
}

void enqueue(QueueType *Q, char e)
{
    if(isFull(Q))
	{
	    printf("Full.\n");
        return;
    }
    Q->rear++;
    Q->data[Q->rear] = e;
}

char dequeue(QueueType *Q)
{
    if(isEmpty(Q))
    {
        printf("Empty.\n");
        return 0;
    }
    Q->front++;
    return Q->data[Q->front];
}

void print(QueueType *Q)
{
    printf("Front pos : %d, Rear pos : %d\n", Q->front, Q->rear);
	if(!isEmpty(Q))
	{
        for(int i = Q->front + 1; i <= Q->rear; i++)
            printf("[%c] ", Q->data[i]);
	    printf("\n");    
    }
}

int main()
{
    QueueType Q;
    init(&Q);
    srand(time(NULL));
    for(int i = 0; i < 7; i++)
	    enqueue(&Q, rand() % 26 + 65);
	print(&Q); getchar();   
    for(int i = 0; i < 3; i++)
        printf("[%c] ", dequeue(&Q));
    printf("\n\n");    
    print(&Q); getchar();		
    for(int i = 0; i < 5; i++)
        enqueue(&Q, rand() % 26 + 65);
    print(&Q); getchar();					    
    for(int i = 0; i < 3; i++)
		printf("[%c] ", dequeue(&Q));
	printf("\n\n");    
	print(&Q);											    
	return 0;
}

