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
        cin >> n;
        if(n == 1)cout << 0 << endl;
        else if(n == 2)cout << 1 << endl;
        else if(n == 3)cout << 2 << endl;
        else if(n % 2 == 0)cout << 2 << endl;
        else cout << 3 << endl;
    }


    return 0;
}
