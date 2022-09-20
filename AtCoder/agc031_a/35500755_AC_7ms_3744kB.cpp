/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5, mod = 1e9 + 7;
int tc, n, casee = 1, mp[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    string s; cin >> n >> s;
    for(auto i : s)mp[i]++;

    ll Ans = 1;
    for(char c = 'a'; c <= 'z'; c++) {
        if(!mp[c])continue;
        Ans *= ++mp[c];
        Ans %= mod;
    }

    cout << --Ans << endl;

    return 0;
}
