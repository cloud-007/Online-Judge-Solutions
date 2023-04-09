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
    cin >> n;
    int oddCount = 0;
    while(n--) {
        int x; cin >> x;
        oddCount += (x & 1);
    }

    cout << (oddCount & 1 ? "NO" : "YES") << endl;


    return 0;
}
