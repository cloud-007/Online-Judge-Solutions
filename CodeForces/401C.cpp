#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if(n-1>m)
        puts("-1");
    else if((n+1)*2<m)
        puts("-1");
    else
    {
        string ans="";
        while(n || m)
        {
            if(n<m && n && m)
            {
                ans+="110";
                n--,m-=2;
            }
            else if(n==m && n && m)
            {
                ans+="10";
                n--,m--;
            }
            else if(m<n && m && n)
                ans+="01",m--,n--;
            else if(m)
                ans+="1",m--;
            else if(n)
                ans+="0",n--;
        }
        cout<<ans<<endl;
    }
}
