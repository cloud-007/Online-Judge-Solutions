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
int tc, n, a[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    map < pair < int, int >, bool > mp;
    cin >> n;
    bool ok = false;
    for(int i = 1; i <= n; i++) {
        int x, d; cin >> x >> d;
        int y = x + d;
        if(mp[ {y, x}])ok = true;
        mp[ {x, y}] = true;
    }

    cout << (ok ? "YES" : "NO") << endl;


    return 0;
}
