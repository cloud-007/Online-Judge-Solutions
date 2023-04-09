/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
int tc, n, a[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    map < int, int > mp;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    vector < int > v;
    ll Ans = 0;
    for(auto i : mp) {
        if(i.S >= 2) {
            v.push_back(i.F);
        }
        if(i.S >= 4) {
            Ans = max(Ans, (ll)i.F * (ll)i.F);
        }
    }
    sort(v.rbegin(), v.rend());
    if(v.size() >= 2) {
        Ans = max(Ans, (ll)v[0] * (ll)v[1]);
    }

    cout << Ans << endl;


    return 0;
}
