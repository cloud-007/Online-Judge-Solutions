#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long

int n;
const int sz=1e6+50;
int ans=INT_MAX;
int dp[sz][10];

int rec(int val,int tot,int c)
{
    if(val==0)return 0;
    int &ret=dp[val][c];
    if(~ret)return ret;
    ret=INT_MAX;
    int x=val;
    while(x!=0)
    {
        int num=x%10;
        if(num)ret=min(ret,1+rec(val-num,tot+1,num));
        x/=10;
    }
    return ret;
}

int main()
{
    cloud_007;
    memset(dp, -1, sizeof dp);
    cin>>n;
    cout<< rec(n,0,0) <<endl;
}
