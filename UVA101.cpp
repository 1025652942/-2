///模拟 查找a，b的位置 2n 2
///将a上所有积木复原 v[i].push_back(i);
///将a落到b上
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>

using namespace std;

vector<int>ss[27];
vector<int>::iterator it,it1,it2;

///pile over
void deal1(int a1,int a2,int n)
{
    ///cout<<"1"<<endl;
    int loc1=-1;int loc2=-1;
    for(int i=0;i<n;++i)
    {
        if(find(ss[i].begin(),ss[i].end(),a1)!=ss[i].end()) {loc1=i;it1=find(ss[i].begin(),ss[i].end(),a1);}
        if(find(ss[i].begin(),ss[i].end(),a2)!=ss[i].end()) {loc2=i;it2=find(ss[i].begin(),ss[i].end(),a2);}
    }
     if(loc1==-1||loc2==-1) return;
     if(loc1==loc2) return;
     ///不放回

     for(it1;it1!=ss[loc1].end();)
     {
       ss[loc2].push_back( (*it1) );
       it1=ss[loc1].erase(it1);
     }
}
void deal2(int a1,int a2,int n)
{
    ///cout<<"2\n";
    ///move over
    int loc1=-1;int loc2=-1;
    for(int i=0;i<n;++i)
    {
        if(find(ss[i].begin(),ss[i].end(),a1)!=ss[i].end()) {loc1=i;it1=find(ss[i].begin(),ss[i].end(),a1);}
        if(find(ss[i].begin(),ss[i].end(),a2)!=ss[i].end()) {loc2=i;it2=find(ss[i].begin(),ss[i].end(),a2);}
    }
     if(loc1==-1||loc2==-1) return;
     if(loc1==loc2) return;

     ss[loc2].push_back(*it1);
     it1=ss[loc1].erase(it1);
     for(it1;it1!=ss[loc1].end();)
     {
         ss[*it1].push_back(*it1);
         it1=ss[loc1].erase(it1);
     }
}
void deal3(int a1,int a2,int n)
{
   ///cout<<"3\n";
    ///pile onto
    int loc1=-1;int loc2=-1;
    for(int i=0;i<n;++i)
    {
        if(find(ss[i].begin(),ss[i].end(),a1)!=ss[i].end()) {loc1=i;it1=find(ss[i].begin(),ss[i].end(),a1);}
        if(find(ss[i].begin(),ss[i].end(),a2)!=ss[i].end()) {loc2=i;it2=find(ss[i].begin(),ss[i].end(),a2);}
    }
     if(loc1==-1||loc2==-1) return;
     if(loc1==loc2) return;
   it2++;
     for(it2;it2!=ss[loc2].end();)
     {
         ss[*it2].push_back(*it2);
         it2=ss[loc2].erase(it2);
     }
     for(it1;it1!=ss[loc1].end();)
     {
         ss[loc2].push_back(*it1);
         it1=ss[loc1].erase(it1);
     }


}
void deal4(int a1,int a2,int n)
{
    ///cout<<"4\n";
    ///move onto
    int loc1=-1;int loc2=-1;
    for(int i=0;i<n;++i)
    {
        if(find(ss[i].begin(),ss[i].end(),a1)!=ss[i].end()) {loc1=i;it1=find(ss[i].begin(),ss[i].end(),a1);}
        if(find(ss[i].begin(),ss[i].end(),a2)!=ss[i].end()) {loc2=i;it2=find(ss[i].begin(),ss[i].end(),a2);}
    }
     if(loc1==-1||loc2==-1) return;
     if(loc1==loc2) return;
    it2++;
     for(it2;it2!=ss[loc2].end();)
     {
         ss[*it2].push_back(*it2);
         it2=ss[loc2].erase(it2);
     }
     ss[loc2].push_back(*it1);
     it1=ss[loc1].erase(it1);
     for(it1;it1!=ss[loc1].end();)
     {
         ss[*it1].push_back(*it1);
         it1=ss[loc1].erase(it1);
     }


}



void display(int n)
{
    for(int i=0;i<n;++i)
    {
        cout<<i<<":";
        if(!ss[i].empty())
        {
           for(it=ss[i].begin();it<ss[i].end();it++)
            cout<<" "<<*it ;
        }
        cout<<endl;
    }

}






int main()
{
    int n;
    cin>>n;
    ///getchar();

    ///初始化
    for(int i=0;i<n;++i)
    {
        ss[i].push_back(i);
    }
    ///display(n);

        char temp[15];
        string s1;
        string s2;
        bool mark1;
        bool mark2;
        int a1;
        int a2;
        string c="quit";
        string c1="move";
        string c2="pile";
        string c3="onto";
        string c4="over";

        while (cin >> s1)
        {

             if(s1==c) break;
             cin>> a1 >> s2 >> a2;
            /*for(int i=0;i<4;++i)
            {
                s1[i]=a[i];
            }*/
            ///cout<<"s1"<<s1<<"\n";
            if(s1==c1) mark1=0;
            else if(s1==c2) mark1=1;
            /*
            for(int i=0;i<4;++i)
            {
                s2[i]=a[6+i];
            }*/
            ///cout<<"s2"<<s2<<"\n";
            if(s2==c3) mark2=0;
            else if(s2==c4) mark2=1;
             ///cout<<"marks"<<mark1<<" "<<mark2<<" \n";
            ///a2=(int)a[12]-(int)'0';
            if(mark1&&mark2) deal1(a1,a2,n);///pile over
            else if(!mark1&&mark2) deal2(a1,a2,n);///move over
            else if(mark1&&!mark2) deal3(a1,a2,n);///pile onto
            else if(!mark1&&!mark2) {deal4(a1,a2,n);}///move onto
           ///cout<<"end\n";
           ///display(n);
        }

        display(n);

     return 0;

}
