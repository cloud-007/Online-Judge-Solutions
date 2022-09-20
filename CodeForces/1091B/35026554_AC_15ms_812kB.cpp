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
    cin >> n;
    vector < pair < int, int >> a(n), b(n);
    for(auto &x : a)cin >> x.F >> x.S;
    for(auto &x : b)cin >> x.F >> x.S;

    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());

    cout << a[0].F + b[0].F << " " << a[0].S + b[0].S << endl;


    return 0;
}
