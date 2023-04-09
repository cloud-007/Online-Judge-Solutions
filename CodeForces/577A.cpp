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
    int x; cin >> n >> x;
    set < int > st;
    for(int i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            st.insert(i);
            st.insert(x / i);
        }
    }
    int Ans = 0;
    for(auto i : st) {
        if(i <= n && x / i <= n)++Ans;
    }
    cout << Ans << endl;


    return 0;
}
