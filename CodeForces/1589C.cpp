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
map < int, int > mp;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 1; i <= n; i++)cin >> a[i];
        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            mp[x]++;
        }
        sort(a + 1, a + n + 1);
        bool ok = true;
        for(int i = 1; i <= n; i++) {
            if(mp[a[i]]) {
                mp[a[i]]--;
                continue;
            } else if(mp[a[i] + 1]) {
                mp[a[i] + 1]--;
            }
        }
        for(auto i : mp) {
            if(i.S)ok = false;
        }
        cout << (ok ? "YES" : "NO") << endl;
        mp.clear();
    }



    return 0;
}
