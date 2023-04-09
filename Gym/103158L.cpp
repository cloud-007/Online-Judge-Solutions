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
    freopen("max-pair.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        string s; cin >> s;
        n = s.size();

        map < char, bool > mp;

        int Ans = 0;
        for(int i = 0; i < n; i++) {
            if(mp[s[i]])continue;
            mp[s[i]] = true;
            for(int j = n - 1; j > i; j--) {
                if(s[i] != s[j]) {
                    Ans = max(Ans, j - i);
                    break;
                }
            }
        }

        mp.clear();

        for(int i = n - 1; i >= 0; i--) {
            if(mp[s[i]])continue;
            mp[s[i]] = true;
            for(int j = 0; j < i ; j++) {
                if(s[i] != s[j]) {
                    Ans = max(Ans, i - j);
                    break;
                }
            }
        }

        cout << Ans << endl;

    }


    return 0;
}
