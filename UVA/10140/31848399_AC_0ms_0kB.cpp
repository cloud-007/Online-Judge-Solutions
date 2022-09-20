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
pair < int, int > mx, mn;

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

void segmentedSieve(ll l, ll r) {

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

    int pre = -1;

    for(int i = 0; i < r - l + 1; i++) {
        if(isPrime[i]) {
            if(pre == -1)pre = i + l;
            else {
                if(mn.S - mn.F > i + l - pre) {
                    mn = {pre, i + l};
                } if(mx.S - mx.F < i + l - pre) {
                    mx = {pre, i + l};
                }
            }
            pre = i + l;
        }
    }

}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    sieve(sqrt(2147483647) + 100);
    ll l, r;
    while(cin >> l >> r) {
        mx = {-1, -1}, mn = {0, INT_MAX};
        segmentedSieve(l, r);
        if(mx.F == -1)printf("There are no adjacent primes.\n");
        else printf("%d,%d are closest, %d,%d are most distant.\n", mn.F, mn.S, mx.F, mx.S);
    }


    return 0;
}
