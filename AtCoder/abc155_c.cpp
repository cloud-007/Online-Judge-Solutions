#include<bits/stdc++.h>
using namespace std;
int main()
{
    map < string , int > mp;
    int n;
    scanf("%d",&n);
    int mx=0;
    while(n--)
    {
        string s;
        cin>>s;
        mp[s]++;
        mx=max(mx,mp[s]);
    }
    for(auto i : mp)
    {
        if(i.second==mx)
        {
            cout<<i.first<<endl;
        }
    }
    cout<<endl;
}
