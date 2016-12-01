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
	int account_no, amount;

    printf("\nEnter account number:");
    scanf(" %d",&account_no);

    printf("\nHow much money would you like to transfer? :");
    scanf(" %d", &amount);

    for(np = head; np != NULL; np = np->next){
    	if(np->account_number == account_no)
    		break;
    }

    if( ap->balance < amount){
        printf("Transaction denied!Insufficient funds!!\n");
        //return 1;
    }else if(np == NULL){
    	printf("Account does not exist...\n");
    }else{
        printf("%d amount has been remitted\n",amount);
        ap->balance-=amount;
        np->account->balance += amount;
        printf("%d amount left in account\n", ap->balance);
    }
    //return 0;
}
