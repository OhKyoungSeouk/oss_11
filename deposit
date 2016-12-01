#include <stdio.h>
#include <stdlib.h>

struct account
{
	int id;
	char name[20];
	int money;
};

void depositMoney(account *tmp)
{
	int id;
	int money;
	char q;

	printf("계좌에 금액을 더합니다.\n");
	printf("계좌번호를 입력하시오\n");
	scanf("%d", &id);
	printf("입금할 금액을 입력하시오\n");
	scanf("%d", &money);
	fflush(stdin);

	for (;;)
	{
		printf("입력한 계좌번호와 금액이 각각 %d, %d가 맞습니까?(Y/N)\n", id, money);
		scanf("%c", &q);
		if (q == 'y')
		{
			for (int i = 0; i<100; i++)
			{
				if (id == tmp[i].id)
					tmp[i].money += money;
			}
			break;
		}
		else if (q == 'n')
			printf("잘못 입력하였습니다. 다시 입력하시오.(Y/N)\n");
	}
	printf("입금이 완료되었습니다.\n");

}

void withdraw(account *tmp)
{

	int id;
	int money;
	char q;

	printf("계좌에서 출금을 합니다.\n");
	printf("계좌번호를 입력하시오\n");
	scanf("%d", &id);
	printf("출금할 금액을 입력하시오\n");
	scanf("%d", &money);
	fflush(stdin);

	for (;;)
	{
		printf("입력한 계좌번호와 금액이 각각 %d, %d가 맞습니까?(Y/N)\n", id, money);
		scanf("%c", &q);
		if (q == 'y')
		{
			for (int i = 0; i<100; i++)
			{
				if (id == tmp[i].id)
					tmp[i].money -= money;
			}
			break;
		}
		else if (q == 'n')
			printf("잘못 입력하였습니다. 다시 입력하시오.(Y/N)\n");
	}
	printf("출금이 완료되었습니다.\n");

}
