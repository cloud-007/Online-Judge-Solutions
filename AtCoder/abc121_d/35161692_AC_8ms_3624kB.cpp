/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
ll a, b;

ll computeXOR(ll n) {
    if(n % 4 == 0)return n;
    if(n % 4 == 1)return 1;
    if(n % 4 == 2)return n + 1;
    return 0;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> a >> b;
    ll x = computeXOR(b);
    ll y = computeXOR(max(0ll, a - 1));
    cout << (x ^ y) << endl;


    return 0;
}
