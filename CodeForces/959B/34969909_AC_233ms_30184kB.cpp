/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, k, m, casee = 1, a[N];
string s[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n >> k >> m;
    for(int i = 1; i <= n; i++)cin >> s[i];
    for(int i = 1; i <= n; i++)cin >> a[i];

    map < string, int > mp;

    while(k--) {
        int x; cin >> x;
        vector < string > v;
        int mn = INT_MAX;
        while(x--) {
            int id; cin >> id;
            v.push_back(s[id]);
            mn = min(mn, a[id]);
        }
        for(auto i : v)mp[i] = mn;
    }

    ll Ans = 0;

    while(m--) {
        string x; cin >> x;
        Ans += mp[x];
    }

    cout << Ans << endl;


    return 0;
}
