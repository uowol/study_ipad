#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
// #define element char

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
    else
    {
        S->top++;
        S->data[S->top] = c;
    }
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

int rollin(char word[]){
    StackType S;
    init(&S);

    char c, t;
    char copy[SIZE];
	int n=strlen(word);
    int j = 0;

    for(int i=0; i<n; i++){
        c = word[i];
        if(c >= 'A' && c <= 'Z') {
            push(&S, c+32);
            copy[j++] = c+32;
        }
        else if(c < 'a' || c > 'z') continue;
        else {
            push(&S, c);
            copy[j++] = c;
        }
    }

    for(int i=0; i<j; i++){
        c = copy[i];
        t = pop(&S);
        if (c!=t) return 0;
    }    

    return 1;
}

int main()
{
    char word[SIZE];
    printf("문자열을 입력하시오: ");
    scanf("%[^\n]s", word);

    int res = rollin(word);

    if(res){
        printf("회문입니다.\n");
    }else{
        printf("회문이 아닙니다.\n");
    }
    return 0;
}