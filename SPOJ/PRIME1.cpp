#include<bits/stdc++.h>
using namespace std;

vector < int > primes;

void sieve(int N) {

    bool prime[N + 5];

    for(int i = 2; i <= N; i++)prime[i] = true;

    for(int i = 4; i <= N; i += 2)prime[i] = false;

    for(int i = 3; i <= N ; i += 2) {
        if(prime[i]) {
            for(int j = i * i; j <= N; j += i * 2) {
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
#define ll long long

void segmentedSieve(ll l, ll r) {

    bool isPrime[r - l + 5];

    for(int i = 0; i < r - l + 5; i++)isPrime[i] = true;

    if(l == 1)isPrime[0] = false;

    for(int i = 0; primes[i] * primes[i] <= r; i++) {
        int cp  = primes[i];
        ll currentNumber = ((l + cp - 1) / cp) * cp;
        for(ll j = currentNumber; j <= r; j += cp)
            isPrime[j - l] = false;
        if(currentNumber == cp)isPrime[currentNumber - l] = true;
    }

    for(int i = 0; i < r - l + 1; i++) {
        if(isPrime[i])cout << i + l << endl;
    }

}


int main() {
    sieve(sqrt(1000000000) + 100);
    int tc; cin >> tc;
    while(tc--) {
        ll l, r;
        cin >> l >> r;
        segmentedSieve(l, r);
    }
}