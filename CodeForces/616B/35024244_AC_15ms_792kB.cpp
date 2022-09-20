/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, m, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n >> m;
    int Ans = -1;
    while(n--) {
        for(int i = 1; i <= m; i++)cin >> a[i];
        Ans = max(Ans, *min_element(a + 1, a + m + 1));
    }
    cout << Ans << endl;


    return 0;
}
