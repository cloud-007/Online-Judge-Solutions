/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
int tc, n, m, l, Par[sz], a[sz];

void make_set(int v) {
    Par[v] = v;
}

int find_set(int v) {
    if(v == Par[v])
        return v;
    return Par[v] = find_set(Par[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        Par[b] = a;
    }
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> m >> l;
    for(int i = 1; i <= n; i++) {
        make_set(i);
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        if(a[i] > l) {
            if(i - 1 >= 1 && a[i - 1] > l)union_sets(i, i - 1);
            if(i + 1 <= n && a[i + 1] > l)union_sets(i, i + 1);
        }
    }

    int Ans = 0;

    map < int, int > mp;

    for(int i = 1; i <= n; i++) {
        if(a[i] > l) {
            int cur = find_set(i);
            mp[cur]++;
        }
    }

    Ans = mp.size();

    while(m--) {
        int ty; cin >> ty;
        if(!ty)cout << Ans << endl;
        else {
            int i, d; cin >> i >> d;
            if(a[i] <= l && a[i] + d > l) {
                int par_a = -1, par_b = -1;
                if(i - 1 >= 1 && a[i - 1] > l)par_a = find_set(i - 1);
                if(i + 1 <= n && a[i + 1] > l)par_b = find_set(i + 1);
                if(~par_a && ~par_b) {
                    --Ans;
                    union_sets(i, i - 1);
                    union_sets(i, i + 1);
                } else if(~par_a)union_sets(i, i - 1);
                else if(~par_b)union_sets(i, i + 1);
                else Ans++;
            }
            a[i] += d;
            if(a[i] > l)a[i] = l + 1;
        }
    }


    return 0;
}
