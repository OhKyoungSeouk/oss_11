#ifndef FRAMEWORK_H
#define FRAMEWORK_H
#include "framework.h"
#endif

struct Account makeAccount(){
	//배열과 빈 요소의 인덱스를 입력하시오
	struct Account ap;
	char name[20], id[20];
	long int input;

	puts("이름을 입력하시오: ");fflush( stdout );
	scanf(" %s", name);
	puts("login ID를 입력하시오: ");fflush( stdout);
	scanf(" %s", id);
	puts("비밀번호를 입력하시오: ");fflush( stdout );
	scanf(" %ld", &input);

	strncpy(ap.name, name, 20);
	strncpy(ap.id, id, 20);
	ap.password = input;
	ap.balance = 0;

	return ap;
}
