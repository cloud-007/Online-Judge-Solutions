#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long


int main()
{
    cloud_007;
    int n,cnt=0,a,last=0;
    cin>>n;
    vector < int > v;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a<0)
        {
            if(cnt==2)
            {
                v.push_back(i-last-1);
                last=i-1;
                cnt=1;
            }
            else
                cnt++;
        }
    }
    if(last!=n)v.push_back(n-last);
    cout<<v.size()<<endl;
    for(auto i : v)cout<<i<<" ";
    cout<<endl;
}
