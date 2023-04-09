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
        string s; int q;
        cin >> n >> q >> s;
        s = "#" + s;
        while(q--) {
            int l, r; cin >> l >> r;
            int foundL = -1, foundR = -1;
            bool foundLeft = false, foundRight = false;
            for(int i = 1, L = l; i <= n && L <= r; i++) {
                if(s[i] == s[L]) {
                    ++L;
                    if(L >= r)foundLeft = true;
                    if(foundL == -1)foundL = i;
                }
            }
            for(int i = n, R = r; i >= 1 && R >= l; i--) {
                if(s[i] == s[R]) {
                    --R;
                    if(R <= l)foundRight = true;
                    if(foundR == -1)foundR = i;
                }
            }
            if(foundL == -1 || foundR == -1) {
                cout << "NO" << endl;
            } else if(foundL == l && foundR == r) {
                cout << "NO" << endl;
            } else if(foundLeft && foundRight && (foundR - foundL) >= r - l) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }


    return 0;
}
