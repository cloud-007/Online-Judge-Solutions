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
ll pref[N];

void pre() {
    for(int i = 1; i < N; i++) {
        for(int j = 1; j * j <= i; j++) {
            if(i % j)continue;
            if(j & 1)pref[i] += j;
            if(j != (i / j) && (i / j) & 1)pref[i] += (i / j);
        }
        pref[i] += pref[i - 1];
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    pre();
    cin >> tc;
    while(tc--) {
        int l, r; cin >> l >> r;
        cout << pref[r] - pref[l - 1] << endl;
    }

    return 0;
}
