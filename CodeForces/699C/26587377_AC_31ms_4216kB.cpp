#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long

int n, dp[105][4], a[105];

int rec(int id, int pre)
{
    if(id >= n)return 0;
    int &ret = dp[id][pre];
    if(~ret)return ret;
    ret = 0;
    if(a[id] == 0)
    {
        ret += 1 + rec(id + 1, 0);
    }
    else if(a[id] == 1)
    {
        if(pre == 1)ret += 1 + rec(id + 1, 0);
        else ret += rec(id + 1, 1);
    }
    else if(a[id] == 2)
    {
        if(pre == 2)ret += 1 + rec(id + 1, 0);
        else ret += rec(id + 1, 2);
    }
    else
    {
        if(pre == 0)ret = min(rec(id + 1, 1), rec(id + 1, 2));
        else if(pre == 1)ret +=  rec(id + 1, 2);
        else ret +=  rec(id + 1, 1);
    }
    return ret;
}
int main()
{
    cloud_007;
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(int i = 0 ; i < n; i++)
    {
        cin >> a[i];
    }
    cout << rec(0, 0) << endl;
}
