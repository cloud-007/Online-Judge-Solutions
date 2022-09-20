/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 3e5 + 5;
int tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    vector <pair<int, int>> vp;
    map <int, int> mp;

    int lastIndex = 0;
    for(int i = 1; i <= n; i++) {
        if(mp[a[i]]) {
            vp.push_back({lastIndex + 1, i});
            mp.clear();
            lastIndex = i;
        } else mp[a[i]] = i;
    }

    if(vp.size()) {
        vp[vp.size() - 1].S = n;
        cout << vp.size()<<endl;
        for(auto i: vp)cout << i.F<<" "<<i.S<<endl;
    } else cout << -1 << endl;


    return 0;
}
