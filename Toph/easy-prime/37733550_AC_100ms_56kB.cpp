/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e7 + 5;

int tc, n, c,  lp[N + 5];
vector < int > pr;
bool isPrime[N];

void sieve() {
    for(int i = 2; i <= N; ++i) {
        if(lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    for(auto i : pr)isPrime[i] = true;
}

#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

ordered_set os;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    sieve();

    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        if(isPrime[x])os.insert(i);
    }

    int q; cin >> q;
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int l, r; cin >> l >> r;
            int Ans = os.order_of_key(r + 1) - os.order_of_key(l);
            cout << Ans << endl;
        } else {
            int idx, val; cin >> idx >> val;
            if(os.find(idx) != os.end() && !isPrime[val]) {
                os.erase(idx);
            } else if(!(os.find(idx) != os.end()) && isPrime[val]) {
                os.insert(idx);
            }
        }
    }

    return 0;
}
