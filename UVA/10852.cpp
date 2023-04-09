/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e5;
int tc, n, c, a[N + 5], lp[N + 5];
vector < int > pr;
vector < pair < int, int >> vp;

void sieve() {
    for(ll i = 2; i <= N; ++i) {
        if(lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for(ll j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // cloud_007
    To_Infinity_And_Beyond;
    sieve();
    cin >> tc;
    while(tc--) {
        cin >> n;
        auto pos = lower_bound(pr.begin(), pr.end(), n / 2) - pr.begin();
        if(n >= pr[pos] * 2)++pos;
        cout << pr[pos] << endl;
    }

    return 0;
}
