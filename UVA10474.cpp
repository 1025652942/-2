#include<iostream>
#include<algorithm>

using namespace std;



int main()
{  int cases=0;
    while(++cases)
    {

    int a[10020];
    int n,m;
    cin>>n>>m;
    if(n==0&&m==0) break;
    else cout<<"CASE# "<<cases<<":\n";
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    int temp;
    for(int j=1;j<=m;++j)
    {
        cin>>temp;
        int ans=lower_bound(a+1,a+n+1,temp)-a;

        if(ans!=n+1&&a[ans]==temp) cout<<temp<<" found at "<<ans<<endl;
        else cout<<temp<<" not found\n";
    }

    }
    return 0;
}
