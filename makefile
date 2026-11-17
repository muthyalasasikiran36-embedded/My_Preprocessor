  1 compiler = cc
  2 flag = -c
  3
  4 exe: main.o remove_comments.o replace_header.o append_header.o sub_macro.o
  5         $(compiler) $^ -o $@
  6
  7 main.o: main.c
  8         $(compiler) $(flag) $^
  9
 10 remove_comments.o: remove_comments.c
 11         $(compiler) $(flag) $^
 12
 13 replace_header.o: replace_header.c
 14         $(compiler) $(flag) $^
 15
 16 append_header.o: append_header.c
 17         $(compiler) $(flag) $^
 18
 19 sub_macro.o: sub_macro.c
 20         $(compiler) $(flag) $^
 21
 22 clean:
 23         @echo "cleaning up..."
 24         @rm -rv *.o exe
