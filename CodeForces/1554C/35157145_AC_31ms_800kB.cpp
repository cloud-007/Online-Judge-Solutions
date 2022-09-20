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
        int m; cin >> n >> m; ++m;
        int Ans = 0;
        for(int k = 30; k >= 0 && n < m; k--) {
            if((n >> k & 1) == (m >> k & 1))continue;
            if(m >> k & 1)Ans |= (1 << k), n |= (1 << k);
        }
        cout << Ans << endl;
    }


    return 0;
}
