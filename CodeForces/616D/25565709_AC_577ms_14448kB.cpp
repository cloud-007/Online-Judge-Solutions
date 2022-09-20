#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,cnt=0,mx=0,l=-1,r=-1;
    scanf("%d%d",&n,&k);
    int a[n+5];
    map < int, int > mp;
    int j=1,i=1;
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(i; i<=n; i++)
    {
        if(!mp[a[i]])
        {
            cnt++;
            if(cnt>k)
            {
                if(l==-1 && r==-1)
                {
                    l=j,r=i-1;
                    mx=abs(l-r);
                }
                else
                {
                    if(abs(j-(i-1))>mx)
                    {
                        l=j,r=i-1;
                        mx=abs(l-r);
                    }
                }
                while(cnt>k)
                {
                    mp[a[j]]--;
                    if(mp[a[j]]==0)
                        cnt--;
                    j++;
                }
            }
        }
        mp[a[i]]++;
    }
    if(l==-1 && r==-1)
        l=j,r=i-1;
    else if(abs(j-(i-1))>mx)
    {
        l=j,r=i-1;
    }
    printf("%d %d",l,r);
}
