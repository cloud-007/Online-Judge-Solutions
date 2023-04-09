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

struct R {
    int l, r;
    bool operator <(R a)const {
        if(l == a.l)return r > a.r;
        return l < a.l;
    }
};
vector < R > v;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        int m; cin >> n >> m;
        v.resize(n);
        for(auto &x : v)cin >> x.l >> x.r;
        sort(v.begin(), v.end());
        while(m--) {
            int x; cin >> x;
            if(x >= v.back().r)cout << -1 << endl;
            else {
                R pt = {x, INT_MAX};
                auto it = lower_bound(v.begin(), v.end(), pt) - v.begin();

                if(it == 0) {
                    cout << v[it].l - x << endl;
                } else {
                    if(v[it - 1].l <= x && v[it - 1].r > x)cout << 0 << endl;
                    else cout << v[it].l - x << endl;
                }

            }
        }
    }


    return 0;
}

