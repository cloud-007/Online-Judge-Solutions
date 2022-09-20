/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, m, n, casee = 1;
map <int, int> mp, mp1;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        cin >> n >> m;
        int Ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int x; cin >> x;
                mp1[x]++;
            }
            for(auto i : mp1)Ans += min(i.S, mp[i.F]);
            mp.clear();
            for(auto i : mp1)mp[i.F] = i.S;
            mp1.clear();
        }

        mp.clear(), mp1.clear();

        cout << Ans << endl;
    }


    return 0;
}
