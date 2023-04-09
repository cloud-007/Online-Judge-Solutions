/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
ll n, k, x, Xor, Ans, bit[55][2], a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> x; a[i] = x;
        for(ll i = 50; i >= 0; i--) {
            ll curBit = (1ll << i);
            if(x & curBit)bit[i][1]++;
            else bit[i][0]++;
        }
    }


    for(ll i = 50; i >= 0; i--) {
        ll curBit = (1ll << i);
        if(bit[i][0] > bit[i][1] && Ans + curBit <= k)Ans += curBit;
    }

    for(int i=1;i<=n;i++){
        Xor += a[i]^Ans;
    }

    cout << Xor << endl;


    return 0;
}
