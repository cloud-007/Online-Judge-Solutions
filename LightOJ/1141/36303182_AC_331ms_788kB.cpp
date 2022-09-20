/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e3 + 5;
int tc, t, casee = 1, dp[N];
vector < int > primes, x[N];

bool isPrime(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0)return false;
    }
    return true;
}

void pre() {
    for(int i = 2; i < N; i++) {
        if(isPrime(i))primes.push_back(i);
    }
}

void preCalc(int n) {
    set < int > pr;
    int idx = n;
    for(auto i : primes) {
        if(n <= 1)break;
        while(n % i == 0) {
            pr.insert(i);
            n /= i;
        }
    }
    if(n > 1)pr.insert(n);
    for(auto j : pr) {
        if(j != idx)x[idx].push_back(j);
    }
}

void dfs(int n) {
    if(n >= t)return;

    for(auto i : x[n]) {
        if(dp[n] + 1 < dp[i + n]) {
            dp[i + n] = dp[n] + 1;
            dfs(n + i);
        }
    }
}


int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    pre();
    for(int i = 1; i <= 1000; i++)preCalc(i);
    cin >> tc;
    while(tc--) {
        int s; cin >> s >> t;
        if(s > t)swap(s, t);
        for(int i = s; i <= t; i++)dp[i] = INT_MAX;
        dp[s] = 0;
        dfs(s);
        if(dp[t] == INT_MAX)dp[t] = -1;
        cout << "Case " << casee++ << ": " << dp[t] << endl;
    }


    return 0;
}
