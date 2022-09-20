/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, deg[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        int k; cin >> n >> k;
        for(int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            deg[u]++, deg[v]++;
        }
        if(n == 1 || deg[k] == 1 || (--n) & 1)cout << "Ayush" << endl;
        else cout << "Ashish" << endl;

        memset(deg, 0, sizeof deg);

    }


    return 0;
}
