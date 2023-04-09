#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int l=0,r=s.size()-1,left=0,right=0,c1=0,c2=0,cnt=0;
    while(l<r)
    {
        if(s[l]=='['){left = 1 ; l++; break;}
        else cnt++;
        l++;
    }
    while(r>=l)
    {
        if(s[r]==']'){ right =1 ; r--; break;}
        else cnt++;
        r--;
    }
    while(l<=r)
    {
        if(s[l]==':'){c1=1 ; l++; break;}
        else cnt++;
        l++;
    }
    while(r>=l)
    {
        if(s[r]==':'){c2=1; r--; break;}
        else cnt++;
        r--;
    }
    while(l<=r)
    {
        if(s[l]!='|')cnt++;
        l++;
    }
    if(left && right && c1 && c2)cnt=(int)s.size()-cnt;
    else cnt=-1;
    printf("%d\n",cnt);
}
