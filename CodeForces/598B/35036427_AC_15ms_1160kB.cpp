/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, q, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    string s; cin >> s >> q;
    while(q--) {
        int l, r, k;
        cin >> l >> r >> k;
        int sz = r - l + 1;
        --l, --r; k %= sz;
        if(k == 0)continue;

        string s1 = s.substr(0, l);
        string s2 = s.substr(r + 1, s.size());

        string t1 = s.substr(l, sz - k);
        string t2 = s.substr(l + sz - k, k);

        s = s1 + t2 + t1 + s2;

    }

    cout << s << endl;


    return 0;
}
