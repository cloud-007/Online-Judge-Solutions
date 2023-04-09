/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    int l, q, c, x;

    set < pair < int, int >> st;
    cin >> l >> q;
    st.insert({l, 1});
    while(q--) {
        cin >> c >> x;
        auto it = st.lower_bound({x, 0});
        if(c == 2) {
            cout << (it->F - it->S)+1 << endl;
        } else {
            st.insert({it->F, x+1});
            st.insert({x, it->S});
            st.erase(it);
        }
    }


    return 0;
}
