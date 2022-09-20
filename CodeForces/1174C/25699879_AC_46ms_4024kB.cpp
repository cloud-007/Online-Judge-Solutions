#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,cn=1;
    scanf("%d",&n);
    int ans[n+5];
    memset(ans,0,sizeof ans);
    for(int i=2;i<=n;i++)
    {
        bool fl=false;
        for(int j=i;j<=n;j+=i)
        {
            if(!ans[j])
            {
                fl=true;
                ans[j]=cn;
            }
        }
        if(fl)cn++;
    }
    for(int i=2;i<=n;i++)
        printf("%d ",ans[i]);
}
