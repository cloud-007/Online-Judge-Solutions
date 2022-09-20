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
int tc, n, a, last;
set < int > st;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    while(cin >> n) {
        st.clear();
        for(int i = 1; i <= n; i++) {
            cin >> a;
            if(i > 1)
                st.insert(abs(a - last));
            last = a;
        }
        puts((st.size() == n - 1 && *st.begin() == 1 && *st.rbegin() == n - 1) || n == 1 ? "Jolly" : "Not jolly");
    }

    return 0;
}
