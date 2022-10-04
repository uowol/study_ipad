#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

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
    return Q->front == (Q->rear + 1) % SIZE;
}

void enqueue(QueueType *Q, char e)
{
    if(isFull(Q))
	{
	    printf("Full.\n");
        return;
    }
    Q->rear = (Q->rear + 1)%SIZE;
    Q->data[Q->rear] = e;
}

char dequeue(QueueType *Q)
{
    if(isEmpty(Q))
    {
        printf("Empty.\n");
        return 0;
    }
    Q->front = (Q->front+1)%SIZE;
    return Q->data[Q->front];
}

char peek(QueueType *Q){
	if(isEmpty(Q)){
		printf("Empty!\n");
		return 0;
	}
	return Q->data[(Q->front+1)%SIZE];
}

void print(QueueType *Q)
{
    printf("Front pos : %d, Rear pos : %d\n", Q->front, Q->rear);
	int i = Q->front;
	while(i!=Q->rear){
		i = (i+1)%SIZE;
		printf("[%c]", Q->data[i]);
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

