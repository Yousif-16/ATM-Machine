    #include"server.h"
    #include <stdio.h>
#include <stdlib.h>
extern int i;
ST_transaction_t Trans_Data;
int flag;
int flag_2=0;
    EN_transState_t recieveTransactionData(ST_transaction_t *transData)
    {
if(isValidAccount(&transData->cardHolderData))
{
    flag_2=1;

    return DECLINED_STOLEN_CARD;
}

else if(isAmountAvailable(&transData->terminalData))
{
    flag_2=3;
    return DECLINED_INSUFFECIENT_FUND;
}

if(!isAmountAvailable(&transData->terminalData))
{
    accounts_arr[flag].balance=accounts_arr[flag].balance-transData->terminalData.transAmount;

}
/*if(saveTransaction(&transData))
{
    	accounts_arr[flag].balance=accounts_arr[flag].balance-transData->terminalData.transAmount;
    	return APPROVED;
}
else
{
    return INTERNAL_SERVER_ERROR;
}*/

    }

    EN_serverError_t isValidAccount(ST_cardData_t *cardData)
    {
        // Linear search Algorithm
        int index=0;
        int j=0;
        int I=0;

         Account_DB();

         fflush(stdin);
        for (I=0;I<255;I++)
        {
            for(j=0;j<18;j++)

            if(accounts_arr[I].primaryAccountNumber[j]==cardData->primaryAccountNumber[j])
            {
               index++;
               continue;
            }
            else
            {
                index=0;
                break;
            }
if (index==18)
   {
       flag=I;
       break;
   }
else
    continue;

        }

        if (index==18)
            return ok;
        else
            return DECLINED_STOLEN_CARD;

    }
    EN_serverError_t isAmountAvailable(ST_terminalData_t *termData)
    {
        if(termData->transAmount>accounts_arr[flag].balance)
        {

            return LOW_BALANCE;
        }
        else
        {

            return ok;
        }
    }
   /* EN_serverError_t saveTransaction(ST_transaction_t *transData)

    {
        int counter_2=0;
        while (transData->cardHolderData.primaryAccountNumber[counter_2]!='\0')
	{
		transaction_arr[flag].cardHolderData.primaryAccountNumber[counter_2]=transData->cardHolderData.primaryAccountNumber[counter_2];
		counter_2++;
	}
	counter_2=0;
	    while (transData->cardHolderData.cardHolderName[counter_2]!='\0')
	{
		transaction_arr[flag].cardHolderData.cardHolderName[counter_2]=transData->cardHolderData.cardHolderName[counter_2];
		counter_2++;
	}
	counter_2=0;
	    while (transData->cardHolderData.cardExpirationDate[counter_2]!='\0')
	{
		transaction_arr[flag].cardHolderData.cardExpirationDate[counter_2]=transData->cardHolderData.cardExpirationDate[counter_2];
		counter_2++;
	}
	transaction_arr[flag].terminalData.transAmount=transData->terminalData.transAmount;
    transaction_arr[flag].terminalData.maxTransAmount=transData->terminalData.maxTransAmount;
counter_2=0;
    while (transData->terminalData.transactionDate[i]!='\0')
	{
	transaction_arr[flag].terminalData.transactionDate[counter_2]=transData->terminalData.transactionDate[counter_2];
	counter_2++;
	}
return ok;

    }
    EN_serverError_t getTransaction(Uint32 transactionSequenceNumber, ST_transaction_t *transData)

{


		if (transactionSequenceNumber==transData->transactionSequenceNumber)
		{
			return ok;
		}
		else
		{
			return TRANSACTION_NOT_FOUND;
		}

}*/

    void Account_DB(void)
    {
    accounts_arr[0]=(ST_accountsDB_t){20000,RUNNING,"111111111111111111"};
	accounts_arr[1]=(ST_accountsDB_t){30000,RUNNING,"222222222222222222"};
	accounts_arr[2]=(ST_accountsDB_t){40000,RUNNING,"333333333333333333"};
	accounts_arr[3]=(ST_accountsDB_t){50000,RUNNING,"444444444444444444"};
	accounts_arr[5]=(ST_accountsDB_t){100000,RUNNING,"555555555555555555"};
	accounts_arr[6]=(ST_accountsDB_t){200000,RUNNING,"666666666666666666"};
	accounts_arr[7]=(ST_accountsDB_t){300000,BLOCKED,"777777777777777777"};
	accounts_arr[8]=(ST_accountsDB_t){400000,BLOCKED,"888888888888888888"};
	accounts_arr[9]=(ST_accountsDB_t){1500000,BLOCKED,"9999999999999999"};
	accounts_arr[10]=(ST_accountsDB_t){12200000,BLOCKED,"123456789123456789"};
	accounts_arr[11]=(ST_accountsDB_t){1030000,BLOCKED,"551111115555555511"};

    }

