/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
ll tc, n;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    if(n <= 2) {
        cout << 1 << endl;
        exit(0);
    }
    ll sum = 0;
    for(ll i = 1;; i++) {
        sum += i;
        if(sum >= n) {
            sum -= i;
            if(n % sum == 0)cout << i << endl;
            else cout << n % sum << endl;
            exit(0);
        }
    }

    return 0;
}

