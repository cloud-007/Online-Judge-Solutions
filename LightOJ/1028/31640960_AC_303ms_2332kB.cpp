/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1000010;
ll tc, n, prime[N], cnt, casee = 1;
bool vis[N];

void sieve() {
    prime[cnt++] = 2;
    for(ll i = 3; i < N; i += 2) {
        if(!vis[i]) {
            prime[cnt++] = i;
            for(ll j = i * i; j < N; j += i * 2)
                vis[j] = true;
        }
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
        ll Ans = 1;
        for(int i = 0; i < cnt && prime[i] * prime[i] <= n ; ++i) {
            if(n % prime[i] == 0) {
                ll k = 1;
                while(n % prime[i] == 0) {
                    n /= prime[i];
                    ++k;
                    if(n <= 1)break;
                }
                Ans *= k;
            }
        }
        if(n != 1)Ans *= 2;
        --Ans;
        cout << "Case " << casee++ << ": " << Ans << Endl;
    }



    return 0;
}
