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
    cin >> tc;
    while(tc--) {
        int x; cin >> n >> x;
        int even = 0, odd = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] % 2 == 0 ? even++ : odd++;
        }
        if(odd % 2 == 0 && odd)--odd;
        if(x % 2 == 0 && even + odd >= x && even && odd)cout << "Yes" << endl;
        else if(x & 1 && even + odd >= x && odd)cout << "Yes" << endl;
        else cout << "No" << endl;
    }


    return 0;
}
