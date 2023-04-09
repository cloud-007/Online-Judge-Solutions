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
int tc, n, q, a[sz], b[sz];
set < int > st;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
        st.insert(i);
    }
    cin >> q;
    while(q--) {
        int ty; cin >> ty;
        if(ty == 1) {
            int id, tot; cin >> id >> tot;
            auto it = st.lower_bound(id);
            vector < int > del;
            while(it != st.end()) {
                int ase = a[*it];
                // cout<<*it<<" "<<tot<<endl;
                if(a[*it] <= tot) {
                    tot -= a[*it];
                    a[*it] = -1;
                    del.push_back(*it);
                } else {
                    a[*it] -= tot;
                    break;
                }
                ++it;
            }
            for(auto i : del)st.erase(i);
        } else {
            int k; cin >> k;
            if(~a[k])cout << b[k] - a[k] << endl;
            else cout << b[k] << endl;
        }
    }


    return 0;
}
