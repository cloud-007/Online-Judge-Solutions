/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"



///1= taxi, 2= pizza, 3= girl
int tc, n;
string s, number;
int dp[105][5], t = 0, p = 0, g = 0;
map < int, string > mp;

int main()
{
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    memset(dp, 0, sizeof dp);
    cin >> tc;
    for(int i = 1; i <= tc; i++)
    {
        cin >> n >> s;
        mp[i] = s;
        while(n--)
        {
            cin >> number;
            int last = 10, chuto = 0, boro = 0;
            for(auto i : number)
            {
                if(i != '-')
                {
                    int val = i - '0';
                    if(val < last)chuto++;
                    else if(val > last)boro++;
                    last = val;
                }
            }
            if(chuto == 1 && boro == 0)dp[i][1]++, t = max(t, dp[i][1]);
            else if(chuto == 6 && boro == 0)dp[i][2]++, p = max(p, dp[i][2]);
            else dp[i][3]++, g = max(g, dp[i][3]);
        }
    }
    int ok = 0;
    cout << "If you want to call a taxi, you should call: ";
    for(int i = 1; i <= tc; i++)
    {
        if(dp[i][1] == t)
        {
            if(ok)cout << ", ";
            cout << mp[i];
            ok = 1;
        }
    }
    cout << "." << endl;
    cout << "If you want to order a pizza, you should call: ";
    ok = 0;
    for(int i = 1; i <= tc; i++)
    {
        if(dp[i][2] == p)
        {
            if(ok)cout << ", ";
            cout << mp[i];
            ok = 1;
        }
    }
    cout << "." << endl;
    cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
    ok = 0;
    for(int i = 1; i <= tc; i++)
    {
        if(dp[i][3] == g)
        {
            if(ok)cout << ", ";
            cout << mp[i];
            ok = 1;
        }
    }
    cout << ".";
    return 0;
}
