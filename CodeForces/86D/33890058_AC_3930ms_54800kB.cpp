/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e6 + 5;
int tc, n, m, k, a[N], mp[N];
ll res = 0, Ans[N];

struct query {
    int index, l, r;
    bool operator<(const query &other)const {
        int block_own = l / k;
        int block_other = other.l / k;
        if(block_own == block_other)return r < other.r;
        return block_own < block_other;
    }
} q[N];

void add(int idx) {
    ll curFreq = mp[a[idx]], curVal = a[idx];
    res -= (curFreq * curFreq * curVal);
    mp[a[idx]]++;
    curFreq = mp[a[idx]], curVal = a[idx];
    res += (curFreq * curFreq * curVal);
}

void remove(int idx) {
    ll curFreq = mp[a[idx]], curVal = a[idx];
    res -= (curFreq * curFreq * curVal);
    mp[a[idx]]--;
    curFreq = mp[a[idx]], curVal = a[idx];
    res += (curFreq * curFreq * curVal);
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> n >> m;
    k = sqrt(n);
    for(int i = 1; i <= n; i++)cin >> a[i];
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
        Ans[q[i].index] = res;
    }

    for(int i = 1; i <= m; i++)cout << Ans[i] << endl;
    for(int i = 1; i <= n; i++)mp[a[i]] = 0;


    return 0;
}
