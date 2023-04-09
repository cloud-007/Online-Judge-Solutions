#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n>>s;
    int cnt=0;
    for(int i=1; i<s.size(); i++)
    {
        if(s[i]==s[i-1] && i<s.size()-1 && s[i]==s[i+1])
        {
            cnt++;
            if(s[i]=='G')
                s[i]='R';
            else if(s[i]=='B')
                s[i]='G';
            else
                s[i]='B';
        }
        else if(s[i]==s[i-1])
        {
            cnt++;
            if(i+1<s.size())
            {
                if(s[i+1]=='G')
                {
                    if(s[i]=='B')
                        s[i]='R';
                    else if(s[i]=='R')
                        s[i]='B';
                }
                else if(s[i+1]=='B')
                {
                    if(s[i]=='G')
                        s[i]='R';
                    else if(s[i]=='R')
                        s[i]='G';
                }
                else
                {
                    if(s[i]=='B')
                        s[i]='G';
                    else if(s[i]=='G')
                        s[i]='B';
                }
            }
            else
            {
                if(s[i]=='G')
                    s[i]='R';
                else if(s[i]=='B')
                    s[i]='G';
                else if(s[i]=='R')
                    s[i]='B';
            }
        }
    }
    cout<<cnt<<endl;
    cout<<s<<endl;
}
