/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 5005;
int tc, n, pref[sz][4];
string s;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> s;
    n = s.size();
    s = "#" + s;

    for(int i = 1; i <= n; i++) {
        pref[i][1] = pref[i - 1][1];
        pref[i][2] = pref[i - 1][2];
        pref[i][1] += (s[i] == 'a');
        pref[i][2] += (s[i] == 'b');
    }

    int Ans = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            int tot_b_first = pref[i - 1][2];
            int tot_b_last = pref[n][2] - pref[j][2];
            int tot_a_mid = pref[j][1] - pref[i][1];
            Ans = max(Ans, n - (tot_a_mid + tot_b_first + tot_b_last));
        }
    }

    cout << Ans << endl;


    return 0;
}
