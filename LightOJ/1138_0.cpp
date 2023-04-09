#include<bits/stdc++.h>
using namespace std;

int cnttrail(int n)
{
    if(n<0)return INT_MAX;
    int cnt=0;
    for(int i=5;(n/i)>0;i*=5)
    {
        cnt+=(n)/i;
    }
    if(!cnt)cnt=INT_MAX;
    return cnt;
}


int main()
{
    //freopen("in.txt","r",stdin);
    int tc,casee=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,ans=INT_MAX,x;
        scanf("%d",&n);
        int lo=1,hi=8*1e8+50;
        while(lo<hi)
        {
            int mid=(lo+hi)/2;
            x=cnttrail(mid);
            if(x<n)lo=mid+1;
            else if(x>n)hi=mid-1;
            else
            {
                while(cnttrail(mid)==n)
                {
                    ans=mid;
                    mid--;
                }
                break;
            }
        }
        printf("Case %d: ",casee++);
        if(ans==INT_MAX)printf("impossible\n");
        else printf("%d\n",ans);
    }
}
