/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, k, casee = 1;
string a, b;
map < char, int > now, need;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        cin >> n >> k >> a >> b;
        for(auto i : a)now[i]++;
        for(auto i : b)need[i]++;

        bool ok = true;

        for(char c = 'a'; c <= 'z'; c++) {
            if(now[c] == need[c])continue;
            if(now[c] < need[c]) {
                ok = false;
                break;
            }
            if((now[c] - need[c]) % k) {
                ok = false;
                break;
            }
            now[c + 1] += now[c] - need[c];
        }

        cout << (ok ? "YES" : "NO") << endl;

        now.clear(), need.clear();

    }


    return 0;
}
