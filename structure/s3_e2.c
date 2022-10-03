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

int evaluate(char exp[]){
	StackType S;
	init(&S);

	int op1, op2, val;
	char c;
	int n = strlen(exp);

	for(int i=0; i<n; i++){
		c = exp[i];
		if(c!='+' && c!= '-' && c!='*' && c!='/'){
			val = c-'0';
			push(&S, val); // 숫자자료 형변환
		}else{
			op2 = pop(&S);
			op1 = pop(&S);
			switch(c){
				case '+':
					push(&S, op1 + op2);
					break;
				case '-':
					push(&S, op1 - op2);
					break;
				case '*':
					push(&S, op1*op2);
					break;
				case '/':
					push(&S, op1/op2);
					break;
			}
		}
	}
	return pop(&S);

}

// 연산자 우선순위
int prec(char op){
	switch(op){
		case '(': case ')':
			return 0;
		case '+': case '-':
			return 1;
		case '*': case '/':
			return 2;
	}
}

void convert(char infix[], char postfix[]){
	StackType S;
	init(&S);

	char c,t;
	int n = strlen(infix);
	int idx = 0;
	for(int i=0; i<n; i++){
		c = exp[i];
		switch(c){
			case '+': case '-': case '*': case '/':
				// 비어있지 않다면 연산자 비교	
				while(!isEmpty(&S) && prec(c) <= prec(peek(&S))){
					res[idx_res] = pop(&S);
				}
				push(&S, c);
				break;
			case '(':
				push(&S, c);
				break;
			case ')':
				t = pop(&S);
				while(t != '('){
					printf("%c", t);
					t = pop(&S);
				}
				break;
			default:
				printf("%c", c);
		}
	}
	while(!isEmpty(&S)){
		printf("%c", pop(&S));
	}
	printf("\n");
}

int main()
{
	char infix[SIZE], postfix[SIZE];
	scanf("%s", infix);

	convert(infix, postfix);

//	if(check(exp)){
//		printf("Success\n");
//	}else{
//		printf("Fail\n");
//	}
	printf("%d\n", evaluate(exp));

	return 1;
}
