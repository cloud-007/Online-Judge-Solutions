#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    map < int , int > mp;
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]=='V' && s[i+1]=='K')mp[i]=1,mp[i+1]=1;
    }
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]==s[i+1] && !mp[i] && !mp[i+1])
        {
            if(s[i]=='V')
            {
                s[i+1]='K';
            }
            else s[i]='V';
            break;
        }
    }
    int cnt=0;
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]=='V' && s[i+1]=='K')cnt++;
    }
    cout<<cnt<<endl;
}
