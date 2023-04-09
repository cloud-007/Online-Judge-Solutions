#include<bits/stdc++.h>
using namespace std;


void solve(long long n)
{
    long long cnt=0;
    if(n%2==0)
    {
        cnt+=n/2;
    }
    else
    {
        int d=0;
        set < long long > st;
        for(long long i=3;i*i<=n;i+=2)
        {
            if(n%i==0)
            {
                st.insert(i),st.insert(n/i);
            }
        }
        if(st.size())
        {
            for(auto i : st)
            {
                if(i&1)
                {
                    n-=i;
                    cnt++;
                    if(n>0)
                        cnt+=(n/2);
                    break;
                }
            }
        }
        else
            cnt++;
    }
    cout<<cnt<<endl;
}

int main()
{
    cin.tie(0),cout.tie(0);
    long long int n;
    cin>>n;
    solve(n);
}
