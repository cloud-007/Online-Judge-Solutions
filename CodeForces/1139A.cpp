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
    string s;
    cin >> n >> s;
    ll Ans = 0, odd = 0, even = 0;
    for(int i = 0; i < n; i++) {
        if((s[i] - '0') % 2 == 0) {
            even++;
            Ans += i;
        }
    }

    Ans += even;

    cout << Ans << endl;


    return 0;
}
