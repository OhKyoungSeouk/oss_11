#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef STRING_H
#define STRING_H
#include <string.h>
#endif

#define NAMESIZE 20


struct Customer{
	char name[20];
	int password;
	int balance;
};

void makeAccount(struct Customer *array, int index){
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
