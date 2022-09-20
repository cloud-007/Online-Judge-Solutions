/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, k, Ans[N], a[N];
int mp[N], res[N], cnt;

struct query {
    int index, l, r;
    bool operator< (const query &other)const {
        int block_own = l / k;
        int block_other = other.l / k;
        if(block_own == block_other)
            return r < other.r;
        return block_own < block_other;
    }
} q[N];

void add(int idx) {
    res[mp[a[idx]]]--;
    mp[a[idx]]++;
    res[mp[a[idx]]]++;
    cnt = max(cnt, mp[a[idx]]);
}

void remove(int idx) {
    int x = mp[a[idx]];
    res[mp[a[idx]]]--;
    mp[a[idx]]--;
    res[mp[a[idx]]]++;
    if(res[x] == 0 && cnt == x) {
        cnt = x - 1;
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        int c, m; cin >> n >> c >> m;
        k = sqrt(n);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            mp[i] = res[i] = 0;
        }
        for(int i = 1; i <= m; i++) {
            cin >> q[i].l >> q[i].r;
            q[i].index = i;
            Ans[i] = 0;
        }
        sort(q + 1, q + m + 1);
        int l = 1, r = 0;

        cnt = 0;
        for(int i = 1; i <= m; i++) {
            while(r < q[i].r)add(++r);
            while(l < q[i].l)remove(l++);
            while(r > q[i].r)remove(r--);
            while(l > q[i].l)add(--l);
            Ans[q[i].index] = cnt;
        }
        cout << "Case " << casee++ << ":" << endl;
        for(int i = 1; i <= m; i++)cout << Ans[i] << endl;
    }


    return 0;
}
