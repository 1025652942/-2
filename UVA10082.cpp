 #include<iostream>
 #include<stdio.h>
 #include<string>
 #include<cstring>
 #include<set>
 using namespace std;


int main()
{
    char s[]="`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
    char ch;
    ///int k=0;
    while((ch=getchar())!=EOF)
    {
        ///k++;
        ///cout<<k;
        ///cout<<k<<" "<<ch;
        if(ch==' '||ch=='\n'||ch=='\r') printf("%c",ch);

         int i;
        for( i=0;i<strlen(s);i++)
        {
            if(s[i]==ch) {cout<<s[i-1];break;}
        }
        ///if(i==strlen(s)) printf("%c",ch);


    }


}
