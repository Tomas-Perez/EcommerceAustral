set(core_SRCS BookInformation.c ProductBook.c Cart.c Invoice.c Student.c Bank.c BankAccount.c Transaction.c Provider.c Admin.c SupportStaff.c UserDatabase.c UserLog.c OperationCertificate.c Subject.c Subject.h College.c College.h)
add_library(core ${core_SRCS})
add_executable(exe main.c)
target_link_libraries(exe core)