/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1000 + 5;
int tc, n, casee = 1, a, b, dp[N];
vector < int > primeFactor;
bool primes[N];

bool isPrime(int n) {
    for(int i = 2; i * i <= n; i++)if(n % i == 0)return false;
    return true;
}

void initPrimes() {
    for(int i = 2; i <= 1000; i++) {
        if(isPrime(i))primes[i] = true;
    }
}

int dfs(int u, vector < int > primeFactor) {
    if(u == b)return 0;
    if(u > b)return 500;
    int &ret = dp[u];
    if(~ret)return ret;
    ret = 500;
    for(auto i : primeFactor) {
        int a = u + i;
        if(a <= b) {
            vector < int > newPrimeFactor;
            for(int i = 2; i * i <= a; i++) {
                if(a % i == 0) {
                    if(primes[i])newPrimeFactor.push_back(i);
                    if((a / i) != i && primes[a / i])newPrimeFactor.push_back(a / i);
                }
            }
            ret = min(ret, 1 + dfs(u + i, newPrimeFactor));
        }
    }
    return ret;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    initPrimes();
    cin >> tc;
    while(tc--) {
        cin >> a >> b;
        memset(dp, -1, sizeof dp);

        primeFactor.clear();

        for(int i = 2; i * i <= a; i++) {
            if(a % i == 0) {
                if(primes[i])primeFactor.push_back(i);
                if((a / i) != i && primes[a / i])primeFactor.push_back(a / i);
            }
        }

        int Ans = dfs(a, primeFactor);

        cout << "Case " << casee++ << ": " << (Ans >= 500 ? -1 : Ans) << endl;

    }

    return 0;
}
