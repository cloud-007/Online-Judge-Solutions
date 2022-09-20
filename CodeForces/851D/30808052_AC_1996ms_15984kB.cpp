/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 5e5 + 5, N = 1e6 + 5;
ll tc, n, x, y, a[sz], lp[N + 1];
vector<int> pr, v;
map < int, int > mp;
vector < pair < int, int >> max_freq;

void sieve() {
    pr.push_back(2);
    for(int i = 3; i * i <= N; i++) {
        if(lp[i])continue;
        pr.push_back(i);
        for(int j = (ll)i * i; j <= N; j += i * 2)lp[i] = 1;
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    sieve();
    map < int, int > mp;
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i++)cin >> a[i];
    ll Ans = 0, odd = 0, mx = 0;
    for(int i = 1; i <= n; i++) {
        int c = a[i];
        for(auto j : pr) {
            if(c <= 1)break;
            int add = 0;
            while(c > 1 && c % j == 0) {
                c /= j;
                add = 1;
            }
            if(add)mp[j]++;
        }
        if(c > 1)mp[c]++;
    }
    for(auto i : mp)max_freq.push_back({i.S, i.F});
    sort(max_freq.rbegin(), max_freq.rend());

    int cnt = 0;
    v.push_back(2);
    for(auto i : max_freq) {
        if(cnt >= 100)break;
        v.push_back(i.S);
        ++cnt;
    }

    Ans = n * x;
    for(auto j : v) {
        ll now = 0, del;
        for(int i = 1; i <= n; i++) {
            if(a[i] % j == 0)continue;
            ll tot = a[i] / j;
            ++tot;
            tot *= j;
            del = tot - a[i];
            del *= y;
            now += min(del, x);
        }
        Ans = min(Ans, now);
    }

    cout << Ans << endl;


    return 0;
}
