/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e3 + 5;
int tc, n, m;
vector < pair < int, int >> vp;
bool visa[N], visb[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(!visa[i] || !visb[j]) {
                vp.push_back({i, j});
                visa[i] = true;
                visb[j] = true;
            }
        }
    }

    sort(vp.begin(), vp.end());

    cout << vp.size() << endl;

    for(auto i : vp)cout << i.F << " " << i.S << endl;


    return 0;
}
