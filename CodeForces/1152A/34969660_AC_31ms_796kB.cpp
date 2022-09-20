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

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    int m; cin >> n >> m;
    int evenN = 0, evenM = 0, oddM = 0, oddN = 0;
    while(n--) {
        int x; cin >> x;
        oddN += (x & 1);
        evenN += (x % 2 == 0);
    }
    while(m--) {
        int x; cin >> x;
        oddM += (x & 1);
        evenM += (x % 2 == 0);
    }

    cout << min(evenM, oddN) + min(evenN, oddM) << endl;


    return 0;
}
