  1 #include<stdio.h>
  2 #include<string.h>
  3 #include<stdlib.h>
  4 extern void remove_comments(char*ip,char*op);
  5 extern void include_header(char*ip,char*op);
  6 extern void replace_header(char*ip,char*op);
  7 extern void append_header(char*ip,char*op);
  8 typedef struct macro
  9 {
 10 char name[100];
 11 char body[1000];
 12 }m;
 13 extern void sub_macro(char *ip,char*op);