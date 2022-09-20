#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,casee=1;
    cin>>tc;
    while(tc--)
    {
        string s;
        cin>>s;
        string ans="";
        ans+=s;
        reverse(s.begin(),s.end());
        for(int i=1;i<s.size();i++)
            ans+=s[i];
        cout<<"Case "<<casee++<<": "<<ans<<endl;
    }
}
