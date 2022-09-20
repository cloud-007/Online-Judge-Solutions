/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 30005, N = 1e6 + 5;
int k, n, m, a[sz], mp[N], res = 0, ans[N];

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
    if(!mp[a[idx]])res++;
    mp[a[idx]]++;
}

void remove(int idx) {
    mp[a[idx]]--;
    if(!mp[a[idx]])res--;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    k = sqrt(n);
    for(int i = 1; i <= n; i++)cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].index = i;
    }

    sort(q + 1, q + m + 1);

    int l = 1, r = 0;

    for(int i = 1; i <= m; i++) {
        while(r < q[i].r)add(++r);
        while(l < q[i].l)remove(l++);
        while(r > q[i].r)remove(r--);
        while(l > q[i].l)add(--l);
        ans[q[i].index] = res;
    }

    for(int i = 1; i <= m; i++)cout << ans[i] << (i != m ? endl : "");


    return 0;
}
