#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,casee=1;
    scanf("%d",&tc);
    while(tc--)
    {
        map < int , int > mp;
        int n;
        scanf("%d",&n);
        int a[n+5];
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            mp[a[i]]=i;
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==i)continue;
            else
            {
                cnt++;
                int x=mp[i];
                a[x]=a[i];
                a[i]=i;
                mp[a[x]]=x;
            }
        }
        printf("Case %d: %d\n",casee++,cnt);
    }
}
