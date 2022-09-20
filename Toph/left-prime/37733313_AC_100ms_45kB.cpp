/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e7 + 5;

int tc, casee = 1, n, c, a[N + 5], lp[N + 5];
vector < int > pr;

void sieve() {
    for(int i = 2; i <= N; ++i) {
        if(lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    sieve();
    cin >> tc;
    while(tc--) {
        cin >> n;
        int Ans = lower_bound(pr.begin(), pr.end(), n) - pr.begin();
        cout << Ans << endl;
    }


    return 0;
}
