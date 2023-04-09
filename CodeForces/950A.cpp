/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
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
    To_Infinity_And_Beyond;
    int l, r, a; cin >> l >> r >> a;
    if(l > r)swap(l, r);
    int mn = min(a, r - l);
    l += mn;
    a -= mn;
    l += a / 2;

    cout << l*2 << endl;


    return 0;
}
