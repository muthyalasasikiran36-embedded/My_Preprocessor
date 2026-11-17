  1 #include"header.h"
  2 extern void append_header(char*ip,char*op)
  3 {
  4 FILE *in,*out;
  5 in=fopen(ip,"r");
  6 out=fopen(op,"a");
  7 char s[1000];
  8 while(fgets(s,1000,in))
  9 if(!strstr(s,"#include<"))
 10 break;
 11 fputs(s,out);
 12 while(fgets(s,1000,in))
 13 fputs(s,out);
 14 fclose(in);
 15 fclose(out);
 16 }