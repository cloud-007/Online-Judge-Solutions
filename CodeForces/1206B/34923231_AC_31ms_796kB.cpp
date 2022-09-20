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
    sort(a + 1, a + n + 1);

    int flagId = -1;
    ll Ans = 0;

    for(int i = 1; i <= n; i++) {
        if(a[i] >= 0 && flagId == -1) {
            flagId = i;
        }
        if(a[i] == 0)Ans++;
        else Ans += abs(a[i]) - 1;
    }

    if(flagId == -1) {
        if(n & 1) {
            Ans += 2;
        }
        cout << Ans << endl;
    } else {
        if((flagId-1) & 1 && a[flagId]!=0) {
            Ans += 2;
        }
        cout << Ans << endl;
    }


    return 0;
}
