#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        string s,t,p,x="";
        cin>>s>>t>>p;
        map < char , int > mp;
        for(auto i : p)mp[i]++;
        int k=0;
        for(int i=0;i<t.size();i++)
        {
            if(k<s.size() && t[i]==s[k])
            {
                k++;
            }
            else
                x+=t[i];
        }
        bool fl=true;
        for(auto i : x)
        {
            if(mp[i]>0)mp[i]--;
            else
            {
                fl=false;
                break;
            }
        }
        puts(fl && k==s.size()?"YES":"NO");
    }
}
