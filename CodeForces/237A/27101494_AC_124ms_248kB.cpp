/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int n, h, m, mx = 0;
map < pair < int, int >, int > mp;

int main()
{
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> h >> m, mp[ {h, m}]++, mx = max(mx, mp[ {h, m}]);

    cout << mx << endl;
    return 0;
}
