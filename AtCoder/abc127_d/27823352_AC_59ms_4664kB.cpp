/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 1e5 + 5;
int tc, n, a, m, l, r;

struct R {
    int tot, chn;
    bool operator<(R a)const {
        if(chn == a.chn)return tot > a.tot;
        return chn > a.chn;
    }
};

vector < R > vp;
priority_queue < int > pq;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        pq.push(-a);
    }

    while(m--) {
        cin >> l >> r;
        vp.push_back({l, r});
    }

    sort(vp.begin(), vp.end());

    for(auto i : vp) {
        int val = i.chn, tot = i.tot;
        if(val <= (-pq.top()))break;
        while(tot--) {
            int pq_val = -pq.top();
            pq.pop();
            if(pq_val < val) {
                pq_val = val;
                pq.push(-pq_val);
            } else {
                pq.push(-pq_val);
                break;
            }
        }
    }
    ll ans = 0;
    while(!pq.empty()) {
        ans += (-pq.top());
        pq.pop();
    }
    cout << ans << endl;

    return 0;
}
