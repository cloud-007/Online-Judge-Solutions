#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n,k;
    long long sum=0;
    scanf("%d%d",&n,&k);
    string s;
    cin>>s;
    map < char , int > mp;
    for(auto i : s)mp[i]++;
    priority_queue < int > pq;
    for(auto i : mp)
    {
        pq.push(i.second);
    }
    while(!pq.empty())
    {
        if(pq.top()<=k)
        {
            sum+=(ll)pq.top()*(ll)pq.top();
            k-=pq.top();
        }
        else
        {
            sum+=(ll)k*(ll)k;
            k=0;
        }
        if(k<=0)
            break;
        pq.pop();
    }
    printf("%lld\n",sum);
}
