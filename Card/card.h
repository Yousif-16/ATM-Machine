#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
#define NULL 0

typedef unsigned char Uint8;

typedef enum EN_cardError_t
{
OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;
typedef struct ST_cardData_t
{
Uint8 cardHolderName[25];
Uint8 primaryAccountNumber[20];
Uint8 cardExpirationDate[6];
}ST_cardData_t;

EN_cardError_t getCardHolderName(ST_cardData_t *cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData);
EN_cardError_t getCardPAN(ST_cardData_t *cardData);





#endif // CARD_H_INCLUDED
