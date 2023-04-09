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
double ab, ac, bc, Ratio;

double findRatio(double ad) {
    double ae = (ad * ac) / ab;
    double de = (ad * bc) / ab;
    double parOfAbc = (ab + ac + bc) / 2.0;
    double parOfAde = (ad + ae + de) / 2.0;

    double areaOfAbc = sqrt(parOfAbc * (parOfAbc - ab) * (parOfAbc - bc) * (parOfAbc - ac));
    double areaOfAde = sqrt(parOfAde * (parOfAde - ad) * (parOfAde - de) * (parOfAde - ae));
    double areaOfBDEC = areaOfAbc - areaOfAde;

    return areaOfAde / areaOfBDEC;
}


int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        cin >> ab >> ac >> bc >> Ratio;
        double lo = 0.0, high = ab, mid;
        for(int i = 0; i <= 100; i++) {
            mid = (lo + high) / 2;
            if(findRatio(mid) < Ratio) lo = mid;
            else high = mid;
        }
        cout << fixed << setprecision(7);
        cout << "Case " << casee++ << ": " << mid << endl;
    }

    return 0;
}
