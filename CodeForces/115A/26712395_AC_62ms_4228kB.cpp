#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long

int par[2005];

int main()
{
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    map < int, int > mp;
    int n, a, mx = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a;
        par[i] = a;
    }
    for(int i = 1; i <= n; i++)
    {
        int cnt = 1;
        int now = par[i];
        while(now != -1)
        {
            cnt++;
            now = par[now];
        }
        mx = max(mx, cnt);
    }
    cout << mx << endl;
    return 0;
}
