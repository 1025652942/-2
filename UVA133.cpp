/*
���� wrong answer��ԭ��δ֪
�Ĺ�һ��˼·��ȷʵ��������ֱ���������ͺ�
ѭ������
�ر�ע�⣺������˳�������˳�򣬱�����ǰ�к󣬰��źã�

*/
#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;


int ss[29];
int n,num;

int nex(int nx,int step,int mark)
{
    int i=0;

    while(num&&i<=step)
        {
         ///cout<<"i nx "<<i<<" "<<nx<<endl;
         if(ss[nx]!=0) {i++;}
         if(i==step) return nx;
         nx=(nx+mark+n)%n;
         ///cout<<"i 2 nx"<<i<<" "<<nx<<endl;
         }

}
void put(int xx)
{
   printf("%3d",xx);

}

int main()
{
    int k,m;
    while(cin>>n>>k>>m)
    {
        if(n==0&&k==0&&m==0) break;
    num=n;
    for(int i=1;i<=n;++i) ss[i-1]=i;///�±�ȡģ�����Ϊ0~n-1
    ///֪��
    int n1=0;int n2=n-1;
    while(num>0)
    {
        int x1=nex(n1,k,1);
        int x2=nex(n2,m,-1);
        //cout<<"x1x2 :"<<x1<<" "<<x2<<endl;
        if(x1!=x2)
        {
            //cout<<"ans :";
            put(ss[x1]);
            put(ss[x2]);
        ss[x1]=0;
        ss[x2]=0;
        n1=x1;
        n2=x2;
        num-=2;
        }
        else
        {
            //cout<<"ans :";
            put(ss[x1]);
        ss[x1]=0;
        n1=x1;
        n2=x2;
        num-=1;
        }

          if(num)cout<<",";
  /*     cout<<n1<<" "<<n2<<endl;
        for(int i=0;i<n;++i)
            cout<<ss[i]<<" ";
        cout<<endl;
*/
    }

    }


return 0;
}
