 1 #include"header.h"
  2 extern void replace_header(char*ip,char*op);
  3 void include_header(char *ip,char *op)
  4 {
  5 FILE *in;
  6 in=fopen(ip,"r");
  7 int c=0,c1=0;
  8 char ch;
  9 while((ch=fgetc(in))!=EOF)
 10 {
 11 c++;
 12 if(ch=='\n')
 13 {
 14 if(c>c1)
 15 c1=c;
 16 c=0;
 17 }
 18 }
 19 rewind(in);
 20 char file[100]="/usr/include/";
 21 int len=strlen(file);
 22 char* s=malloc(c1+1);
 23 while(fgets(s,c1+1,in))
 24 {
 25 if(strstr(s,"main()"))
 26 break;
 27 if(strstr(s,"include<"))
 28 {
 29 int i=9;
 30 while(s[i]!='>')
 31 {
 32 strncat(file,s+i,1);
 33 i++;
 34 }
 35 replace_header(file,op);
 36 strcpy(file+len,file+strlen(file));
 37 }
 38 }
 39 fclose(in);
 40 }
 41 void replace_header(char*ip,char*op)
 42 {
 43 FILE *in,*out;
 44 in=fopen(ip,"r");
 45 out=fopen(op,"a");
 46 char s[1000];
 47 while(fgets(s,1000,in))
 48 fputs(s,out);
 49 fclose(in);
 50 fclose(out);
 51 }