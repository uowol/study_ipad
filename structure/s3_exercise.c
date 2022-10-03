#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    if(isEmpty(S)){
        printf("Empty!!\n");
        return -1;
    }	   
	char c = S->data[S->top];
    S->top--;
    return c;
}

char peek(StackType* S)
{
    if(isEmpty(S)){
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

int check(char exp[]){
	StackType S;
	init(&S);

	char c, t;
	int n=strlen(exp);

	for(int i=0; i<n; i++){
		c = exp[i];
		if(c == '(' || c=='{' || c=='['){
			push(&S, c);
		}else if(c==')' || c=='}' || c==']'){
			if(isEmpty(&S)){
				return 0;
			}else{
				t = pop(&S);
				if((t=='(' && c!=')') 
					|| (t=='{' && c!='}') 
					|| (t=='[' && t!=']'))
					return 0;
				return 1;
			}
		}
	}
}

int main()
{
	char exp[SIZE];
	scanf("%s", exp);

	if(check(exp)){
		printf("Success\n");
	}else{
		printf("Fail\n");
	}
	return 1;
}
