#include "framework.h"
#include "account_inquiry.h"
#include "make_account.h"
#include "manage_money.h"
#include "transfer.h"

struct node *head = NULL;
int account_no = 0;

void insertNode(char *name, char *id, int pw, int balance){
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link->account = (struct Account*) malloc(sizeof(struct Account));
	//link->account->name = (char*) malloc(sizeof(char) * 21); // char * 20 + null character

	strncpy(link->account->name, name, 20); // strncpy instead of strcpy to limit copy to 20 characters
	strncpy(link->account->id, id, 20);
	link->account->password = pw;
	link->account->balance = balance;

	link->next = head;
	head = link;
}
void printNodes(void){
	struct node *ptr = head;
	while(ptr){
		printf("%s %s %ld %ld\n", ptr->account->name, ptr->account->id, ptr->account->password, ptr->account->balance);
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
			fprintf(fp, "%s,%s,%ld,%ld\n", np->account->name, np->account->id, np->account->password, np->account->balance);
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
	if(fp != NULL){
		for(np = head; np != NULL; np = np->next){
			np->account->account_number = account_no;
			account_no++;
			if(fgets(str, 160, fp) != NULL){
				token = strtok(str, ",");
				while(token!=NULL){
					strncpy(np->account->name, token, 20);
					token = strtok(NULL, ",");
					strncpy(np->account->id, token, 20);
					token = strtok(NULL, ",");
					sscanf(token, "%ld", &np->account->password);
					token = strtok(NULL, ",");
					sscanf(token, "%ld", &np->account->balance);
					token = strtok(NULL, ",");
				}
			}
		}
	}else{
		fclose(fp);
		return 1;
	}
	fclose(fp);
	return 0;
}

// user level
struct node* login(void){
	long int pw;
	char id[20];
	struct node *np = NULL;
	puts("ID를 입력하시오: ");fflush(stdout);
	// gets(logid); -id is not login id, nvm-
	scanf(" %s", id);
	puts("비밀번호를 입력하시오: ");fflush(stdout);
	scanf(" %ld", &pw);

	for(np = head; np != NULL; np = np->next){
		if(strcmp(np->account->id,id) == 0 && np->account->password == pw){
			//puts("Testing...");
			//printf("from list: %s\nfrom input%s\n",np->account->id, id);
			return np;
		}
	}
	return np;
}
void menu(struct Account *ap){

	int choice;
	printf("Test: %s %s %ld %ld %ld\n", ap->name, ap->id, ap->password, ap->account_number, ap->balance);
	puts("작업 번호를 입력하시오: ");
	printf("[1]deposit\n[2]withdraw\n[3]transfer\n[4]inquiry\n[5]exit\n");fflush(stdout);
	scanf(" %d", &choice);
	switch(choice){
	case 1:
		depositMoney(ap);
		break;
	case 2:
		withdraw(ap);
		break;
	case 3:
		transfer(ap, head);
		break;
	case 4:
		inquiry(head);
		break;
	default:
		break;
	}
	puts("완료되었습니다.");
}
void newAccount(void){
	struct Account tmp;
	tmp = makeAccount();
	tmp.account_number = account_no;
	account_no++;

	insertNode(tmp.name, tmp.id, tmp.password, tmp.balance);

	printf("%s, Your new account has been created!\nid: %s\naccount no: %05ld\n", tmp.name, tmp.id, tmp.account_number);

	//puts("Testing...");
	//printNodes();
}
int main(void){
	//setbuf(stdout, NULL); // eclipse printf-scanf problem: disables buffer

	struct node *np = NULL;
	int choice;

	if(loadData() == 1){
		puts("Data load failed...");
		return 1;
	}
	//printf("Testing: \n");
	//printNodes();fflush( stdout );
	while(1){
		printf("[1]Login\n[2]Register\n");fflush( stdout );
		scanf(" %d", &choice);
		if(choice == 1){
			np = login();
			if(np != NULL){
				menu(np->account);
				saveData();
				system("cls");
			}else{
				puts("Invalid username or password");fflush( stdout );
				printNodes();
			}
		}else if(choice == 2){
			newAccount();
			saveData();
		}else{
			puts("완료되었습니다...");fflush( stdout );
			break;
		}
	}
	return 0;
}
