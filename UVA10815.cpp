 #include<iostream>
 #include<stdio.h>
 #include<string>
 #include<cstring>
 #include<set>
 using namespace std;



 int main()
 {
     set<string> ss;
     set<string> ::iterator it;
     char a[100];
     char ch;
     string b;

     int i=0;
     while(scanf("%c",&ch)!=EOF)
     {
        ///cout<<i<<" ";
        if(isalpha(ch))a[i++]=ch;
         else
         {
             a[i]='\0';
         int j=0;
         if(i!=0)
         {
          while(a[j]!='\0')
          {
          if(a[j]>='A'&&a[j]<='Z') a[j]=a[j]+32;
          j++;
          }
          b=a;
          ///cout<<b<<endl;
          ss.insert(b);
         }
           i=0;
         }
     }
      for(it=ss.begin();it!=ss.end();it++)
      {
          cout<<*it<<endl;
      }

     return 0;
 }
