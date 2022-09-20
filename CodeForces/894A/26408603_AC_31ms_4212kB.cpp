#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long

const int sz=105;
int dp[sz][5],ans=0;
string s;

int main()
{
    cloud_007;
    memset(dp, 0, sizeof dp);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='A' && dp[i][2])
            dp[i][1]++;
        else if(s[i]=='Q')
            dp[i][2]++;
        dp[i+1][1]=dp[i][1];
        dp[i+1][2]=dp[i][2];
    }
    int n=s.size()-1;
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]=='A' && dp[i][2]>0 && dp[i][1]>0)
        {
            ans += dp[i][2] * (dp[n][2]-dp[i][2]);
        }
    }
    cout<<ans<<endl;
}
