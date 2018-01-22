#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<conio.h>
using namespace std;

int main()
{
    char rev[36]="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
    char ch[100];
    while(scanf("%s",&ch))
    {
        printf("%s -- ",ch);
        int len=strlen(ch);
        int mark1=1;
        for(int i=0;i<len/2;++i)
        {
            if(ch[len-1-i]!=ch[i]) {mark1=0;break;}
        }
        int mark2=1;
        for(int i=0;i<len/2;++i)
        {
            char xx=ch[i];
            char yy;
            if(xx<='Z'&&xx>='A')  yy=rev[xx-'A'];
            else if(xx<='9'&&xx>='1')  yy=rev[26+xx-'1'];
             ///cout<<"yy: "<<yy<<endl;
            if(ch[len-1-i]!=yy) {mark2=0;break;}
        }
        ///cout<<mark1<<" "<<mark2<<endl;

        if(mark1&&mark2) cout<<"is a mirrored palindrome."<<endl;
        else if((!mark1)&&mark2) cout<<"is a mirrored string."<<endl;
        else if(mark1&&(!mark2)) cout<<"is a regular palindrome."<<endl;
        if((!mark1)&&(!mark2)) cout<<"is not a palindrome."<<endl;
        memset(ch,0,sizeof(ch));
    }


}
