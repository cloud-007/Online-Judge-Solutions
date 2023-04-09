/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e3 + 5;
int tc, n, casee = 1, a[N], pref[N][2];

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
        for(int i = 1; i <= n; i++) {
            pref[i][0] = pref[i - 1][0] + (s[i] == '0');
            pref[i][1] = pref[i - 1][1] + (s[i] == '1');
        }
        int Ans = INT_MAX;
        for(int i = 1; i <= n; i++) {
            int one = pref[i][1] + (pref[n][0] - pref[i][0]);
            int two = pref[i][0] + (pref[n][1] - pref[i][1]);
            Ans = min({Ans, one, two});
        }
        cout << Ans << endl;
        memset(pref, 0, sizeof pref);
    }


    return 0;
}
