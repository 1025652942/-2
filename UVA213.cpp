/*
2017 4,4
字符串处理，最后的bug是getline后面要带getchar()
二进制流处理，每次读取n个二进制字节，输出数字
*/
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>

using namespace std;


char hea[100];

int readint(int n)
{
    int xx=0;
    int v=0;
    while(n--)
    {
        char ch1;
     while(1){
    char ch=getchar();
    ch1=ch;
    ///cout<<"ch "<<ch<<endl;
    if(ch!='\n'&&ch!='\r') break;
     }
     v=(v<<1)+(ch1-'0');
     ///cout<<"v "<<v<<endl;
    }
    return v;
}


int main()
{
while(cin.getline(hea,100))
{
    ///for(int i=0;i<strlen(hea);++i) cout<<hea[i]<<" ";
    ///cout<<endl;
    while(1)
    {
      int num=readint(3);
      ///cout<<"num "<<num<<endl;
      if(num==0) break;
    while(1)
    {
     int xx=readint(num);
     if(xx==(1<<num)-1) break;
     ///cout<<"xx"<<xx<<" ";
     int yy=(1<<num)-num-1+xx;
      cout<<hea[yy];
    }

    }
    cout<<endl;
   memset(hea,0,sizeof(hea));
   for(int i=0;i<strlen(hea);++i) cout<<hea[i]<<" ";
   ///cout<<"break";
   getchar();
}
return 0;
}
