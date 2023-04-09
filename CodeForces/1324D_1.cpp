#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    scanf("%d",&n);
    int a[n+5],b[n+5];
    ll sum=0,same=0,cnt=0;
    vector < int > v, vp;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        if(a[i]==b[i])same++;
        else if(a[i]>b[i])v.push_back(abs(a[i]-b[i])),cnt++;
        else vp.push_back(a[i]-b[i]);
    }
    sort(v.rbegin(),v.rend());
    sort(vp.begin(),vp.end());
    int length=vp.size();
    for(auto i : v)
    {
        int j=0,k=length-1,mid,dd=-1;
        while(j<=k)
        {
            mid=(j+k)/2;
            if(vp[mid]+i<=0) j= mid + 1;
            else if(mid>0 && vp[mid-1]+i>0) k = mid -1;
            else { dd = mid ; break; }
        }
        if(dd!=-1)
            sum+=length-dd;
    }
    sum+=(cnt*(cnt-1))/2;
    sum+=(cnt*same);
    printf("%lld\n",sum);
}