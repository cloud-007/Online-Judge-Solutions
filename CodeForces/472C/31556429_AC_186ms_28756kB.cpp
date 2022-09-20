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
int tc, n, a[N], Map[N];
string s[N][3];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s[i][1] >> s[i][2];
    }

    string last = "";

    bool ok = true;

    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        if(last.empty()) {
            last = min(s[x][1], s[x][2]);
        } else if(min(s[x][1], s[x][2]) >= last) {
            last = min(s[x][1], s[x][2]);
        } else if(max(s[x][1], s[x][2]) >= last) {
            last = max(s[x][1], s[x][2]);
        } else ok = false;
    }

    cout << (ok ? "YES" : "NO") << endl;


    return 0;
}
