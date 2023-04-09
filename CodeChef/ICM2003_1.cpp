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
double b, c;

double f(double x) {
    return (x * x + b * x + c) / sin(x);
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        cin >> b >> c;
        double l = 0, r = 3.1416 / 2.0;
        int cnt = 100;
        while(cnt--) {
            double mid1 = l + (r - l) / 3.0;
            double mid2 = r - (r - l) / 3.0;
            if(f(mid1) < f(mid2))r = mid2;
            else l = mid1;
        }
        cout << fixed << setprecision(10) << f(l) << endl;
    }


    return 0;
}
