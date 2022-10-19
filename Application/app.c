#include"app.h"
void appStart(void)
{
     extern ST_cardData_t CardData;
   extern Uint8 Name[25];
   extern Uint8 Expiry_Date[6];
   extern Uint8 PAN[20];
   extern Uint8 Lenght;
   extern Uint8 i;
   extern ST_terminalData_t TermData;
   extern Uint8 Transction_date[11];
   extern f32 TRANS_AMOUNT;
   extern f32 MAX_TRANS;
   ST_transaction_t Trans_Data;
   extern int flag_2;
   while(1)
   {
       do
        {


       do
       {
           printf("please enter your Name: ");
       gets(Name);
       Lenght=strlen(Name);
       strcpy(Trans_Data.cardHolderData.cardHolderName,Name);

       if (getCardHolderName(&(Trans_Data.cardHolderData)))
   {
      printf ("Wrong Name\n");
      // return main();
   }
       else
        printf("OK\n");
       }while(getCardHolderName(&(Trans_Data.cardHolderData)));


        do
        {
            printf("please enter the expiry date(MM/YY) : ");
        gets(Expiry_Date);
        Lenght=strlen(Expiry_Date);
        strcpy(Trans_Data.cardHolderData.cardExpirationDate,Expiry_Date);
       if(getCardExpiryDate(&Trans_Data.cardHolderData))
       {
           printf("Wrong Expiration Date\n");
           // go back to date
       }

       else
        printf("OK\n");
        }while(getCardExpiryDate(&Trans_Data.cardHolderData));
        do
        {
            printf("Please Enter your Primary Accounting Number : ");
        gets(PAN);
        Lenght=strlen(PAN);
        strcpy(&Trans_Data.cardHolderData.primaryAccountNumber,PAN);
        if(getCardPAN(&Trans_Data.cardHolderData))
            printf("Wrong Primary Accounting Number\n");
        else
            printf("OK\n");
        }while(getCardPAN(&Trans_Data.cardHolderData));

            do
            {
                printf("Please enter your Transction Date (DD/MM/YYYY) : ");
            gets(Transction_date);
            Lenght=strlen(Transction_date);
            strcpy(Trans_Data.terminalData.transactionDate,Transction_date);
            if(getTransactionDate(&Trans_Data.terminalData))
                printf("Wrong Transction Date \n");
            else
                printf("ok\n");
            }while(getTransactionDate(&Trans_Data.terminalData));
                printf("Now checcking the validity OF the card.............\n");
                printf("the card is ");

                 if(isCardExpired(Trans_Data.cardHolderData,Trans_Data.terminalData))
                    printf("Expired card\n");
                 else
                    printf("OK\n \n");
   }while(isCardExpired(Trans_Data.cardHolderData,Trans_Data.terminalData));
   do
   {
       printf("please enter the MAX Transaction amount :");
       scanf("%f",&MAX_TRANS);
       fflush(stdin);
       Trans_Data.terminalData.maxTransAmount=MAX_TRANS;
       if(setMaxAmount(& Trans_Data.terminalData))
        printf ("\nInvalid MAX Amount....!\n");
       else
        printf("ok\n");
   }while (setMaxAmount(& Trans_Data.terminalData));

                   do
                   {
                       printf("Please Enter the Transaction Amount : ");
                   scanf("%f",&TRANS_AMOUNT);
                   fflush(stdin);
                  Trans_Data.terminalData.transAmount=TRANS_AMOUNT;
                   if(getTransactionAmount(&Trans_Data.terminalData))
                    printf("Invalid amount\n");
                   else
                    printf("OK\n");
                    printf("Now compares the MAX amount with transaction amount....\n ");
                    if(isBelowMaxAmount(& Trans_Data.terminalData))
                        printf("The transaction amount is exceeds the MAX amount....\n");
                    else
                        printf(" OK\n");
                   }while (isBelowMaxAmount(& Trans_Data.terminalData));
                   recieveTransactionData(&Trans_Data);

                       if(flag_2==1)
                        {
                            printf("Declined Stolen Card\n");
                        }
                        else if(flag_2==3)
                        {
                            printf("DECLINED INSUFFECIENT FUND\n");
                        }
                        else
                            printf("transaction is approved\n");
}
}
