#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Account Structure
struct Account{
	char name[20];
	char id[20];
	long int account_number;
	long int password;
	long int balance;
};

// linked list
struct node{
	struct Account *account;
	struct node *next;
};

struct node *head = NULL;
int account_no = 0;

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

int inquiry(struct node *head) // requires node in main.c
{
	struct node *np = NULL;

	long int ID;
	//int i;

	printf("개좌 조회\n");
	printf("ID: ");fflush( stdout );
	scanf(" %ld", &ID);

	for (np = head; np != NULL; np = np->next)
	{
		if (np->account->account_number == ID)
		{
			printf("ID: %ld\n", np->account->account_number);
			printf("사용자 이름: %s\n", np->account->name);
			printf("잔액: %ld\n", np->account->balance);
			return 0;
		}
	}
	printf("해당 ID는 없습니다.");
	return 1;
}

void depositMoney(struct Account *tmp)
{
	//int id;
	long int money;
	char q;

	printf("계좌에 금액을 더합니다.\n");
	//printf("계좌번호를 입력하시오\n");
	//scanf(" %d", &id);
	printf("입금할 금액을 입력하시오\n");fflush(stdout);
	scanf(" %ld", &money);
	fflush(stdin);

	while(money > 0)
	{
		printf("입력한 계좌번호와 금액이 각각 %05ld, %ld가 맞습니까?(y/n)\n", tmp->account_number, money);fflush(stdout);
		scanf(" %c", &q);
		if (q == 'y') {
			tmp->balance += money;
			break;
		}
		else
		{
			printf("잘못 입력하였습니다. 다시 입력하시오.(y/n)\n");fflush(stdout);
			scanf(" %c", &q);
			if(q == 'n')
				break;
		}
	}
	printf("입금이 완료되었습니다.\n");
}
void withdraw(struct Account *tmp)
{
	//int id;
	long int money;
	char q;

	printf("계좌에서 출금을 합니다.\n");
	//printf("계좌번호를 입력하시오\n");
	//scanf(" %d", &id);
	printf("출금할 금액을 입력하시오\n");fflush(stdout);
	scanf(" %ld", &money);
	fflush(stdin);

	while(money > 0) {
		printf("입력한 계좌번호와 금액이 각각 %05ld, %ld가 맞습니까?(Y/N)\n", tmp->account_number, money);fflush(stdout);
		scanf(" %c", &q);
		if (q == 'y') {
			tmp->balance -= money;
			break;
		}else{
			printf("잘못 입력하였습니다. 다시 입력하실까요?(y/n)\n");fflush(stdout);
			scanf(" %c", &q);
			if(q == 'n')
				break;
		}
	}
	printf("출금이 완료되었습니다.\n");
}

void transfer(struct Account *ap, struct node *head)
{
	struct node *np;
	long int account_no, amount;

    printf("\nEnter account number:");fflush(stdout);
    scanf(" %ld",&account_no);

    printf("\nHow much money would you like to transfer? :");fflush(stdout);
    scanf(" %ld", &amount);

    for(np = head; np != NULL; np = np->next){
    	if(np->account->account_number == account_no)
    		break;
    }

    if( ap->balance < amount){
        printf("Transaction denied!Insufficient funds!!\n");
        //return 1;
    }else if(np == NULL){
    	printf("Account does not exist...\n");
    }else{
        printf("%ld amount has been remitted\n",amount);
        ap->balance-=amount;
        np->account->balance += amount;
        printf("%ld amount left in account\n", ap->balance);
    }
    //return 0;
}

void insertNode(char *name, char *id, long int account_number,long int pw, long int balance){
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link->account = (struct Account*) malloc(sizeof(struct Account));
	//link->account->name = (char*) malloc(sizeof(char) * 21); // char * 20 + null character

	strncpy(link->account->name, name, 20); // strncpy instead of strcpy to limit copy to 20 characters
	strncpy(link->account->id, id, 20);
	link->account->account_number = account_number;
	link->account->password = pw;
	link->account->balance = balance;

	link->next = head;
	head = link;
}
void printNodes(void){
	struct node *ptr = head;
	while(ptr){
		printf("%s %s %ld %ld %ld\n", ptr->account->name, ptr->account->id, ptr->account->account_number, ptr->account->password, ptr->account->balance);
		ptr = ptr->next;
	}
}
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
	// struct node *np = NULL;
	char name[20], id[20];
	long int password, balance;
	char str[160], *token;

	account_no = 0;
	fp = fopen("accounts.txt", "r");
	if(fp != NULL){
		while(fgets(str, 160, fp) != NULL){
			//np->account->account_number = account_no;
			//account_no++;
			token = strtok(str, ",");
			while(token!=NULL){
				strncpy(name, token, 20);
				token = strtok(NULL, ",");
				strncpy(id, token, 20);
				token = strtok(NULL, ",");
				sscanf(token, "%ld", &password);
				token = strtok(NULL, ",");
				sscanf(token, "%ld", &balance);
				token = strtok(NULL, ",");
				insertNode(name, id, account_no, password, balance);
				account_no++;
			}
		}
	}else{
		fclose(fp);
		return 1;
	}
	fclose(fp);
	return 0;
}
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
	account_no++;

	insertNode(tmp.name, tmp.id, account_no, tmp.password, tmp.balance);

	printf("%s, Your new account has been created!\nid: %s\naccount no: %05ld\n", tmp.name, tmp.id, tmp.account_number);

	//puts("Testing...");
	//printNodes();
}

/*
int main(void){
	//struct node *np = NULL;
	loadData();
	printNodes();

	//printf("%s %s %ld %ld\n", np->account->name, np->account->id, np->account->password, np->account->balance);


	return 0;
}
*/

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
		//printNodes();
		//system("cls");
		printf("[1]Login\n[2]Register\n");fflush( stdout );
		scanf(" %d", &choice);
		if(choice == 1){
			np = login();
			if(np != NULL){
				menu(np->account);
				saveData();
				//system("cls");
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


