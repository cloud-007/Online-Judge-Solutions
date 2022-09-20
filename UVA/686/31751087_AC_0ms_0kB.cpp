/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e6 + 5;
bool prime[N];
set < int > primes;

void sieve() {
    primes.insert(2);
    for(int i = 4; i <= 33000; i += 2)prime[i] = 1;
    prime[1] = 1;
    for(ll i = 3; i <= 33000; i += 2) {
        if(prime[i] == 0) {
            primes.insert(i);
            for(ll j = i * i; j <= 33000; j += i * 2)
                prime[j] = 1;
        }
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    sieve();
    int n;
    while(cin >> n && n != 0) {
        int Ans = 0;
        for(auto i : primes) {
            if(i <= n) {
                if(prime[n - i] == 0) {
                    if(i == n - i)Ans += 2;
                    else ++Ans;
                }
            } else break;
        }
        cout << Ans / 2 << endl;
    }

    return 0;
}
