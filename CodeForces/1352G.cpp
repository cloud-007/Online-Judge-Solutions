/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int tc, n;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        cin >> n;
        if(n <= 3) {
            cout << -1 << endl;
            continue;
        }
        int m;
        n % 2 == 0 ? m = n - 1 : m = n;
        for(m; m >= 1; m -= 2)cout << m << " ";
        cout << "4 2 ";
        for(m = 6; m <= n; m += 2)cout << m << " ";
        cout << endl;
    }

    return 0;
}
