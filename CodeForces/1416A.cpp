/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 3e5 + 5;
int tc, n, casee = 1, Ans[N];
set < int > st;
vector < int > x[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            int k; cin >> k;
            st.insert(k);
            x[k].push_back(i);
        }
        for(int i = 1; i <= n; i++)Ans[i] = INT_MAX;
        for(auto i : st) {
            int last = 0, mx = 0;
            for(auto j : x[i]) {
                int cur = j - last + 1;
                mx = max(mx, cur);
                last = j;
            }
            mx = max(mx, (n + 1) - last + 1);
            Ans[mx - 1] = min(Ans[mx - 1], i);
            x[i].clear();
        }
        int cur = INT_MAX;
        for(int i = 1; i <= n; i++) {
            cur = min(cur, Ans[i]);
            if(cur == INT_MAX)cout << -1 << " ";
            else cout << cur << " ";
        }
        cout << endl;
        st.clear();
    }


    return 0;
}
