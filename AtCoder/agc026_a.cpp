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
    int cnt = 1, Ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == a[i - 1])++cnt;
        else Ans += cnt / 2, cnt = 1;
    }
    Ans += cnt / 2;

    cout << Ans << endl;


    return 0;
}
