#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED
#include"../Card/card.h"
#include"../Terminal/terminal.h"



typedef unsigned char Uint8;
typedef float f32;
typedef unsigned long int Uint32;

#define NULL 0

typedef enum EN_transState_t
{
APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, INTERNAL_SERVER_ERROR
}EN_transState_t;

typedef enum EN_serverError_t
{
ok, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE
}EN_serverError_t ;

typedef struct ST_transaction_t
{
ST_cardData_t cardHolderData;
ST_terminalData_t terminalData;
EN_transState_t transState;
Uint32 transactionSequenceNumber;
}ST_transaction_t;
ST_transaction_t transaction_arr [255];
typedef enum Card_State
{
    RUNNING,
    BLOCKED
}Account_State;

typedef struct ST_accountsDB_t
{
f32 balance;
Account_State state;
Uint8 primaryAccountNumber[20];
}ST_accountsDB_t;
ST_accountsDB_t accounts_arr [255];

    EN_transState_t recieveTransactionData(ST_transaction_t *transData);
    EN_serverError_t isValidAccount(ST_cardData_t *cardData);
    EN_serverError_t isAmountAvailable(ST_terminalData_t *termData);
    EN_serverError_t saveTransaction(ST_transaction_t *transData);
    EN_serverError_t getTransaction(Uint32 transactionSequenceNumber, ST_transaction_t *transData);
    void Account_DB(void);




#endif // SERVER_H_INCLUDED
