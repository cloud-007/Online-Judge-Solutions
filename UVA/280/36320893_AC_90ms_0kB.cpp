/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e3 + 5;
int tc, n, u, v, casee = 1, src, selfLoop[N];
vector < int > x[N];
bool vis[N];

void dfs(int u) {
    vis[u] = true;
    for(auto i : x[u]) {
        if(!vis[i])dfs(i);
        else if(i == src)selfLoop[src] = true;
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    while(cin >> n && n) {

        memset(selfLoop, false, sizeof selfLoop);

        while(cin >> u && u) {
            while(cin >> v && v) {
                x[u].push_back(v);
                if(u == v)selfLoop[u] = true;
            }
        }

        cin >> tc;
        while(tc--) {
            src; cin >> src;
            memset(vis, false, sizeof vis);
            dfs(src);
            set < int > st;
            if(selfLoop[src] == false)st.insert(src);
            for(int i = 1; i <= n; i++)if(!vis[i])st.insert(i);
            cout << st.size();
            bool nl = false;
            for(auto i : st) {
                cout << " ";
                nl = true;
                cout << i ;
            }
            cout << endl;
        }


        for(int i = 1; i <= n; i++)x[i].clear();
    }


    return 0;
}
