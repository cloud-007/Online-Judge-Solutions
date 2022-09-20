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
ll tc, n, q, a[sz], mp[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)cin >> a[i];
    while(q--) {
        int l, r; cin >> l >> r;
        mp[l]++, mp[r + 1]--;
    }

    priority_queue < ll > pq;

    for(int i = 1; i <= n; i++) {
        mp[i] += mp[i - 1];
        pq.push(mp[i]);
    }
    sort(a + 1, a + n + 1);

    ll Ans = 0;

    while(!pq.empty()) {
        ll now = pq.top() * a[n--];
        pq.pop();
        Ans += now;
    }

    cout << Ans << endl;


    return 0;
}
