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

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    ll k, sum = 0;
    cin >> k;
    for(int i = 1; i <= k; i++) {
        sum = sum * 10 + 7;
        sum %= k;
        if(sum == 0) {
            cout << i << endl;
            exit(0);
        }
    }
    cout << -1 << endl;


    return 0;
}
