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
    cin >> tc;
    while(tc--) {
        set < int > st;
        map < int, int > mp;
        int q; cin >> n >> q;
        while(n--) {
            int x, y; cin >> x >> y;
            st.insert(x); st.insert(y + 1);
            mp[x]++; mp[y + 1]--;
        }
        int pre = -1;
        for(auto i : st) {
            mp[i] += mp[pre];
            pre = i;
        }
        cout << "Case " << casee++ << ":" << endl;
        while(q--) {
            int x; cin >> x;
            if(st.count(x)) {
                cout << mp[x] << endl;
                continue;
            }
            auto it = st.lower_bound(x);
            --it;
            cout << mp[*it] << endl;
        }
    }


    return 0;
}
