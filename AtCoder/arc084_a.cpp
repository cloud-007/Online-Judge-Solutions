/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1;
vector < int > a, b, c;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    a.resize(n);
    b.resize(n);
    c.resize(n);

    for(auto &x : a)cin >> x;
    for(auto &x : b)cin >> x;
    for(auto &x : c)cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll Ans = 0;

    for(auto i : b) {

        ll Left = lower_bound(a.begin(), a.end(), i) - a.begin();
        ll Right = n - (upper_bound(c.begin(), c.end(), i) - c.begin());
        Ans += Left * Right;
    }

    cout << Ans << endl;

    return 0;
}
