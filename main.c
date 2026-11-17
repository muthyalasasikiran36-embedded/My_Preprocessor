  1 #include"header.h"
  2 void main(int argc,char**argv)
  3 {
  4 if(argc!=2)
  5 {
  6 printf("USAGE:my_preprocessor file.c\n");
  7 return;
  8 }
  9 //creating output file name
 10 int c=strlen(argv[1]);
 11 char *out,*p;
 12 out=malloc(c+1);
 13 strcpy(out,argv[1]);
 14 p=strchr(out,'.');
 15 *(++p)='i';
 16 *(++p)='\0';
 17 //processing
 18 remove_comments(argv[1],"t1.c");
 19 include_header("t1.c","t2.c");
 20 append_header("t1.c","t2.c");
 21 sub_macro("t2.c",out);
 22 remove("t1.c");
 23 remove("t2.c");
 24 }