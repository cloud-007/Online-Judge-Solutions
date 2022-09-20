/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 4e5 + 5;
ll tc, n, a[sz], _Gcd;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(i == 1)_Gcd = a[i];
        else _Gcd = gcd(_Gcd, a[i]);
    }
    int Ans = 0;
    for(ll i = 1; i * i <= _Gcd; i++) {
        if(_Gcd % i == 0) {
            i == _Gcd / i ? Ans++ : Ans += 2;
        }
    }
    cout << Ans << endl;


    return 0;
}
