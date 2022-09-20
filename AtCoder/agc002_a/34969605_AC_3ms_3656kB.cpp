/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a, b;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> a >> b;
    if(a == 0 || b == 0) {
        cout << "Zero" << endl;
    } else if(a < 0 && b < 0) {
        if(((abs(b) - abs(a)) + 1) & 1)cout << "Negative" << endl;
        else cout << "Positive" << endl;
    } else if(a > 0 && b > 0) {
        cout << "Positive" << endl;
    } else {
        cout << "Zero" << endl;
    }


    return 0;
}
