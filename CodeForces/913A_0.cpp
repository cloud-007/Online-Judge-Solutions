/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

ll n, m, val=1;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) {
        val *= 2;
        if(val > m) {
            cout << m << endl;
            return 0;
        }
    }
    cout  << m%val <<endl;

    return 0;
}
