#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    vector < int > v(n);
    for(auto &x : v)scanf("%d",&x);
    sort(v.begin(),v.end());
    int mid=n/2;
    long long sum=0;
    if(v[mid]>=k)
    {
        while(mid >=0 && v[mid]>=k)
        {
            sum+=abs(v[mid]-k);
            mid--;
        }
    }
    else
    {
        while(mid<n && v[mid]<k)
        {
            sum+=abs(v[mid]-k);
            mid++;
        }
    }
    printf("%lld\n",sum);
}
