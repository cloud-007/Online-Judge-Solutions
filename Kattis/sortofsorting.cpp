#include<bits/stdc++.h>
using namespace std;

struct R{
    string s;
    int id;
    bool operator<(R a)const
    {
        if(s[0]==a.s[0] && s[1]==a.s[1])
            return id<a.id;
        else if(s[0]==a.s[0])
            return s[1]<a.s[1];
        return s[0]<a.s[0];
    }
};

vector < R > v;

int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        v.clear();
        string x;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            v.push_back({x,i});
        }
        sort(v.begin(),v.end());
        for(auto i : v)cout<<i.s<<endl;
        puts("");
    }
}
