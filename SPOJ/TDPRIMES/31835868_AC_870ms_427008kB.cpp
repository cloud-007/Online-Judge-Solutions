/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e8;
int tc, n, c, a[N + 5], lp[N + 5];
vector < int > pr;

void sieve() {
    for(int i = 2, cnt = 1; i <= N; ++i) {
        if(lp[i] == 0) {
            if(cnt % 100 == 1)cout << i << endl;
            lp[i] = i, ++cnt;
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
    To_Infinity_And_Beyond;
    sieve();


    return 0;
}
