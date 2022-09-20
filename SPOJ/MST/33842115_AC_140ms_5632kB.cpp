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
int tc, n, m, casee = 1, a[N], p[N];
priority_queue < pair < int, pair < int, int >>>pq;

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> n >> m;

    for(int i = 0; i <= n; i++)p[i] = i;

    while(m--) {
        int u, v, c;
        cin >> u >> v >> c;
        pq.push({-c, {u, v}});
    }

    ll Ans = 0;
    while(!pq.empty()) {
        int x = find(pq.top().S.F);
        int y = find(pq.top().S.S);
        if(x != y) {
            Ans += -(pq.top().F);
            p[y] = x;
        }
        pq.pop();
    }
    cout << Ans << endl;


    return 0;
}
