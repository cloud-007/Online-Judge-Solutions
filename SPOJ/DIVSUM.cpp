#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long

int tc,n,ans;
int main()
{
    cloud_007;
    set < int > st;
    cin>>tc;
    while(tc--)
    {
        st.clear(),ans=0;
        cin>>n;
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                st.insert(i);
                st.insert(n/i);
            }
        }
        for(auto i : st)
            ans+=i;
        cout<<ans+1<<endl;
    }
}
