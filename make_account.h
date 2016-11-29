#ifndef FRAMEWORK_H
#define FRAMEWORK_H
#include "framework.h"
#endif

#define NAMESIZE 20

void makeAccount(struct Account *array, int index){
	//배열과 빈 요소의 인덱스를 입력하시오

	char buffer[20];
	int input;

	puts("이름을 입력하시오: ");
	gets(buffer);
	puts("비밀번호를 입력하시오: ");
	scanf(" %d", &input);

	strcpy(array[index].name, buffer);
	array[index].password = input;
	array[index].balance = 0;

}
