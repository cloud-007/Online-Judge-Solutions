#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define FastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int phi(int n)
{
    float res = n;

    for (int p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
            {
                n /= p;
            }
            res *= (1.0 - (1.0 / (float)p));
        }
    }
    if (n > 1)
        res *= (1.0 - (1.0 / (float)n));

    return (int)res;

}
int main()
{
    ll t,n;
    cin >> t;
    while(t--)
    {
        ll c = 0;
        cin >> n;
        cout << phi(n) << endl;
    }
}
