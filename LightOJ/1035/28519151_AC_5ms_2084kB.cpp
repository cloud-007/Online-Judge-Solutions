/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int tc, n, casee = 1, mp[105];
vector < int > prime;

void init() {
    for(int i = 2; i <= 100; i++) {
        bool ok = true;
        for(int j = 2; j * j <= i; j++) {
            if(i % j == 0) {
                ok = false;
                break;
            }
        }
        if(ok)prime.push_back(i);
    }
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
   // cloud_007;
    init();
    cin >> tc;
    while(tc--) {
        cin >> n;
        ll res = 1;
        for(ll i = 1; i <= n; i++) {
            res *= i;
            for(auto j : prime) {
                while(res && res % j == 0) {
                    res /= j;
                    mp[j]++;
                }
            }
        }

        cout << "Case " << casee++ << ": " << n << " = ";
        int once = 0;
        for(int i = 2; i <= 97; i++) {
            if(mp[i]) {
                if(once)cout << " * ";
                cout << i << " (" << mp[i] << ")";
                     once = 1;
            }
        }
        cout<<endl;

        memset(mp, 0, sizeof mp);
    }

    return 0;
}


