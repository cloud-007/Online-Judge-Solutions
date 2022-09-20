/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
ll tc, n, casee = 1, spf[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {

        cin >> n;

        vector < ll > prFact;

        for(ll i = 2; i * i <= n; i++) {
            while(n % i == 0) {
                prFact.push_back(i);
                n /= i;
            }
        }
        if(n > 1)prFact.push_back(n);

        sort(prFact.begin(), prFact.end());

        vector < ll > Ans;
        Ans.push_back(1);
        map < ll, bool > vis;
        vis[1] = true;

        for(auto i : prFact) {
            for(int j = Ans.size() - 1; j >= 0; j--) {
                ll cur = i * Ans[j];
                if(vis[cur])continue;
                Ans.push_back(cur);
                vis[cur] = true;
            }
        }

        cout << "Case " << casee++ << ":" << endl;
        for(auto i : Ans)cout << i << " ";
        cout << endl;

    }


    return 0;
}
