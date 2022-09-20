/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 300 + 5;
int tc, n, casee = 1, a[N][N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        int m; cin >> n >> m;
        bool ok = true;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> a[i][j];
                if((i == 1 && j == 1) ||
                        (i == 1 && j == m) ||
                        (i == n && j == 1) ||
                        (i == n && j == m)) {
                    if(a[i][j] > 2)ok = false;
                    else {
                        a[i][j] = 2;
                    }
                } else if(i == 1 || j == 1 || i == n || j == m) {
                    if(a[i][j] > 3)ok = false;
                    else a[i][j] = 3;
                } else {
                    if(a[i][j] > 4)ok = false;
                    else a[i][j] = 4;
                }
            }
        }
        if(!ok)cout << "NO" << endl;
        else {
            cout << "YES" << Endl;
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
        }
    }


    return 0;
}
