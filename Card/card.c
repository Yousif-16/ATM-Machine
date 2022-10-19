#include "card.h"

//declare Var

ST_cardData_t CardData;
Uint8 Name[25]={0};
Uint8 Expiry_Date[6]={0};
Uint8 PAN[20]={0};
Uint8 Lenght=0;
Uint8 i=0;
EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
    //printf("%s\n",cardData->cardHolderName);
int counter=0;

//printf("%s\n",cardData->cardHolderName);

//while(cardData->cardHolderName!='\0')
//printf("%d\n",Lenght);
for (int i=0;i<Lenght;i++)
{
    if (((cardData->cardHolderName[i]>='A')&&(cardData->cardHolderName[i]<='Z')) || ((cardData->cardHolderName[i]>='a')&&(cardData->cardHolderName[i]<='z'))|| (cardData->cardHolderName[i]==' ') || (cardData->cardHolderName[i]=='\0'))

       {
           counter++;
        }// return OK;
    else
        return WRONG_NAME;
}
//printf("%d\n",counter);

   if(Lenght>=24)
       return WRONG_NAME;
    else if (Lenght<16)
        return WRONG_NAME;
    else if (Lenght==0)
        return WRONG_NAME;
    else if(counter==Lenght)
    return OK;
    else
        return OK;

}
/*--------- Test Of function 1------------*/
/* test cases :
* 1- 16<Length<25 && not equal Null
* 2-No special character and numbers letters only
*/
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
   /* printf(" %s\n ",cardData->cardExpirationDate);
    printf("%s\n",cardData->cardHolderName);
    printf("%d\n",Lenght);
    printf("%d\n",(cardData->cardExpirationDate[0]-48));*/
    for (int i=0;i<Lenght;i++)
{
    int counter1;
    if (((cardData->cardExpirationDate[i]>='0')&&(cardData->cardExpirationDate[i]<='9')) || (cardData->cardExpirationDate[i]=='/'))

       {
           counter1++;
        }// return OK;
    else
        return WRONG_EXP_DATE;
}
    if(cardData->cardExpirationDate[2]!='/')
        return WRONG_EXP_DATE;
   else if (Lenght<3)
        return WRONG_EXP_DATE;
   else if (Lenght>6)
        return WRONG_EXP_DATE;
        else
        {
            while (cardData->cardExpirationDate[0]==48)

        {
            if((cardData->cardExpirationDate[1]-48)<10 && (cardData->cardExpirationDate[1]-48)!=0)
                {
                    return OK;
                    //break;
                }
            else

                {
                    return WRONG_EXP_DATE;
                   // break;
                }
        }
        while (cardData->cardExpirationDate[0]==49)

        {
            if((cardData->cardExpirationDate[1]-48)<3)
            {
                return OK;
                break;
            }
            else
            {
                return WRONG_EXP_DATE;
                break;
            }
        }
            if (cardData->cardExpirationDate[3]==50)
            {
                 if((cardData->cardExpirationDate[4]-48)>2 && ((cardData->cardExpirationDate[4]-48)<9))
                 {
                     return OK;

                 }
                 else
                 {
                     return WRONG_EXP_DATE;
                 }

            }
            else
            return WRONG_EXP_DATE;
        }
}
/*Test cases :
 * 1- length =5
 * 2- third character must be '\'
 * 3- numbers only are accepted
 */

EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
   // printf("%d\n",Lenght);

       for (int i=0;i<Lenght;i++)
{
    int counter1;
    if (((cardData->primaryAccountNumber[i]>='0')&&(cardData->primaryAccountNumber[i]<='9')) || ((cardData->primaryAccountNumber[i]=='\0')))

       {
           counter1++;
        }// return OK;
    else
        return WRONG_PAN;
}
    if (Lenght>19)
        return WRONG_PAN;
    else if (Lenght<16)
        return WRONG_PAN;
    else if (Lenght== NULL)
        return WRONG_PAN;
        else
        return OK;


}
