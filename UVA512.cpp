#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<conio.h>
using namespace std;
typedef struct
{
    char ope[5];
    int A;
    int x[20];

}cmd;

cmd ss[1003];
int r,c;
int n;

void simulate(int &row,int &col)
{
    for(int i=1;i<=n;++i)
    {

        ///cout<<"i: "<<i<<"row: "<<row<<"col: "<<col<<" \n";
        if(row==-1) return;
        if(ss[i].ope[0]=='E')
        {
          if(row==ss[i].x[1]&&col==ss[i].x[2])
          {row=ss[i].x[3];col=ss[i].x[4];}
          if(row==ss[i].x[3]&&col==ss[i].x[4])
          {row=ss[i].x[1];col=ss[i].x[2];}
        }
        else if(ss[i].ope[0]=='D'&&ss[i].ope[1]=='R')
        {
            int mark=0;
            for(int j=1;j<=ss[i].A;++j)
            {
                if(ss[i].x[j]<row) mark++;
                if(ss[i].x[j]==row) {row=-1;col=-1;}
            }
            if(row!=-1) row-=mark;

        }
        else if(ss[i].ope[0]=='D'&&ss[i].ope[1]=='C')
        {
            int mark=0;
            for(int j=1;j<=ss[i].A;++j)
            {
                if(ss[i].x[j]<col) mark++;
                if(ss[i].x[j]==col) {row=-1;col=-1;}
            }
            if(col!=-1) col-=mark;
        }
        else if(ss[i].ope[0]=='I'&&ss[i].ope[1]=='R')
        {
            int mark=0;
            for(int j=1;j<=ss[i].A;++j)
            {
                if(ss[i].x[j]<=row) mark++;
            }
            row+=mark;

        }
        else if(ss[i].ope[0]=='I'&&ss[i].ope[1]=='C')
        {
            int mark=0;
            for(int j=1;j<=ss[i].A;++j)
            {
                if(ss[i].x[j]<=col) mark++;
            }
            col+=mark;
        }

    }


}

int main()
{

int kk=0;
    while(cin>>r>>c&&r)
    {
        kk++;
        cout<<"Spreadsheet #"<<kk<<endl;
         cin>>n;
         for(int i=1;i<=n;++i)
         {
         scanf("%s",ss[i].ope);
         if(ss[i].ope[0]=='E') {cin>>ss[i].x[1]>>ss[i].x[2]>>ss[i].x[3]>>ss[i].x[4];ss[i].A=4;}
         else
         {
             cin>>ss[i].A;
             for(int j=1;j<=ss[i].A;++j)
                cin>>ss[i].x[j];
         }

       /* cout<<ss[i].A<<" \n";
         for(int k=1;k<=ss[i].A;++k) cout<<ss[i].x[k]<<" ";
         cout<<endl;*/
         }
         int ques;
         cin>>ques;
         for(int l=1;l<=ques;++l)
         {

             int row,col;
             cin>>row>>col;
             cout<<"Cell data in ("<<row<<","<<col<<") ";
             simulate(row,col);
             if(row==-1&&col==-1) cout<<"GONE\n";
             else cout<<"moved to ("<<row<<","<<col<<")"<<endl;
         }







    }





return 0;
}
