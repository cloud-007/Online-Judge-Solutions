/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 3e5 + 10, M = N;
int n, q, a[N], b[N];
const int MAX = 1e6;
struct wavelet_tree {
    int lo, hi;
    wavelet_tree *l, *r;
    int *b, *c, bsz, csz; // c holds the prefix sum of elements

    wavelet_tree() {
        lo = 1;
        hi = 0;
        bsz = 0;
        csz = 0, l = NULL;
        r = NULL;
    }

    void init(int *from, int *to, int x, int y) {
        lo = x, hi = y;
        if(from >= to) return;
        int mid = (lo + hi) >> 1; auto f = [mid](int x) {
            return x <= mid;
        };
        b = (int*)malloc((to - from + 2) * sizeof(int)); bsz = 0; b[bsz++] = 0;
        c = (int*)malloc((to - from + 2) * sizeof(int)); csz = 0; c[csz++] = 0;
        for(auto it = from; it != to; it++) {
            b[bsz] = (b[bsz - 1] + f(*it));
            c[csz] = (c[csz - 1] + (*it));
            bsz++;
            csz++;
        }
        if(hi == lo) return;
        auto pivot = stable_partition(from, to, f);
        l = new wavelet_tree();
        l->init(from, pivot, lo, mid);
        r = new wavelet_tree();
        r->init(pivot, to, mid + 1, hi);
    }
    //count of numbers in [l, r] equal to k
    int count(int l, int r, int k) {
        if(l > r || k < lo || k > hi) return 0;
        if(lo == hi) return r - l + 1;
        int lb = b[l - 1], rb = b[r];
        int mid = (lo + hi) >> 1;
        if(k <= mid) return this->l->count(lb + 1, rb, k);
        return this->r->count(l - lb, r - rb, k);
    }

    //kth smallest element in [l, r]
    int kth(int l, int r, int k) {
        if(l > r) return 0;
        if(lo == hi) return lo;
        int inleft = b[r] - b[l - 1];
        int lb = b[l - 1];
        int rb = b[r];
        if(k <= inleft) return this->l->kth(lb + 1, rb, k);
        return this->r->kth(l - lb, r - rb, k - inleft);
    }

    //count of nos in [l, r] Less than or equal to k
    int LTE(int l, int r, int k) {
        if(l > r or k < lo) return 0;
        if(hi <= k) return r - l + 1;
        int lb = b[l - 1], rb = b[r];
        return this->l->LTE(lb + 1, rb, k) + this->r->LTE(l - lb, r - rb, k);
    }

    ~wavelet_tree() {
        delete l;
        delete r;
    }

} T;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    int maxV = 1e9 + 5;
    scanf("%d %d", &n, &q);
    // cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        //cin >> a[i];
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    T.init(a + 1, a + n + 1, -maxV, maxV);
    while(q--) {
        int l, r, k;// cin >> l >> r >> k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", T.kth(l, r, k));
        // cout << T.kth(l, r, k) << endl;
    }


    return 0;
}
