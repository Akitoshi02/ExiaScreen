project(ExiaScreen)
add_executable(terminter include.h processus.h processus.c main.c virtuel.h virtuel.c pbm.h pbm.c)
target_link_libraries(terminter pthread m)