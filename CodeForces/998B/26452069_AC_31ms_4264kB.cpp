#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long

int n,b;
int a[105],dp[105][105];

int rec(int id, int even, int odd, int val)
{
    if(id>n)return 0;
    int &ret = dp[id][val];
    if(~ret)return ret;
    a[id]%2==0?even++:odd++;
    int one = 0, two = 0;
    if(even == odd)
    {
        if(id+1<=n && abs(a[id]-a[id+1])<=val)
        {
            one = 1 + rec(id+1, 0, 0, val-abs(a[id]-a[id+1]));
        }
    }
    two = rec(id+1, even, odd, val);
    ret= max(one, two);
    return ret;
}

int main()
{
    cloud_007;
    cin>>n>>b;
    memset(dp, -1, sizeof dp);
    for(int i=1;i<=n;i++)cin>>a[i];
    cout << rec(1,0,0,b) << endl;
}
