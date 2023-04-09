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
vector < char > x[100];
bool vis[N];

void dfs(char u) {
    vis[u] = true;;
    for(auto i : x[u]) {
        if(!vis[i])dfs(i);
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    bool fl = false;
    cin >> tc;
    while(tc--) {
        getchar();
        char c; cin >> c;
        cin.ignore();
        string s;
        while(getline(cin, s) && s.size()) {
            char u = s[0], v = s[1];
            x[u].push_back(v);
            x[v].push_back(u);
        }

        int Ans = 0;

        for(char i = 'A'; i <= c; i++) {
            if(!vis[i]) {
                ++Ans;
                dfs(i);
            }
        }

        if(fl)cout << endl;
        fl = true;

        cout << Ans << endl;


        for(char c = 'A'; c <= 'Z'; c++) {
            x[c].clear(); vis[c] = false;
        }
    }


    return 0;
}
