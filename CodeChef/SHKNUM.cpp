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
vector < int > v;

void pre() {
    ll i = 1;
    while(i <= INT_MAX) {
        v.push_back((int)i);
        i *= 2;
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    pre();
    cin >> tc;
    while(tc--) {
        cin >> n;
        ll Ans = 1e18;
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < v.size(); j++) {
                if(i == j)continue;
                ll curSum = v[i] + v[j];
                Ans = min(Ans, abs(n - curSum));
            }
        }
        cout << Ans << endl;
    }

    return 0;
}
