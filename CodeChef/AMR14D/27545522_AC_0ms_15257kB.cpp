/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 10000  + 5;
int tc, n, a;
set < int > st;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        st.clear();
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a;
            st.insert(a);
        }
        puts(st.size() == n ? "YES" : "NO");
    }

    return 0;
}