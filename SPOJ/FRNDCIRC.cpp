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
int tc, n, m, casee = 1, a[N], p[N], cnt[N], upd = 1;

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

void update(int u, int v) {
    p[u] = v;
    cnt[v] += cnt[u];
}

map < string, int > mp;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 0; i <= n * 2; i++)p[i] = i, cnt[i] = 0;
        upd = 1;
        while(n--) {
            string x, y; cin >> x >> y;
            int numX;
            int numY;
            if(!mp[x]) {
                mp[x] = upd++;
                cnt[mp[x]] = 1;
            }
            if(!mp[y]) {
                mp[y] = upd++;
                cnt[mp[y]] = 1;
            }

            numX = find(mp[x]);
            numY = find(mp[y]);

            if(numX != numY) {
                update(numX, numY);
            }
            cout << cnt[find(numY)] << endl;
        }
        mp.clear();
    }




    return 0;
}
