#ifndef FRAMEWORK_H
#define FRAMEWORK_H
#include "framework.h"
#endif

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

int inquiry(void)
{
	int ID;
	int i;

	printf("개좌 조회\n");
	printf("ID: ");
	scanf("%d\n", &ID);

	for (i = 0; i<number; i++)
	{
		if (node[i].ID == ID)
		{
			printf("ID: %d\n", node[i].ID);
			printf("사용자 이름: %s\n", node[i].name);
			printf("잔액: %d\n", node[i].balance);
			return 0;
		}
	}
	printf("해당 ID는 없습니다.");
	return 0;
}
int main(void)
{
	int status1,status2;

	status1 = acc();
	status2 = inquiry();

	printf("%d %d ", status1,status2);
return 0;


