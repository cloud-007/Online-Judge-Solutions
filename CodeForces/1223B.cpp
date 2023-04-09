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
    cin >> tc;
    while(tc--) {
        string s, t; cin >> s >> t;
        map < char, int > mp;
        for(auto i : s)mp[i]++;
        bool ok = false;
        for(auto i : t)if(mp[i])ok = true;
        cout << (ok ? "YES" : "NO") << endl;
    }


    return 0;
}
