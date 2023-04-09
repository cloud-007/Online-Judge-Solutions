/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e7;
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

    for(int i = 3; i <= N; i += 2) {
        if(lp[i] == i &&  i + 2 == lp[i + 2]) {
            vp.push_back({i, i + 2});
        }
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    sieve();
    while(cin >> n) {
        printf("(%d, %d)\n", vp[n - 1].F, vp[n - 1].S);
    }

    return 0;
}
