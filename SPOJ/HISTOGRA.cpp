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
int tc, n, a[sz], ans[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    while(cin >> n && n) {
        stack < pair < int, int>> st;
        ll Ans = 0;
        for(int i = 1; i <= n; i++)cin >> a[i];

        st.push({-1, 0});

        for(int i = 1; i <= n; i++) {
            int x = a[i];
            while(st.size() && x <= st.top().F)st.pop();
            ans[i] = i - st.top().S;
            st.push({x, i});
        }
        while(st.size())st.pop();
        st.push({-1, n + 1});

        for(int i = n; i >= 1; i--) {
            int x = a[i];
            while(st.size() && st.top().F >= x)st.pop();
            ans[i] += st.top().S - i;
            st.push({x, i});
        }

        for(int i = 1; i <= n; i++)Ans = max(Ans, (ll)(ans[i] - 1) * (ll)(a[i]));

        cout << Ans << endl;
    }


    return 0;
}
