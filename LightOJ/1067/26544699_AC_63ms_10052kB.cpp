#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long

const int sz = 1e6 + 50, mod = 1000003;
int  tc, n, k, casee = 1;
ll fact[sz], temp;

void init()
{
    fact[0] = fact[1] = 1;
    for(int i = 2; i < 1000001; i++)
    {
        fact[i] += (fact[i - 1] * i);
        fact[i] = fact[i] % mod;
    }
}

ll bigmod(ll a, ll b, ll m)
{
    if(b == 0)return 1;
    ll x = bigmod(a, b / 2, m) % m;
    x = (x % m * x % m) % m;
    if(b & 1)
        x = (a % m) * (x % m);
    return x;
}

int main()
{
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    init();
    cin >> tc;
    while(tc--)
    {
        cin >> n >> k;
        temp = (fact[k] % mod * fact[n - k] % mod) % mod;
        temp = bigmod(temp, mod-2, mod) % mod;
        temp = (fact[n] % mod * temp % mod) % mod;
        cout << "Case " << casee++ << ": " << temp << endl;
    }
    return 0;
}
