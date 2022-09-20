/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
ll a, b, c, n;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    ll Ans = (1ll << 60);

    for(int i = 0; i <= 60; i++) {
        ll a = n / (1ll << i);
        ll b = i;
        ll c = n - a * (1ll << i);
        Ans = min(Ans, a + b + c);
    }

    cout << Ans << endl;


    return 0;
}
