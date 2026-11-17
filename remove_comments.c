 1 #include"header.h"
  2 void remove_comments(char*ip,char*op)
  3 {
  4 FILE*in;
  5 in=fopen(ip,"r");
  6 if(in==0)
  7 {
  8 printf("file not found!!!\n");
  9 return;
 10 }
 11 FILE *out;
 12 out=fopen(op,"w");
 13 char ch1,ch2;
 14 while((ch1=fgetc(in))!=EOF)
 15 {
 16 if(ch1=='/')
 17 {
 18 ch2=fgetc(in);
 19 if(ch2=='/')
 20 {
 21 while((ch1=fgetc(in))!='\n' && ch1!=EOF);
 22 fputc('\n',out);
 23 }
 24 else if(ch2=='*')
 25 {
 26 while((ch1=fgetc(in))!=EOF)
 27 {
 28 ch2=fgetc(in);
 29 if((ch1=='*') && (ch2=='/'))
 30 break;
 31 }
 32 }
 33 else
 34 {
 35 fputc(ch1,out);
 36 fputc(ch2,out);
 37 }
 38 }
 39 else
 40 fputc(ch1,out);
 41 }
 42 fclose(in);
 43 fclose(out);
 44 }