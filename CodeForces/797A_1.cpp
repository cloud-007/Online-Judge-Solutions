/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N];
vector < int > primes;

int status[N];

void generate_prime() {

    primes.push_back(2);

    int n = sqrt(N);

    for(int i = 4; i < N; i += 2)status[i] = 1;

    for(int i = 3; i < n; i += 2) {
        if(status[i] == 0) {
            primes.push_back(i);
            for(int j = i * i; j < N; j += i * 2)
                status[j] = 1;
        }
    }
}



int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    generate_prime();
    int k, i = 0; cin >> n >> k;

    if(k==1){
        cout << n << endl;
        exit(0);
    }

    deque < ll > fact;

    while(n > 1) {
        while(n > 1 && (n % primes[i] == 0)) {
            fact.push_back(primes[i]);
            n /= primes[i];
        }
        ++i;
    }


    if(fact.size() < k)cout << -1 << endl;
    else {
        while(fact.size() > k) {
            fact[1] *= fact[0];
            fact.pop_front();
        }
        for(auto i : fact)cout << i << " ";
        cout << endl;
    }


    return 0;
}
