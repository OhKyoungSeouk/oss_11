#include "framework.h"
#include "account_inquiry.h"
#include "make_account.h"
#include "manage_money.h"
#include "transfer.h"

struct Account login(void){
	int id, pw, i;
	struct Account *ap; // account pointer
	puts("ID를 입력하시오: ");
	// gets(logid); -id is not login id, nvm-
	scanf(" %d", &id)
	puts("비밀번호를 입력하시오: ");
	scanf(" %d", &pw);

	for(i = 0; i < DATASIZE; i++){
		if(gData[i].id == logid && gData[i].password == pw){
		ap = gData[i];
			return ap;
		}
	}
}
void menu(struct Account *ap){

	int choice;

	printf("[1]deposit\n[2]withdraw\n[3]transfer\n[4]inquiry\n[5]exit\n")
	switch(choice){
	case 1:
		depositMoney(ap);
		break;
	case 2:
		withdraw(ap);
		break;
	case 3:
		transfer(ap);
		break;
	case 4:
		inquiry();
		break;
	default:
		puts("완료되었습니다.")
		break;
	}
}
int main(void){
	struct Account *ap = NULL;
	if((ap = login())!=NULL)
		menu(ap);
	else
		puts("Invalid username or password");

	return 0;
}
