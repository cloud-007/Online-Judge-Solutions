#include<bits/stdc++.h>
using namespace std;
string s;

stack < string > st;

void run(int i,int k)
{

    string x="";
    int cnt=0;
    for(i=i+1;i<s.size();i++)
    {
        x+=s[i];
        cnt++;
        if(cnt==k)
        {
            st.push(x);
            x="";
            cnt=0;
        }
    }
}

bool check()
{
    string now;
    if(st.size())
    {
        now=st.top();
        st.pop();
    }
    else
        return false;
    while(st.size())
    {
        string x=st.top();
        st.pop();
        bool fl=false;
        if(x[x.size()-1]==now[0])
            fl=true;
        else
        {
            return false;
        }
        for(int i=0; i<now.size()-1; i++)
        {
            if(x[i]==now[i+1])
                int ok;
            else
            {
                return false;
            }
        }
        now=x;
    }
    return true;
}

int main()
{
    string ans="";
    cin>>s;
    map < char, int > mp,temp;
    for(auto i : s)
        mp[i]++;
    for(int i=0; i<s.size(); i++)
    {
        ans+=s[i];
        while(!st.empty())
            st.pop();
        st.push(ans);
        if(s.size()%(i+1)==0)
        {
            run(i,i+1);
            if(check())
            {
                printf("%d\n",i+1);
                return 0;
            }
        }
    }
}
