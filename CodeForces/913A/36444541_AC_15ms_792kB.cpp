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
    int m;
    cin >> n >> m;
    ll Ans = 1;
    while(n--) {
        Ans *= 2;
        if(Ans > m) {
            cout << m << endl;
            exit(0);
        }
    }
    cout << m % Ans << endl;


    return 0;
}
