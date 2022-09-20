/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 3e5 + 5;
int tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + n + 1);
    if(n & 1)cout << a[(n + 1) / 2] << endl;
    else {
        int one = a[n / 2], two = a[(n / 2) + 1];
        ll sum = 0, sum1 = 0;
        for(int i = 1; i <= n; i++) {
            sum += abs(a[i] - one);
            sum1 += abs(two - a[i]);
        }
        if(sum <= sum1)cout << one << endl;
        else cout << two << endl;
    }


    return 0;
}
