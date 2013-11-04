#include<stdio.h>
#include<string.h>
#include<conio.h>
   void main()
       {
            char c,a[30],ch[40],count[30]={0},x=0,y=0;
            FILE *fp;
            int i=65,n,j=0;
            clrscr();
            printf("ENTER THE NAME OF FILE");
            scanf("%s",a);
            fp=fopen(a,"w");
            while((c=getchar())!='*')
                  {
                       putc(toupper(c),fp);
                  }
            fclose(fp);
            fp=fopen(a,"r");
            while(j<26)
                  {
                       rewind(fp);
                       while((c=getc(fp))!=EOF)
                             {
                                if((int) c==i)
                                    {
                                        count[j]=count[j]+1;
                                    }
                            }
                      i++;
                      j++;
                  }
            fclose(fp);
            clrscr();
            gotoxy(1,2);
            for(i=65;i<=90;i++)
                  {
                      printf("%c",i);
                  }
            getch();
            x=1,y=3;
            gotoxy(x,y);
            for(i=0;i<=26;i++)
                  {
                       y=3;
                       for(j=0;j<count[i];j++)
                                {
                                    gotoxy(x,y);
                                    printf("*");
                                    y++;
                                }
                       x=x+1;
                 }
             getch();
 }
