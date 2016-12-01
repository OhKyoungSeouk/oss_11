#ifndef FRAMEWORK_H
#define FRAMEWORK_H
#include "framework.h"
#endif

struct Account makeAccount(){
	//배열과 빈 요소의 인덱스를 입력하시오
	struct Account ap;
	char buffer[20];
	int input;

	puts("이름을 입력하시오: ");fflush( stdout );
	gets(buffer);
	puts("비밀번호를 입력하시오: ");fflush( stdout );
	scanf(" %d", &input);

	strncpy(ap.name, buffer, 20);
	ap.password = input;
	ap.balance = 0;

	return ap;
}
