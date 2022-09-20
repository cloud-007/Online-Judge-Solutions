/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 50 + 5;
int tc, n, casee = 1, a[N][N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    if(n == 1) {
        cout << 1 << endl;
        exit(0);
    }
    int startingIndex = (n + 1) / 2, cnt = 1, val = 1;
    for(int i = 1; i <= (n + 1) / 2; i++) {
        int total = cnt;
        for(int j = startingIndex; total > 0; j++) {
            a[i][j] = val; --total;
            val += 2;
        }
        startingIndex--, cnt += 2;
    }
    startingIndex += 2; cnt -= 4;
    for(int i = ((n + 1) / 2) + 1; i <= n; i++) {
        int total = cnt;
        for(int j = startingIndex; total > 0; j++) {
            a[i][j] = val;
            val += 2; --total;
        }
        startingIndex++, cnt -= 2;
    }

    val = 2;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i][j] == 0) {
                a[i][j] = val;
                val += 2;
            }
            cout << a[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
