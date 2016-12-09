project(BabyShell)
add_executable(main main.c virtuel.h virtuel.c pbm.h pbm.c)
target_link_libraries(main pthread)