/*****************************************
                 TRANSFER
*****************************************/
#ifndef FRAMEWORK_H
#define FRAMEWORK_H
#include "framework.H"
#endif

void transfer(struct Account *accPtr)
{
	int account_no, amount;

    printf("\nEnter account number:");
    scanf("%d",&account_no);

    printf("\nHow much money would you like to transfer? :");
    scanf(" %d", &amount);
    if(accPtr->balance < amount){
        printf("Transaction denied!Insufficient funds!!\n");
        //return 1;
    }else{
        printf("%d amount has been remitted\n",amount);
        accPtr->balance-=amount;
        printf("%d amount left in account\n",balance);
    }
    //return 0;
}
