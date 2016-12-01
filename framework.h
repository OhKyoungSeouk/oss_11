#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef STRING_H
#define STRING_H
#include <string.h>
#endif

#ifndef FRAMEWORK_H
#define FRAMEWORK_H

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

#endif

//#define DATASIZE 999


/* obsolete node and data management functions, transferred to main.c
struct node{
	struct Account *account;
	long account_number;
	struct node *next;
};

struct node *head = NULL;
struct Account gData[DATASIZE];

void insertNode(char *name, int id, int pw, int bal){

}

int loadData(void){
	FILE *fp = NULL;
	char str[160], *token;
	int i;
	fp = fopen("accounts.txt", "r");
	if(fp!=NULL){
		for(; head != NULL; head=head->next){
			if(fgets(str, 160, fp)!=NULL){
				token = strtok(str, ",");
				while(token!=NULL){
					strcpy(gData[i].name, token);
					token = strtok(NULL, ",");
					sscanf(token, "%d", &gData[i].id);
					token = strtok(NULL, ",");
					sscanf(token, "%d", &gData[i].password);
					token = strtok(NULL, ",");
					sscanf(token, "%d", &gData[i].balance);
					token = strtok(NULL, ",");
				}
			}else{
				return 1;
			}
		}
	}
	return 0;
}
int saveData(void){
	FILE *fp = NULL;
	int i;
	fp = fopen("accounts.txt", "w");
	if(fp!=NULL){
		for(i = 0; i < DATASIZE; i++){
			fprintf(fp, "%s%d%d%d\n", gData[i].name, gData[i].id, gData[i].password, gData[i].balance);
		}
		fclose(fp);
	}else{
		return 1;
	}
	fclose(fp);
	return 0;
}
*/
