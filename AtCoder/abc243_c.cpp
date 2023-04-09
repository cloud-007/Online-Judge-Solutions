/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, x[N], y[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> x[i] >> y[i];
    string s; cin >> s;
    s = "#" + s;
    map < pair < int, char >, set <int>>mp;

    bool collison = false;

    for(int i = 1; i <= n; i++) {

        if(s[i] == 'R') {
            auto it = mp[ {y[i], 'L'}].end();
            if(mp[ {y[i], 'L'}].size()) {
                --it;
                if(*it > x[i]) {
                    cout << "Yes" << endl;
                    exit(0);
                }
            }
        } else {
            if(mp[ {y[i], 'R'}].size() && *mp[ {y[i], 'R'}].begin() < x[i]) {
                cout << "Yes" << endl;
                exit(0);
            }
        }

        mp[ {y[i], s[i]}].insert(x[i]);
    }

    cout << "No" << endl;


    return 0;
}
