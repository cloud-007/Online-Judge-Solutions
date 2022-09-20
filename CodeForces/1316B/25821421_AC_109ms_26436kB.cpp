#include<bits/stdc++.h>
using namespace std;

bool cmp(pair < string , int > a, pair < string , int > b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int tc;
    cin>>tc;
    vector < pair < string, int >> vp;
    while(tc--)
    {
        int n,d=2;
        cin>>n;
        string s;
        cin>>s;
        vp.clear();
        string temp;
        vp.push_back({s,1});
        for(int i=1; i<n-1; i++)
        {
            string x=s.substr(i,n-i);
            string y=s.substr(0,i);
            if(n%2==0 && i%2)
                reverse(y.begin(),y.end());
            else if(n%2 && i%2==0)
                reverse(y.begin(),y.end());
            x+=y;
            vp.push_back({x,i+1});
        }
        reverse(s.begin(),s.end());
        vp.push_back({s,n});
        sort(vp.begin(),vp.end(),cmp);
        cout<<vp[0].first<<endl;
        cout<<vp[0].second<<endl;
    }
}