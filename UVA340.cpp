#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#define MAXN 1000


using namespace std;
int main()
{
    int ss[MAXN];
    int bb[MAXN];
    int times[10];
    int n;
     while(cin>>n)
    {
        memset(ss,0,sizeof(ss));
        memset(times,0,sizeof(times));
        for(int i=1;i<=n;++i) {cin>>ss[i];if(ss[i]>='1'&&ss[i]<='9')times[ss[i]]++;}
        while(1)
        {
            int mark1=0;int mark2=0;
          for(int i=1;i<=n;++i)
            {
                cin>>bb[i];
                if(bb[i]==ss[i])
                {
                    mark1++;
                    bb[i]=0;
                    times[ss[i]]--;
                }

            }
            if(bb[0]==0) break;
          for(int i=1;i<=n;++i)
          {
              if(bb[i]!=0)
              {
                  if(times[bb[i]]>0) mark2++;
              }

          }
          cout<<"("<<mark1<<","<<mark2<<")";


        }


    }





}
