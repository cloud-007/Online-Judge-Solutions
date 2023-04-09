#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,k;
    scanf("%lld%lld",&n,&k);
    set < long long > st;
    for(long long i=1; i*i<=n; i++)
        if(n%i==0)
        {
            st.insert(i),st.insert(n/i);
        }
    if(st.size()<k)
        puts("-1");
    else
    {
        for(auto i : st)
        {
            k--;
            if(k<=0)
            {
                printf("%lld\n",i);
                return 0;
            }
        }
    }
}
