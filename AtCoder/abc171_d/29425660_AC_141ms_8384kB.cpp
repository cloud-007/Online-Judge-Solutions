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
int tc, n, a[sz], b, q, c;
map < int, int > mp;
ll Ans = 0;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
        Ans += a[i];
    }
    cin >> q;
    while(q--) {
        cin >> b >> c;
        ll del = (ll)mp[b] * (ll)b;
        Ans -= del;
        Ans += (ll)mp[b] * (ll)c;
        mp[c] += mp[b];
        mp[b] = 0;
        cout << Ans << endl;
    }


    return 0;
}
