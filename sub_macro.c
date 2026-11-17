 1 #include"header.h"
  2 extern void sub_macro(char *ip,char*op)
  3 {
  4 FILE *in,*out;
  5 m macro[1000];
  6 in =fopen(ip,"r");
  7 out=fopen(op,"w");
  8 int c=0;
  9 char s[1000];
 10 while(fgets(s,1000,in))
 11 {
 12 if(strncmp(s,"#define",7)==0)
 13 {
 14 if(sscanf(s,"#define %s %[^\n]",macro[c].name,macro[c].body)==2){
 15 c++;}
 16 }
 17 else
 18 {
 19 int i,l;
 20 char *p,t[1000];
 21 for(i=0;i<c;i++)
 22 {
 23 if((p=strstr(s,macro[i].name))!=0)
 24 {
 25 l=p-s;
 26 strncpy(t,s,l);
 27 t[l]='\0';
 28 strcat(t,macro[i].body);
 29 strcat(t,(p+strlen(macro[i].name)));
 30 strcpy(s,t);
 31 }
 32 }
 33 fputs(s,out);
 34 }
 35 }
 36 fclose(in);
 37 fclose(out);
 38 }