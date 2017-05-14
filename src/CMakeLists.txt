set(core_SRCS BookInformation.c ProductBook.c)
add_library(core ${core_SRCS})
add_executable(exe main.c)
target_link_libraries(exe core)