/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 1e5 + 5;
vector < int > x[sz], xy;
int n, u, v, ss = 0, val = -1, ans = 0;

void dfs(int u, int par) {
    int changed = 0;
    if(ans == -1)return;
    for(auto i : x[u]) {
        if(i != par) {
            dfs(i, u);
            changed++;
        }
    }
    if(changed > 1 && u!=val) {
        ans = -1;
        return;
    }
    if(changed == 0)xy.push_back(u);
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    for(int i = 1; i < n; i++) {
        cin >> u >> v;
        x[u].push_back(v);
        x[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        if(x[i].size() >= ss) {
            ss = x[i].size(), val = i;
        }
    }

    dfs(val, -val);

    if(ans == -1)cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        cout << xy.size() << endl;
        for(auto i : xy) {
            cout << val << " " << i << endl;
        }
    }


    return 0;
}
