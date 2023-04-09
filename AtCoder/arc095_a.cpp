#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,a,x;
    cin>>n;
    x=n/2;
    x--;
    vector < int > v,t;
    set < int > st;
    while(n--)
    {
        cin>>a;
        v.push_back(a);
        t.push_back(a);
    }
    sort(v.rbegin(),v.rend());
    int ans=v[x];
    for(auto i : t)
    {
        if(i>=ans)
            cout<<v[x+1]<<endl;
        else
            cout<<v[x]<<endl;
    }
}
