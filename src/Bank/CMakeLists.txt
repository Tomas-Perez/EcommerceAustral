set(BANK_SRC Bank.c BankAccount.c OperationCertificate.c Transaction.c)
add_library(bank ${BANK_SRC})