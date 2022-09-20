/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
int tc, n, dis[sz], indegree[sz], remote[sz], x;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            dis[i] = indegree[i] = remote[i] = 0;
        }
        ll mx = 0;
        remote[0] = 1;

        for(int nxt = 2; nxt <= n + 1; nxt++) {
            cin >> x;
            if(indegree[x] == 1) {
                int val = dis[x] % 2 ? 1 : 0;
                remote[val]--;
            }
            indegree[x]++;
            indegree[nxt]++;
            dis[nxt] = dis[x] + 1;
            int val = dis[nxt] % 2 ? 1 : 0;
            remote[val]++;
            int now = max(remote[0], remote[1]);
            mx += now;
        }
        cout << mx << endl;
    }


    return 0;
}
