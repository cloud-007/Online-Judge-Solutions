/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, pref[N], a[N];

struct R {
    int defPower, gold;
    bool operator <(R a)const {
        if(defPower == a.defPower)return gold > a.gold;
        return defPower < a.defPower;
    }
};

vector < R > v;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    int m; cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> a[i];
    v.resize(m);
    for(auto &x : v)cin >> x.defPower >> x.gold;
    sort(v.begin(), v.end());

    for(int i = 0; i < m; i++) {
        pref[i] = v[i].gold;
        if(i)pref[i] += pref[i - 1];
    }

    for(int i = 1; i <= n; i++) {
        R pt = {a[i] + 1, INT_MAX};
        auto it = lower_bound(v.begin(), v.end(), pt) - v.begin();
        cout << pref[it - 1] << " ";
    }


    return 0;
}
