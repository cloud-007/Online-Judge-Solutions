/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 105;
int n, m, u, v, mp[sz];

int main()
{
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    memset(mp, 0, sizeof mp);
    pair < int, int > ans = {-1, -1};
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        mp[u]++;
        mp[v + 1]--;
    }
    for(int i = 1; i <= n; i++)
    {
        mp[i] += mp[i - 1];
        if(mp[i]==0 || mp[i]>1)
        {
            if(ans.F==-1)
            {
                ans.F=i, ans.S=mp[i];
                break;
            }
        }
    }
    if(~ans.F)cout<<ans.F<<" "<<ans.S<<endl;
    else cout << "OK" <<endl;


    return 0;
}
