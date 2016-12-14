project(ExiaScreen)
add_executable(termstatic include.h processus.h processus.c main.c virtuel.h virtuel.c pbm.h pbm.c)
target_link_libraries(termstatic pthread m)