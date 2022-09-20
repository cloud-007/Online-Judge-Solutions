/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

double a, b, c, i, j, k, mn = 505;

int main()
{
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> a >> b >> c >> i >> j >> k;
    mn = min(mn, a / i);
    mn = min(mn, b / j);
    mn = min(mn, c / k);
    i *= mn, j *= mn, k *= mn;
    printf("%.6f %.6f %.6f\n", a-i, b-j, c-k);
   // cout << a - i << " " << b - j << " " << c - k << endl;
}
