/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e6 + 5;
int tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];

    int alive = 0, bound = INT_MAX;
    for(int i = n; i >= 1; i--) {
        if(bound > i) ++alive;
        bound = min(bound, i - a[i]);
    }

    cout << alive << endl;


    return 0;
}
