/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        int q; cin >> n >> q;

        int Ans = 0;

        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            Ans += (a[i] != a[i - 1]);
        }

        a[n+1] = 0;

        while(q--) {
            int id, val;
            cin >> id >> val;
            int pre = a[id];
            a[id] = val;
            if(pre == a[id - 1]) {
                if(a[id] != a[id - 1])++Ans;
            } else {
                if(a[id] == a[id - 1])--Ans;
            }
            if(pre == a[id + 1]) {
                if(a[id] != a[id + 1])++Ans;
            } else {
                if(a[id] == a[id + 1])--Ans;
            }
            cout << Ans << endl;
        }

    }


    return 0;
}
