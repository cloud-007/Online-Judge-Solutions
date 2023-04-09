/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
ll tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        cin >> n;
        ll pre = -1;
        bool ok = true;
        for(int i = 1; i <= n; i++)cin >> a[i];
        if(n >= 64)cout << "NO" << endl;
        else {
            map < ll, int > mp;
            for(int i = 1; i <= n; i++) {
                for(int j = i; j <= n; j++) {
                    ll Ans = 0;
                    for(int k = i; k <= j; k++)Ans |= a[k];
                    mp[Ans]++;
                }
            }
            for(auto i : mp)if(i.S > 1)ok = false;
            cout << (ok ? "YES" : "NO") << endl;

        }
    }


    return 0;
}
