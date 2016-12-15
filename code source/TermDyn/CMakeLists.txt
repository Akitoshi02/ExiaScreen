project(ExiaScreen)
add_executable(termdyn include.h processus.h processus.c main.c virtuel.h virtuel.c pbm.h pbm.c)
target_link_libraries(termdyn pthread m)