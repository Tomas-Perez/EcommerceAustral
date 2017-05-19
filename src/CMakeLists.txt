set(core_SRCS BookInformation.c ProductBook.c Cart.c Cart.h Invoice.c Invoice.h Student.c Student.h test.c)
add_library(core ${core_SRCS})
add_executable(exe main.c)
target_link_libraries(exe core)