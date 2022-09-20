/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N], m;
vector < int > bachelor, spinster;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    while(cin >> n >> m && (n || m)) {
        for(int i = 1; i <= n; i++)cin >> a[i];
        for(int i = 1; i <= m; i++) {
            int x; cin >> x;
        }
        sort(a + 1, a + n + 1);
        cout << "Case " << casee++ << ": ";
        if(n > m)cout << n - m << " " << a[1] << endl;
        else cout << "0" << endl;
    }


    return 0;
}
