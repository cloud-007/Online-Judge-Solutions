/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int tc;
double b, p;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        cin >> b >> p;
        double bpm = (60 * b) / p;
        double del = bpm / b;
        cout << fixed << setprecision(4) << bpm - del << " " << bpm << " " << bpm + del << endl;
    }
    return 0;
}
