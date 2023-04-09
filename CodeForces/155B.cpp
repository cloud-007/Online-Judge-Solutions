/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int n, u, v, mx = 0, check =  0;
vector < pair < int, int >> vp;
bool cmp(pair < int, int > a, pair < int, int > b)
{
    if(a.S == b.S)return a.F > b.F;
    return a.S > b.S;
}

int main()
{
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> u >> v;
        vp.push_back({u, v});
        mx = max(mx, u);
        check = max(check, v);
    }
    if(!check)
    {
        cout << mx << endl;
        return 0;
    }
    sort(vp.begin(), vp.end(), cmp);
    int ans = 0, can = -1;

    for(auto i : vp)
    {
        if(can == -1 )
        {
            can = i.S;
            ans += i.F;
        }
        else if(can)
        {
            can --;
            can += i.S;
            ans+=i.F;
        }
        else break;
    }

    cout << ans << endl;
    return 0;
}
