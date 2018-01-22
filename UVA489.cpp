#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<cstring>
#define MAXSTR 10000

using namespace std;

int main()
{
    int i;
    while(cin>>i&&i!=-1)
    {
        cout<<"Round "<<i<<endl;
        char str1[MAXSTR];
        char str2[MAXSTR];
        int alp1[27];
        ///int alp2[27];
        memset(alp1,0,sizeof(alp1));
        ///memset(alp2,-1,sizeof(alp2));
        scanf("%s",&str1);
        scanf("%s",&str2);
        //printf("%s",str1);
        //printf("%s",str2);
        int num1=strlen(str1);
        int num2=strlen(str2);
        ///cout<<"num"<<num1<<" "<<num2<<endl;
        int mark1=0;///±»²Â²â´®ÊÇ·ñ²ÂÍê
        int mark2=num2;///²Â²â´®ÊÇ·ñÊäÍê
        for(int i=0;i<num1;++i)
        {
            int xx=str1[i]-'a';
            if(!alp1[xx]) mark1++;
            alp1[xx]=1;
        }
        int mark3=6;///²Â²âÊý6
        int i=0;
        while(mark3&&mark1&&mark2)
        {
             /// cout<<"mark1: "<<mark1<<" "<<endl;
            ///cout<<"mark2: "<<mark2<<" "<<endl;
            ///cout<<"mark3: "<<mark3<<" "<<endl;
            int yy=str2[i]-'a';
            //////!!!!!!!!!!!
            if(alp1[yy]>0)
            {
               alp1[yy]--;
               mark1--;
            }
            else
            {
                mark3--;
            }
            mark2--;
            i++;///!!!!
        }
        if(!mark1) cout<<"You win.\n";
        if(!mark2) cout<<"You checked out.\n";
        if(!mark3) cout<<"You lose.\n";







    }


}
