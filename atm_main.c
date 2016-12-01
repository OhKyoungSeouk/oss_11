#include "framework.h"
#include "account_inquiry.h"
#include "make_account.h"
#include "manage_money.h"
#include "transfer.h"

// linked list
struct node{
	struct Account *account;
	int account_number;
	struct node *next;
};

struct node *head = NULL;
int account_no = 0;

void insertNode(char *name, int id, int pw, int balance){
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link->account = (struct Account*) malloc(sizeof(struct Account));
	link->account->name = (char*) malloc(sizeof(char) * 21); // char * 20 + null character

	strncpy(link->account->name, name, 20); // strncpy instead of strcpy to limit copy to 20 characters
	link->account->id = id;
	link->account->password = pw;
	link->account->balance = balance;

	link->next = head;
	head = link;
}
void printNodes(void){
	struct node *ptr = head;
	while(ptr){
		printf("%s %d %d\n", ptr->account->name, ptr->account->id, ptr->account->balance);
		ptr = ptr->next;
	}
}

// data management
int saveData(void){
	FILE *fp = NULL;
	struct node *np = NULL;
	fp = fopen("accounts.txt", "w");
	if(fp!=NULL){
		for(np = head; np != NULL; np = np->next){
			fprintf(fp, "%s,%d,%d,%d\n", np->account->name, np->account->id, np->account->password, np->account->balance);
		}
		fclose(fp);
	}else{
		return 1;
	}
	fclose(fp);
	return 0;
}
int loadData(void){
	FILE *fp = NULL;
	struct node *np = NULL;
	char str[160], *token;
	account_no = 0;
	fp = fopen("accounts.txt", "r");
	if(fp!=NULL){
		for(np = head; np != NULL; np = np->next){
			np->account_number = account_no;
			id++;
			if(fgets(str, 160, fp) != NULL){
				token = strtok(str, ",");
				while(token!=NULL){
					strncpy(np->account->name, token, 20);
					token = strtok(NULL, ",");
					sscanf(token, "%d", &np->account->id);
					token = strtok(NULL, ",");
					sscanf(token, "%d", &np->account->password);
					token = strtok(NULL, ",");
					sscanf(token, "%d", &np->account->balance);
					token = strtok(NULL, ",");
				}
			}else{
				return 1;
			}
		}
	}
	return 0;
}

// user level
struct node login(void){
	int id, pw;
	struct node *np = NULL;
	puts("ID를 입력하시오: ");
	// gets(logid); -id is not login id, nvm-
	scanf(" %d", &id)
	puts("비밀번호를 입력하시오: ");
	scanf(" %d", &pw);

	for(np = head; np != NULL; np = np->next){
		if(np->account->id == logid && np->account->password == pw){
			return np;
		}else{
			return NULL;
		}
	}
}
void menu(struct Account *ap){

	int choice;
	puts("작업 번호를 입력하시오: ");
	printf("[1]deposit\n[2]withdraw\n[3]transfer\n[4]inquiry\n[5]make account\n[6]exit\n")
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
	case 5:
		makeAccount();
		break;
	default:
		break;
	}
	puts("완료되었습니다.")
}
int main(void){
	struct node *np = NULL;

	if(loadData() == 1){
		puts("Data load failed...");
		return 1;
	}
	if((np = login())!=NULL){
		menu(np->account);
		saveData();
	}
	else
		puts("Invalid username or password");

	return 0;
}