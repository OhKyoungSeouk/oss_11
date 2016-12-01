#ifndef FRAMEWORK_H
#define FRAMEWORK_H
#include "framework.h"
#endif

//#define N 10
/* obsolete structure
typedef struct {
	int ID;
	char name[20];
	int balance;
}acd;

acd node[N];
int number = 0;

int acc(void) // 이거 뭐예요??
{
	int ID;
	char name[20];
	int balance;

	printf("개좌 개설\n");
	printf("ID: ");
	scanf("%d\n", &ID);
	printf("사용자 이름: ");
	scanf("%s\n", name);
	printf("금액: ");
	scanf("%d\n", &balance);

	node[number].ID = ID;
	strcpy(node[number].name, name);
	node[number].balance = balance;
	number++;
	return 0;
}
*/
int inquiry(struct node *head) // requires node in main.c
{
	struct node *np = NULL;

	long int ID;
	//int i;

	printf("개좌 조회\n");
	printf("ID: ");fflush( stdout );
	scanf(" %ld", &ID);

	for (np = head; np != NULL; np = np->next)
	{
		if (np->account->account_number == ID)
		{
			printf("ID: %ld\n", np->account->account_number);
			printf("사용자 이름: %s\n", np->account->name);
			printf("잔액: %ld\n", np->account->balance);
			return 0;
		}
	}
	printf("해당 ID는 없습니다.");
	return 1;
}
