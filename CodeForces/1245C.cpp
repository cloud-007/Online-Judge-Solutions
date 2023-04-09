#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int sz=1e5+50;
const int mod=1e9+7;
ll mp[sz];
void init()
{
    mp[1]=1;
    mp[2]=2;
    mp[3]=3;
    for(int i=4; i<=100000; i++)
    {
        mp[i]=mp[i-1]+mp[i-2];
        mp[i]%=mod;
    }
}

int main()
{
    init();
    string s;
    cin>>s;
    ll sum=1;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='u' || s[i]=='n')
        {
            int cnt=0;
            char c=s[i];
            while(i<s.size() && s[i]==c)
                cnt++,i++;
            i--;
            sum*=mp[cnt];
            sum%=mod;
        }
        if(s[i]=='m' || s[i]=='w')
        {
            puts("0");
            return 0;
        }
    }
    printf("%lld\n",sum);
}
