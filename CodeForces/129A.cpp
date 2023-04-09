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
    int even = 0, odd = 0;
    while(n--) {
        int x; cin >> x;
        if(x & 1)++odd;
        else ++even;
    }

    if(odd & 1)cout << odd << endl;
    else cout << even << endl;


    return 0;
}
