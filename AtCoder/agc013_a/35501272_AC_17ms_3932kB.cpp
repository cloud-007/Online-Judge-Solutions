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
    for(int i = 1; i <= n; i++)cin >> a[i];

    int Ans = 0, pos = 1, i, j;

    while(pos <= n) {
        i = j = pos;
        while(i + 1 <= n && a[i] <= a[i + 1])++i;
        while(j + 1 <= n && a[j] >= a[j + 1])++j;
        pos = max(i, j) + 1; ++Ans;
    }


    cout << Ans << endl;


    return 0;
}
