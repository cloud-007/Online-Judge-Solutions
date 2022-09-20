/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e8 + 5;
bool prime[N];

void sieve() {
    int cnt = 1;
    cout << 2 << endl;
    ++cnt;
    for(ll i = 3; i <= 1e8; i += 2) {
        if(prime[i] == 0) {
            if(cnt % 100 == 1)cout << i << endl;
            ++cnt;
            for(ll j = i * i; j <= 1e8; j += i * 2)
                prime[j] = true;
        }
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
