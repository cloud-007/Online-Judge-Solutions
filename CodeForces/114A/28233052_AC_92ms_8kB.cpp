/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

ll k, n;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> k>>n;
    for(ll i = 1;; i++) {
        ll val=1;
        for(int j=1;j<=i;j++)val*=k;
        if(val > n)break;
        else if(val == n) {
            cout << "YES" << endl;
            cout << i - 1 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}
