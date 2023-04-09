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
    int x[] = {100, 20, 10, 5, 1};
    cin >> n;
    int Ans = 0;

    for(int i = 0; i <= 4; i++) {
        if(x[i] <= n) {
            Ans += n / x[i];
            n -= (x[i] * (n / x[i]));
        }
    }

    cout << Ans << endl;


    return 0;
}
