#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(string s,string b)
{
    if(s.size()==b.size())
        return s[0]<b[0];
    return s.size()<b.size();
}

int main()
{
    int tc;
    cin>>tc;
    map < string , int > mp;
    vector < string > v;
    while(tc--)
    {
        v.clear();
        mp.clear();
        bool fl=true;
        int n;
        cin>>n;
        while(n--)
        {
            string s,x="";
            cin>>s;
            v.push_back(s);
        }
        sort(v.begin(),v.end(),cmp);
        for(auto i : v)
        {
            string x="";
            for(auto j : i)
            {
                x+=j;
                if(mp[x])
                {
                    fl=false;
                    break;
                }
            }
            mp[i]=1;
        }
        puts(fl?"YES":"NO");
    }
}
