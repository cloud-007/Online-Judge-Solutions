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
    int k; cin >> n >> k;
    double sum = 0;
    int div = 1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(i <= k)sum += a[i];
    }
    double Ans = sum;
    int i = 1;
    while(k < n) {
        sum -= a[i++];
        sum += a[++k];
        Ans += sum; ++div;
    }

    cout << fixed << setprecision(6) << Ans / div << endl;


    return 0;
}
