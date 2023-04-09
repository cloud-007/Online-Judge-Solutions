#include<bits/stdc++.h>
using namespace std;
#define ll long long

map < ll , int > mp;
vector < ll > v;
void init()
{
    int times=0;
    ll n=2;
    while(n*n<=1e12)
    {
        v.push_back(n*n);
        mp[n*n]=1;
        n++;
    }
}

int main()
{
    init();
    ll n;
    scanf("%lld",&n);
    set < ll > st;
    set < ll > ::reverse_iterator it;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            st.insert(i),st.insert(n/i);
        }
    }
    for(it=st.rbegin();it!=st.rend();it++)
    {
        bool fl=true;
        for(auto i : v)
        {
            if(i>*it)break;
            if(*it%i==0)
            {
                fl=false;
                break;
            }
        }
        if(fl)
        {
            printf("%lld\n",*it);
            return 0;
        }
    }
}
