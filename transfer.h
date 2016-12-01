/*****************************************
                 TRANSFER
*****************************************/
#ifndef FRAMEWORK_H
#define FRAMEWORK_H
#include "framework.H"
#endif

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
