/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N], Ans[N];
bool done[N];

int mex = 0;

int next() {
    while(done[mex])++mex;
    return mex;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];

    memset(Ans, -1, sizeof Ans);

    for(int i = 1; i <= n; i++) {
        if(a[i] != a[i - 1]) {
            Ans[i] = a[i - 1];
            done[Ans[i]] = true;
        }
    }

    done[a[n]] = true;

    for(int i = 1; i <= n; i++) {
        if(Ans[i] == -1) {
            Ans[i] = next();
            done[Ans[i]] = true;
        }
        cout << Ans[i] << " ";
    }
    cout << endl;


    return 0;
}
