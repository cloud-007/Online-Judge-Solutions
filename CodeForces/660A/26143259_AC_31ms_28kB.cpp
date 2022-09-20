#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int tc,n;
    scanf("%d",&n);
    int a[n+5],cnt=0;
    vector < int > v;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        v.push_back(a[i]);
        if(__gcd(a[i],a[i+1])!=1)
        {
            cnt++;
            v.push_back(1);
        }
    }
    v.push_back(a[n]);
    printf("%d\n",cnt);
    for(auto i : v)
        printf("%d ",i);
    printf("\n");
}
