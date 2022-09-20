/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N];
map < int, ll> mp;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    ll k; cin >> n >> k;
    while(n--) {
        int x, y; cin >> x >> y;
        mp[x] += y;
    }

    ll cur = 0;
    for(auto i : mp) {
        cur += i.S;
        if(cur >= k) {
            cout << i.F << endl;
            exit(0);
        }
    }


    return 0;
}
