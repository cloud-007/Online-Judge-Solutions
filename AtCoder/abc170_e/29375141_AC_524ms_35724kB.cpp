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
int n, q, a[sz], b[sz], c, d;
multiset < int > x[sz], ans;
set < int > st;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        x[b[i]].insert(a[i]);
        st.insert(b[i]);
    }

    for(auto i : st) {
        ans.insert(*x[i].rbegin());
    }

    while(q--) {
        cin >> c >> d;
        auto it1 = x[b[c]].find(a[c]);
        bool deleted1 = 0, deleted2 = 0;
        if(*x[b[c]].rbegin() == a[c]) {
            auto it = ans.find(a[c]);
            ans.erase(it);
            deleted1 = true;
        }
        x[b[c]].erase(it1);
        if(x[d].size()) {
            auto del = ans.find(*x[d].rbegin());
            ans.erase(del);
            deleted2 = true;
        }
        x[d].insert(a[c]);
        if(x[b[c]].size() && deleted1)ans.insert(*x[b[c]].rbegin());
        ans.insert(*x[d].rbegin());
        b[c] = d;
        cout << *ans.begin() << endl;
    }


    return 0;
}
