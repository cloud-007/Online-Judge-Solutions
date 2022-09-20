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
    int k; cin >> n >> k;
    string s; cin >> s;
    map < char, int > mp;
    while(k--) {
        char c; cin >> c;
        mp[c]++;
    }

    ll Ans = 0, cnt = 0;

    for(auto i : s) {
        if(!mp[i]) {
            Ans += (cnt * (cnt + 1)) / 2;
            cnt = 0;
        } else ++cnt;
    }

    Ans += (cnt * (cnt + 1)) / 2;

    cout << Ans << endl;


    return 0;
}
