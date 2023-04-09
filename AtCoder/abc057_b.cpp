/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 55;
int tc, n, m, w, a[sz], b[sz], c[sz], d[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> a[i] >> b[i];
    for(int i = 1; i <= m; i++)cin >> c[i] >> d[i];

    for(int i = 1; i <= n; i++) {
        int ans = INT_MAX, id = -1;
        for(int j = 1; j <= m; j++) {
            int now = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if(now < ans) {
                ans = now;
                id = j;
            }
        }
        cout << id << endl;
    }



    return 0;
}
