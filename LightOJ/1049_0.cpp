/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 100 + 5;
int tc, n, casee = 1, a[N], mp[N][N];
vector < int > x[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {

        cin >> n;
        for(int i = 1; i <= n; i++) {
            int u, v, c; cin >> u >> v >> c;
            mp[u][v] = c;
            x[u].push_back(v);
            x[v].push_back(u);
        }

        int clockWise = 0, antiClockWise = 0;

        int curCity = 1, nextCity = x[1][0];

        for(int i = 1; i <= n; i++) {
            if(mp[curCity][nextCity] == 0)clockWise += mp[nextCity][curCity];

            int temp = x[nextCity][0];
            if(temp == curCity)temp = x[nextCity][1];

            curCity = nextCity; nextCity = temp;
        }

        curCity = 1, nextCity = x[1][1];

        for(int i = 1; i <= n; i++) {
            if(mp[curCity][nextCity] == 0) antiClockWise += mp[nextCity][curCity];

            int temp = x[nextCity][0];
            if(temp == curCity)temp = x[nextCity][1];

            curCity = nextCity; nextCity = temp;
        }

        cout << "Case " << casee++ << ": " << min(clockWise, antiClockWise) << endl;

        memset(mp, 0, sizeof mp);
        for(int i = 1; i <= n; i++)x[i].clear();
    }


    return 0;
}
