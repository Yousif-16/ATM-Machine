#ifndef TERMINAL_H_INCLUDED
#define TERMINAL_H_INCLUDED
#include"../Card/card.h"
//macros
#define MIN_TRANS_AMOUNT 0

typedef unsigned char Uint8;
typedef float f32;

#define NULL 0
extern ST_cardData_t;


typedef enum EN_terminalError_t
{
oK, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t ;

typedef struct ST_terminalData_t
{
float transAmount;
float maxTransAmount;
Uint8 transactionDate[11];
}ST_terminalData_t;

//functions
    EN_terminalError_t getTransactionDate(ST_terminalData_t *termData);
    EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData);
    EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData);
    EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData);
    EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData);
    EN_terminalError_t setMaxAmount(ST_terminalData_t *termData);





#endif // TERMINAL_H_INCLUDED
