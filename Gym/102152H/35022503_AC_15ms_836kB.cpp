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
        string s; cin >> s;
        n = s.size();
        s = "#" + s;
        if(n == 1) {
            cout << "YES" << endl;
            continue;
        }
        bool ok = true;
        for(int i = 1; i < n; i++) {
            if(s[i] == 'z' && s[i + 1] != 'a') {
                ok = false;
                break;
            } else if(s[i] != 'z' && s[i + 1] - s[i] != 1) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }


    return 0;
}
