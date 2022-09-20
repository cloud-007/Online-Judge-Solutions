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
double x, y, d;

double check(double mid) {
    double h1 = sqrt((x*x) - (mid*mid));
    double h2 = sqrt((y*y) - (mid*mid));

    return (h1*h2) / (h1+h2);
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        cin >> x >> y >> d;
        double lo = 0.0, hi = min(x, y);
        int cnt = 100;
        while(cnt--) {
            double mid = (lo + hi) / 2.0;
            if(check(mid)<=d) {
                hi = mid;
            } else lo = mid;
        }
        cout <<"Case "<<casee++<<": ";
        cout <<fixed <<setprecision(8)<<lo<<endl;
    }

    return 0;
}

