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
ll tc, n, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> n;
    set < ll > st;
    ll Ans = 1e18;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(i == 1) {
            st.insert(a[i]);
            continue;
        }
        auto it = st.lower_bound(a[i]);
        if(it == st.end()) {
            st.insert(a[i]);
            continue;
        }
        Ans = min(Ans, *it - a[i]);
        st.insert(a[i]);
    }

    if(Ans == INT_MAX)Ans = 0;

    cout << Ans << Endl;


    return 0;
}
