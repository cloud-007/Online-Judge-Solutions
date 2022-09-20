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
vector <pair<int, int>> vp;

int main() {
    freopen("icecream.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        int k; cin >> n >> k;
        for(int i = 1; i <= n; i++)cin >> a[i];
        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            vp.push_back({a[i], x});
        }
        sort(vp.begin(), vp.end());

        ll happiness = 0;
        int idx = k;

        while(k <= n && vp[idx - 1].F == vp[k - 1].F)++k;
        --k;
        vector < int > v;
        for(int i = 0; i < k; i++)v.push_back(vp[i].S);
        sort(v.rbegin(), v.rend());
        for(int i = 0; i < idx; i++)happiness += v[i];

        cout << vp[idx - 1].F << " " << happiness << endl;
        vp.clear();
    }


    return 0;
}
