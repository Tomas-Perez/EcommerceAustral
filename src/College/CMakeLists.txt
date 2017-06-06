set(COLLEGE_SRC BookInformation.c College.c Student.c Subject.c)
add_library(college ${COLLEGE_SRC})
target_link_libraries(college ecommerce)