#include<stdio.h>
#include<stdlib.h>
#include<string>
#define N 10

typedef struct {
	int ID;
	char name[20];
	int balance;
}acd;

acd node[N];
int number = 0;

int acc(void)
{
	int ID;
	char name[20];
	int balance;

	printf("개좌 개설\n");
	printf("ID: ");
	scanf_s("%d\n", &ID);
	printf("사용자 이름: ");
	scanf_s("%s\n", &name);
	printf("금액: ");
	scanf_s("%d\n", &balance);

	node[number].ID = ID;
	strcpy(node[number].name, name);
	node[number].balance = balance;
	number++;
}

int inquiry(void)
{
	int ID;
	int i;

	printf("개좌 조회\n");
	printf("ID: ");
	scanf_s("%d\n", &ID);

	for (i = 0; i<number; i++)
	{
		if (node[i].ID == ID)
		{
			printf("ID: %d\n", node[i].ID);
			printf("사용자 이름: %s\n", node[i].name);
			printf("잔액: %d\n", node[i].balance);
			return;
		}
	}
	printf("해당 ID는 없습니다.");
}