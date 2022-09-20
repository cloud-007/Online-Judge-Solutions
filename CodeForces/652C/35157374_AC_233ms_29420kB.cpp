/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 3e5 + 5;
int tc, n, casee = 1, mp[N];
set < int > st[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    int m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x; mp[x] = i;
    }

    while(m--) {
        int x, y; cin >> x >> y;
        st[min(mp[x], mp[y])].insert(max(mp[x], mp[y]));
    }

    ll Ans = 0;
    int last = n + 1;
    for(int i = n; i > 0; i--) {
        if(st[i].size())last = min(last, *st[i].begin());
        Ans += last - i;
    }

    cout << Ans << endl;


    return 0;
}
