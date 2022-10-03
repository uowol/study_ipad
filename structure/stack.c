#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct
{
    char data[SIZE];
    int top;

}StackType;

void init(StackType* S)
{
    S->top = -1;
}

int isEmpty(StackType* S)
{
    return S->top == -1;
}

int isFull(StackType* S)
{
    return S->top == SIZE - 1;
}

void push(StackType* S, char c)
{
    if(isFull(S))
		printf("Overflow!!\n");
	else{
	    S->top++;
		S->data[S->top] = c;								    }
}

char pop(StackType* S)
{
	    if(isEmpty(S))
			    {
				        printf("Empty!!\n");

							        return -1;

									    }

		   

		    char c = S->data[S->top];

			    S->top--;

				    return c;

}

char peek(StackType* S)
{

	    if(isEmpty(S))

			    {

					        printf("Empty!!\n");

							        return -1;

									    }

		 
		   

		    return S->data[S->top];

}

void print(StackType* S)
{

	    for(int i = 0; i <= S->top; i++)
			        printf("%c", S->data[i]);

		    printf("\n");    

}

int main()
{

	    StackType S;

		    init(&S);

			   

			    pop(&S);

				    push(&S, 'C');

					    push(&S, 'a');

						    push(&S, 't');

							    push(&S, 's');

								    print(&S);

									    getchar();

										    printf("After pop() : %c\n", pop(&S));

											    print(&S);
			    return 0;

}
