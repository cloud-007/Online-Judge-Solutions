/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e6 + 5;
int tc, n, casee = 1, a[N], mp[N], cnt = 0, Ans[N];

struct query {
    int index, l, r;
    bool operator< (const query &other)const {
        int block_own = l / 420;
        int block_other = other.l / 420;
        if(block_own == block_other)
            return r < other.r;
        return block_own < block_other;
    }
} q[N];

void add(int idx) {
    if(!mp[a[idx]])++cnt;
    mp[a[idx]]++;
}

void remove(int idx) {
    mp[a[idx]]--;
    if(!mp[a[idx]]) --cnt;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    int m; cin >> m ;

    for(int i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].index = i;
    }

    sort(q + 1, q + m + 1);

    int l = 0, r = -1;
    memset(Ans, 0, sizeof Ans);
    for(int i = 1; i <= m; i++) {
        while(r < q[i].r)add(++r);
        while(l < q[i].l)remove(l++);
        while(r > q[i].r)remove(r--);
        while(l > q[i].l)add(--l);
        Ans[q[i].index] = cnt;
    }

    for(int i = 1; i <= m; i++)cout << Ans[i] << endl;



    return 0;
}
