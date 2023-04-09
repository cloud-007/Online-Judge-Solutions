/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 105 + 5;
int tc, n, casee = 1, a[2][N], pref[N], suff[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 0; i < 2; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(i == 0)pref[j] = pref[j - 1] + a[i][j];
        }
    }

    for(int j = n; j >= 1; j--)suff[j] = suff[j + 1] + a[1][j];

    int Ans = 0;

    for(int i = 1; i <= n; i++) {
        Ans = max(Ans, pref[i] + suff[i]);
    }

    cout << Ans << endl;


    return 0;
}
