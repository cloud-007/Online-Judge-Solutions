/*Editorial*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int tc,n,time,temp;
    scanf("%d",&tc);
    while(tc--)
    {
        ll sum=0;
        int ans=0,prev=0;
        scanf("%d%d",&n,&time);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&temp);
            sum+=temp;
            if(prev<temp && sum-temp<=time)
            {
                ans=i;
                prev=temp;
            }
        }
        if(sum<=time)ans=0;
        printf("%d\n",ans);
    }
}
