//입출금
#ifndef FRAMEWORK_H
#define FRAMEWORK_H
#include "framework.h"
#endif

/* -obsolete-
struct account
{
	int id;
	char name[20];
	int money;
};
*/

void depositMoney(struct Account *tmp)
{
	//int id;
	long int money;
	char q;

	printf("계좌에 금액을 더합니다.\n");
	//printf("계좌번호를 입력하시오\n");
	//scanf(" %d", &id);
	printf("입금할 금액을 입력하시오\n");fflush(stdout);
	scanf(" %ld", &money);
	fflush(stdin);

	while(money > 0)
	{
		printf("입력한 계좌번호와 금액이 각각 %05ld, %ld가 맞습니까?(y/n)\n", tmp->account_number, money);fflush(stdout);
		scanf(" %c", &q);
		if (q == 'y') {
			tmp->balance += money;
			break;
		}
		else
		{
			printf("잘못 입력하였습니다. 다시 입력하시오.(y/n)\n");fflush(stdout);
			scanf(" %c", &q);
			if(q == 'n')
				break;
		}
	}
	printf("입금이 완료되었습니다.\n");
}
void withdraw(struct Account *tmp)
{
	//int id;
	long int money;
	char q;

	printf("계좌에서 출금을 합니다.\n");
	//printf("계좌번호를 입력하시오\n");
	//scanf(" %d", &id);
	printf("출금할 금액을 입력하시오\n");fflush(stdout);
	scanf(" %ld", &money);
	fflush(stdin);

	while(money > 0) {
		printf("입력한 계좌번호와 금액이 각각 %05ld, %ld가 맞습니까?(Y/N)\n", tmp->account_number, money);fflush(stdout);
		scanf(" %c", &q);
		if (q == 'y') {
			tmp->balance -= money;
			break;
		}
		else
			printf("잘못 입력하였습니다. 다시 입력하시오.(y/n)\n");
	}
	printf("출금이 완료되었습니다.\n");
}
