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
    string s; cin >> s;
    ll Ans = 0, cur = 0;

    for(int i = 0; i < s.size(); i++) {
        cur += s[i] - '0';
        ll x = max(cur - 1, 0ll) + (9 * ((int)s.size() - i - 1));
        Ans = max(Ans, x);
    }

    Ans = max(Ans, cur);

    cout << Ans << endl;


    return 0;
}
