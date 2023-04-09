#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    if(s.size()<25)
    {
        puts("-1");
        return 0;
    }
    map < char, int > mp;
    set < char > st;
    int cnt=0,j=0;
    bool fl=false;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='?')
            cnt++;
        else if(!mp[s[i]])
            mp[s[i]]=i,st.insert(s[i]);
        else
        {
            while(j<=mp[s[i]])
            {
                if(s[j]=='?')
                    cnt--;
                else
                {
                    st.erase(s[j]);
                }
                j++;
            }
            mp[s[i]]=i;
            st.insert(s[i]);
        }
        if(st.size() + cnt==26)
        {
            fl=true;
            break;
        }
    }
    if(fl)
    {
        j=0;
        vector < char > v;
        for(char c='A'; c<='Z'; c++)
            if(!st.count(c))
                v.push_back(c);
        if(v.empty())
            v.push_back('A');
        for(auto i : s)
        {
            if(i=='?')
            {
                printf("%c",v[j]);
                j++;
                if(j==v.size())j=0;
            }
            else
                printf("%c",i);
        }
    }
    else
        puts("-1");
}
