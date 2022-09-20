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
int tc, n, a[sz], mp[sz], mx  = 0, mn = INT_MAX;
set < int > st;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x; mp[x]++; mx = max(mx, x);
        mn = min(mn, x);
        st.insert(x);
    }
    vector < int > v;
    for(auto i : st)v.push_back(i);
    sort(v.rbegin(), v.rend());
    for(auto i : v) {
        if(mp[i] & 1) {
            cout << "Conan" << endl;
            exit(0);
        }
    }
    cout << "Agasa" << endl;


    return 0;
}
