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
    for(ll i = 3; i <= 1e6; i += 2) {
        if(prime[i] == 0) {
            primes.insert(i);
            for(ll j = i * i; j <= 1e6; j += i * 2)
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
    while(cin >> n && n!=0) {
        pair < int, int > Ans = {-1, -1};
        for(auto i : primes) {
            if(i <= n) {
                if(prime[n - i] == 0) {
                    Ans = {i, n - i};
                    break;
                }
            } else break;
        }
        if(Ans.F != -1) {
            cout << n << " = " << Ans.F << " + " << Ans.S << Endl;
        } else {
            cout << "Goldbach's conjecture is wrong." << endl;
        }
    }

    return 0;
}
