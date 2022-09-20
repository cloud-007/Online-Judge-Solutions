#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int sz=1e5+50;
int a[sz];
vector < ll > v;
ll sum=0,del=0;

int main()
{
    int n,t,mx=0;
    scanf("%d%d",&n,&t);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
        if(sum<=t)
            mx=i;
        v.push_back(sum);
    }
    for(int i=1;i<=n;i++)
    {
        del+=a[i];
        int pos=lower_bound(v.begin(),v.end(),(ll)del+(ll)t)-v.begin();
        //printf("%d %d\n",i,pos);
        if(v[pos]==(ll)del+(ll)t)pos++;
        int x=pos-i;
        mx=max(mx,x);
    }
    printf("%d\n",mx);
}
