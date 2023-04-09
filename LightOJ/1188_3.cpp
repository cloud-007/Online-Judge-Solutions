/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 1e5 + 50;
int k, ans[sz], a[sz], mp[sz], tc, casee = 1, n, m, cnt = 0;
set < int > st;

struct query {
    int index, l, r;
    bool operator< (const query &other)const {
        int block_own = l / k;
        int block_other = other.l / k;
        if(block_own == block_other)
            return r < other.r;
        return block_own < block_other;
    }
} q[sz];

void add(int idx) {
    if(!mp[a[idx]])cnt++;
    mp[a[idx]]++;
}

void remove(int idx) {
    mp[a[idx]]--;
    if(!mp[a[idx]])cnt--;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    scanf("%d", &tc);
    while(tc--) {
        memset(mp, 0, sizeof mp);
        cnt = 0;
        scanf("%d%d", &n, &m);
        k = sqrt(n);
        for(int i = 1; i <= n; i++)scanf("%d", &a[i]);
        for(int i = 1; i <= m; i++) {
            cin >> q[i].l >> q[i].r;
            q[i].index = i;
        }
        sort(q, q + m);
        int l = 0, r = -1;
        memset(ans, 0, sizeof ans);
        for(int i = 1; i <= m; i++) {
            while(r < q[i].r)add(++r);
            while(l < q[i].l)remove(l++);
            while(r > q[i].r)remove(r--);
            while(l > q[i].l)add(--l);
            ans[q[i].index] = cnt;
        }
        printf("Case %d:\n", casee++);
        for(int i = 1; i <= m; i++)printf("%d\n", ans[i]);
    }
}
