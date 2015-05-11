#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>

char srchstr[10];
int flag=0;

void srch(char s[20])
{
struct dirent *d;
DIR *dir;
int c;
char ss[256]="\0";

if((dir=opendir(s))==NULL)
{
return;
}
       while(d=readdir(dir))
       {
//printf("Path is : %s/%s\n",s,d->d_name);

               if(!strcmp(d->d_name,srchstr))
               {
                       if(flag==0)
                       {
                               printf("File found.\n");
                               flag=1;
                       }
                      // printf("Inode number is : %d\n",d->d_ino);
                       printf("Path is : %s/%s\n",s,d->d_name);
               }

               if(strcmp(d->d_name,".") && strcmp(d->d_name,".."))
               {
                       strcpy(ss,s);
                       strcat(ss,"/");
                       strcat(ss,d->d_name);

                       srch(ss);
               }

       }

       if((c=closedir(dir))==-1)
       {
               printf("Unable to close file.\n");
               exit(1);
       }
       return;
}

int main()
{
       char str[50]="/home";

      // printf("Enter the name of the file to be searched: ");
       scanf("%s",srchstr);
//printf("hi//..\t\t");
       srch(str);

      if(flag==0)
       {
               printf("File not found.\n");
       }
       return;
}
