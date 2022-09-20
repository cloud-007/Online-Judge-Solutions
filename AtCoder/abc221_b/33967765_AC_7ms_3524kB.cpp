/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
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
    To_Infinity_And_Beyond;
    string s, t; cin >> s >> t;
    bool ok = true, once = false;
    for(int i = 0; i < s.size() - 1; i++) {
        if(s[i] != t[i]) {
            if(once) {
                ok = false;
                break;
            }
            once = true;
            if(s[i + 1] != t[i + 1]) {
                if(s[i + 1] != t[i] || s[i] != t[i + 1]) {
                    ok = false;
                    break;
                }
                i++;
            } else {
                ok = false;
                break;
            }
        }

    }
    cout << (ok ? "Yes" : "No") << endl;


    return 0;
}
