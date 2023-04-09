/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[6];

bool rec(int idx, int sum) {
    if(idx > 5) {
        return (sum == 23);
    }
    bool ret = rec(idx + 1, sum - a[idx]);
    ret |= rec(idx + 1, sum + a[idx]);
    ret |= rec(idx + 1, sum * a[idx]);
    return ret;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    while(cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5]
            && (a[1]) || a[2] || a[3] || a[4] || a[5]) {

        bool ok = false;
        sort(a + 1, a + 6);
        do {
            ok |= rec(2, a[1]);
            if(ok)break;
        } while(next_permutation(a + 1, a + 6));
        cout << (ok ? "Possible" : "Impossible") << endl;
    }


    return 0;
}
