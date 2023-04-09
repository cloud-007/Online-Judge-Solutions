/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

vector < int > primes;

void sieve(int N) {

    bool prime[N + 5];

    for(int i = 2; i <= N; i++)prime[i] = true;

    for(int i = 4; i <= N; i += 2)prime[i] = false;

    for(ll i = 3; i <= N ; i += 2) {
        if(prime[i]) {
            for(ll j = i * i; j <= N; j += i * 2) {
                prime[j] = false;
            }
        }
    }

    for(int i = 2; i <= N; i++) {
        if(prime[i]) {
            primes.push_back(i);
        }
    }

}

int segmentedSieve(ll l, ll r) {

    bool isPrime[r - l + 10];

    for(int i = 0; i < r - l + 5; i++)isPrime[i] = true;

    if(l == 1)isPrime[0] = false;

    for(int i = 0; (ll)primes[i] * primes[i] <= r; i++) {
        int cp  = primes[i];
        ll currentNumber = ((l + cp - 1) / cp) * cp;
        for(ll j = currentNumber; j <= r; j += cp)
            isPrime[j - l] = false;
        if(currentNumber == cp)isPrime[currentNumber - l] = true;
    }

    int Count = 0;

    for(int i = 0; i < r - l + 1; i++) {
        if(isPrime[i])++Count;
    }

    return Count;

}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    sieve(sqrt(INT_MAX) + 100);
    ll l, r, casee = 1;
    int tc; cin >> tc;
    while(tc--) {
        cin >> l >> r;
        cout << "Case " << casee++ << ": " << segmentedSieve(l, r) << endl;
    }


    return 0;
}
