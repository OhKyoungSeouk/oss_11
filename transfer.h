/*****************************************
                 TRANSFER
*****************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int password,balance,amount;
	char ID[20];

    printf("\nEnter account number:");
    scanf("%d",&account_no);

    printf("\nHow much money would you like to transfer? :");
while(1)
    {
        if(account_amount<amount)
    {
        printf("Transaction denied!Insufficient funds!!\n");
    }
    else
    {
        printf("%d amount has been remitted\n",amount);
    }
    balance=account_amount-amount;
    printf("%d amount left in account\n",balance);
    }


    return 0;
}
