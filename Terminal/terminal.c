#include"terminal.h"

extern  Uint8 Lenght;
//declare VAR
 ST_terminalData_t TermData;
 Uint8 Transction_date[11]={0};
 f32 TRANS_AMOUNT=0;
 f32 MAX_TRANS=0;

    EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
    {
       /* printf("%d\n",Lenght);
        printf("%d\n",termData->transactionDate[0]);*/
        if (Lenght<10)
            return WRONG_DATE;
            else if (Lenght=NULL)
                return WRONG_DATE;
                else if(termData->transactionDate[2]!='/')
                    return WRONG_DATE;
                else if(termData->transactionDate[5]!='/')
                    return WRONG_DATE;
               else
                {
                    if( (termData->transactionDate[0]-48) <3 && (termData->transactionDate[1]-48)<10)
                    {
                        if((termData->transactionDate[0]-48)==0 && (termData->transactionDate[1]-48)==0)
                            return WRONG_DATE;
                        else if ((termData->transactionDate[3]-48)==0 && (termData->transactionDate[4]-48)<10)
                        {
                            if((termData->transactionDate[3]-48)==0 && (termData->transactionDate[4]-48)==0)
                                return WRONG_DATE;
                                else if ((termData->transactionDate[6]-48)>1 && (termData->transactionDate[7]-48)>-1 && (termData->transactionDate[8]-48)>1 && (termData->transactionDate[9]-48)>1)

                               return oK;
                               else
                                return WRONG_DATE;
                        }
                         else if ((termData->transactionDate[3]-48)==1 && (termData->transactionDate[4]-48)<3)
                         {
                             if((termData->transactionDate[3]-48)==0 && (termData->transactionDate[4]-48)==0)
                                return WRONG_DATE;
                                else if ((termData->transactionDate[6]-48)>1 && (termData->transactionDate[7]-48)>-1 && (termData->transactionDate[8]-48)>1 && (termData->transactionDate[9]-48)>1)

                               return oK;
                               else
                                return WRONG_DATE;
                         }

                    }
                    else if ((termData->transactionDate[0]-48) ==3 && (termData->transactionDate[1]-48)<2)
                    {
                         if((termData->transactionDate[0]-48)==0 && (termData->transactionDate[1]-48)==0)
                            return WRONG_DATE;
                        else if ((termData->transactionDate[3]-48)==0 && (termData->transactionDate[4]-48)<10)
                        {
                            if((termData->transactionDate[3]-48)==0 && (termData->transactionDate[4]-48)==0)
                                return WRONG_DATE;
                                else if ((termData->transactionDate[6]-48)>1 && (termData->transactionDate[7]-48)>-1 && (termData->transactionDate[8]-48)>1 && (termData->transactionDate[9]-48)>1)

                               return oK;
                               else
                                return WRONG_DATE;
                        }
                         else if ((termData->transactionDate[3]-48)==1 && (termData->transactionDate[4]-48)<3)
                         {
                             if((termData->transactionDate[3]-48)==0 && (termData->transactionDate[4]-48)==0)
                                return WRONG_DATE;
                                else if ((termData->transactionDate[6]-48)>1 && (termData->transactionDate[7]-48)>-1 && (termData->transactionDate[8]-48)>1 && (termData->transactionDate[9]-48)>1)

                               return oK;
                               else
                                return WRONG_DATE;
                         }
                    }
                    else
                        return WRONG_DATE;

    }
    }
    EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)

    {

      /*  printf(" %s\n ",cardData.cardExpirationDate);
        printf("%s\n",TermData.transactionDate);*/
        if (cardData.cardExpirationDate[4]>termData.transactionDate[9])
            return OK;
        else if (cardData.cardExpirationDate[4]==termData.transactionDate[9])
        {
            if(cardData.cardExpirationDate[3]>termData.transactionDate[8])
                return oK;
                else if(cardData.cardExpirationDate[3]==termData.transactionDate[8])
                {
                    if(cardData.cardExpirationDate[0]>termData.transactionDate[3])
                        return oK;
                    else if(cardData.cardExpirationDate[0]==termData.transactionDate[3])
                    {
                        if(cardData.cardExpirationDate[1]>termData.transactionDate[4])
                            return oK;
                        else
                            return INVALID_CARD;
                    }
                }

        }
        else
            return INVALID_CARD;
    }

  //  EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData);

    EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
    {
        if ((termData->transAmount)==0 || (termData->transAmount)<0)
            return INVALID_AMOUNT;
        else
            return oK;
    }
    EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
    {
       if((termData->transAmount)> termData->maxTransAmount)
            return EXCEED_MAX_AMOUNT;
       else
        return oK;
    }
    EN_terminalError_t setMaxAmount(ST_terminalData_t *termData)
    {
        if(termData->maxTransAmount<=MIN_TRANS_AMOUNT)
            return INVALID_MAX_AMOUNT;
        else
            return oK;
    }
