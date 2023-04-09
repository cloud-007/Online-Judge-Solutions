/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, Ans[N];
vector < int > x[N], leaves;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        x[u].push_back(i);
        x[v].push_back(i);
    }

    for(int i = 1; i <= n; i++) {
        if(x[i].size() == 1)leaves.push_back(i);
    }

    if(leaves.size() == 2) {
        for(int i = 1; i < n; i++)cout << i - 1 << endl;
    } else {
        memset(Ans, -1, sizeof Ans);

        Ans[x[leaves[0]][0]] = 0;
        Ans[x[leaves[1]][0]] = 1;
        Ans[x[leaves[2]][0]] = 2;

        for(int i = 1, done = 2; i < n; i++) {
            if(Ans[i] == -1)Ans[i] = ++done;
            cout << Ans[i] << endl;
        }
    }


    return 0;
}
