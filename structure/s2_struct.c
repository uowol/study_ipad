#include <stdio.h>
#include <stdlib.h>

typedef struct Bank{
    	int account;
        char name[20];
	int balance;
} Bank;

void deposit(Bank *a,int amt){
	// (*a).balance += amt;
	a->balance += amt;
	printf("%s: %d - %d\n", a->name, a->account, a->balance);
}

int main(){
	Bank a;
	scanf("%d %s %d", &a.account, a.name, &a.balance);
	printf("%d %s %d", a.account, a.name, a.balance);

	getchar();
	deposit(&a, 10000);
	
	getchar();
	printf("%d %s %d", a.account, a.name, a.balance);
	printf("\n");
	return 0;
}
